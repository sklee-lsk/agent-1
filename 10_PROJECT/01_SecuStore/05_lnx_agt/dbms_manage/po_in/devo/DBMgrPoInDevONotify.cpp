/*
 * Copyright (C) 2021-2026 ASHINi Corp. 
 * 
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public 
 * License as published by the Free Software Foundation; either 
 * version 3 of the License, or any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public 
 * License along with this program. If not, see <https://www.gnu.org/licenses/>.   
 *  
 * 
 */


#include "stdafx.h"
#include "com_struct.h"
#include "DBMgrPoInDevONotify.h"

//---------------------------------------------------------------------------

CDBMgrPoInDevONotify*		t_DBMgrPoInDevONotify = NULL;

//---------------------------------------------------------------------------

CDBMgrPoInDevONotify::CDBMgrPoInDevONotify()
{
	m_strDBTName = "po_in_devo_notify";
}
//---------------------------------------------------------------------------

CDBMgrPoInDevONotify::~CDBMgrPoInDevONotify()
{
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevONotify::SetInitalize()
{
    {
    	
	}
	//WriteLogN("current file dbms : [po_in_devo_notify][%d]", m_nDBSVer);
    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevONotify::LoadDB(TListDBPoInDevONotify& tDBPoInDevONotifyList)
{
    UINT32 nReadCnt = 0;
    DB_PO_IN_DEVO_NOTIFY dpfn;

    INT32 nIndex = 0;

    m_strQuery = SPrintf(DBMS_POLICY_QUERY_HDR_SELECT
						", msg_type "
						" FROM po_in_devo_notify WHERE used_flag=1;");
    if(DBOP_Check(ExecuteQuery(m_strQuery)))
		return ERR_DBMS_SELECT_FAIL;

    do
    {
		nIndex = 0;
		DB_PO_HEADER& tDPH = dpfn.tDPH;

		tDPH					= GetDBField_PoHDR(nIndex);
		dpfn.nMsgType			= GetDBField_UInt(nIndex++);
		
        tDBPoInDevONotifyList.push_back(dpfn);
        if(m_nLoadMaxID < UINT32(tDPH.nID))	m_nLoadMaxID = tDPH.nID;
        nReadCnt++;
    }while(Next());
	m_nLoadNumber = tDBPoInDevONotifyList.size();
	WriteLogN("load database : [%s][%u]", m_strDBTName.c_str(), m_nLoadNumber);
    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevONotify::InsertPoInDevONotify(DB_PO_IN_DEVO_NOTIFY& dpfn)
{
	DB_PO_HEADER& tDPH = dpfn.tDPH;

	m_strQuery = SPrintf("INSERT INTO po_in_devo_notify("
						DBMS_POLICY_QUERY_HDR_INSERT_NAME
						", msg_type"
						") VALUES (%s"
						", %u);",
                        GetPoHDRQuery_InsertValue(tDPH).c_str(),
						dpfn.nMsgType);

	if(DBOP_Check(ExecuteQuery(m_strQuery)))		return ERR_DBMS_INSERT_FAIL;

	if(tDPH.nID == 0)
		tDPH.nID      = GetLastID();

    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevONotify::UpdatePoInDevONotify(DB_PO_IN_DEVO_NOTIFY& dpfn)
{
	DB_PO_HEADER& tDPH = dpfn.tDPH;

	m_strQuery = SPrintf("UPDATE po_in_devo_notify SET %s"
						", msg_type=%u"
						" WHERE id=%u;",
						GetPoHDRQuery_Update(tDPH).c_str(),
						dpfn.nMsgType,
						tDPH.nID);

	if(DBOP_Check(ExecuteQuery(m_strQuery)))		return ERR_DBMS_UPDATE_FAIL;

    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------  
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevONotify::LoadExecute(PVOID lpTempletList)
{
	TListDBPoInDevONotify* ptDBList = (TListDBPoInDevONotify*)lpTempletList;

    return LoadDB(*ptDBList);
}
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevONotify::InsertExecute(PVOID lpTemplet)
{
	PDB_PO_IN_DEVO_NOTIFY pd_t = (PDB_PO_IN_DEVO_NOTIFY)lpTemplet;

    return InsertPoInDevONotify(*pd_t);
}
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevONotify::UpdateExecute(PVOID lpTemplet)
{
	PDB_PO_IN_DEVO_NOTIFY pd_t = (PDB_PO_IN_DEVO_NOTIFY)lpTemplet;

    return UpdatePoInDevONotify(*pd_t);
}
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevONotify::DeleteExecute(UINT32 nID)
{
	return CDBMgrBase::DeleteExecute(nID);
}
//---------------------------------------------------------------------------






