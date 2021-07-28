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

//---------------------------------------------------------------------------


#include "stdafx.h"
#include "com_struct.h"
#include "ManagePoNcPtnSPUnit.h"

//---------------------------------------------------------------------------

CManagePoNcPtnSPUnit*	t_ManagePoNcPtnSPUnit = NULL;

//---------------------------------------------------------------------------

CManagePoNcPtnSPUnit::CManagePoNcPtnSPUnit()
{
	t_DBMgrPoNcPtnSPUnit	= new CDBMgrPoNcPtnSPUnit();
}
//---------------------------------------------------------------------------

CManagePoNcPtnSPUnit::~CManagePoNcPtnSPUnit()
{
	if(t_DBMgrPoNcPtnSPUnit)	{	delete t_DBMgrPoNcPtnSPUnit;	t_DBMgrPoNcPtnSPUnit = NULL;	}
}
//---------------------------------------------------------------------------

INT32		CManagePoNcPtnSPUnit::LoadDBMS()
{
	TListDBPoNcPtnSPUnit tDBPoNcPtnSPUnitList;
    TListDBPoNcPtnSPUnitItor begin, end;
	if(SetER(t_DBMgrPoNcPtnSPUnit->LoadExecute(&tDBPoNcPtnSPUnitList)))
    {
    	return g_nErrRtn;
    }

    begin = tDBPoNcPtnSPUnitList.begin();	end = tDBPoNcPtnSPUnitList.end();
    for(begin; begin != end; begin++)
    {
    	AddItem(begin->tDPH.nID, *begin);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::GetHash(UINT32 nID, String& strOrgValue)
{
	PDB_PO_NC_PTN_SP_UNIT pdata 			= NULL;
	{
		if( (pdata = FindItem(nID)) == NULL)
		{
			WriteLogE("not find po_nc_ptn_sp_unit by hash : [%d]", ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			return ERR_INFO_NOT_OP_BECAUSE_NOT_FIND;
		}
	}

	{
		strOrgValue = SPrintf("%s,"
							"%u,%u,%u,"
							"%s,%s,"
							"%s,%s,"
							"%s,"
							"%s,%s,"
							"%s,%s,",							
							GetHdrHashInfo(pdata).c_str(),			
							pdata->nBlockMode, MAKETYPEID32(pdata->nConfirmLevel, pdata->nConfirmDay), pdata->nFltChkType,
							pdata->tDFI.strName.c_str(), pdata->tDFI.strPath.c_str(), 
							pdata->tDFI.strPublisher.c_str(), pdata->tDFI.strDescription.c_str(), 
							pdata->tDFI.strHash.c_str(),
							pdata->tDFI.strSignPubName.c_str(), pdata->tDFI.strSignPubSN.c_str(),
							pdata->tDFI.strSignCntName.c_str(), pdata->tDFI.strSignCntSN.c_str());
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::AddPoNcPtnSPUnit(DB_PO_NC_PTN_SP_UNIT&	data)
{
	if(SetER(t_DBMgrPoNcPtnSPUnit->InsertExecute(&data)))
    {
    	return g_nErrRtn;
    }

    AddItem(data.tDPH.nID, data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::EditPoNcPtnSPUnit(DB_PO_NC_PTN_SP_UNIT&	data)
{
	PDB_PO_NC_PTN_SP_UNIT pdata = FindItem(data.tDPH.nID);
	if(!pdata)	return ERR_DBMS_UPDATE_FAIL;

	if(SetER(t_DBMgrPoNcPtnSPUnit->UpdateExecute(&data)))
    {
    	return g_nErrRtn;
    }

    EditItem(data.tDPH.nID, data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::DelPoNcPtnSPUnit(UINT32 nID)
{
	PDB_PO_NC_PTN_SP_UNIT pdata = FindItem(nID);
	if(!pdata)	return ERR_DBMS_DELETE_FAIL;

	if(SetER(t_DBMgrPoNcPtnSPUnit->DeleteExecute(pdata->tDPH.nID)))
    {
    	return g_nErrRtn;
    }

    DeleteItem(nID);
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::ApplyPoNcPtnSPUnit(DB_PO_NC_PTN_SP_UNIT&	data)
{
	if(FindItem(data.tDPH.nID))
	{
		return EditPoNcPtnSPUnit(data);
	}
	return AddPoNcPtnSPUnit(data);
}
//---------------------------------------------------------------------------

String					CManagePoNcPtnSPUnit::GetName(UINT32 nID)
{
	PDB_PO_NC_PTN_SP_UNIT pdata = FindItem(nID);
    if(!pdata)	return "";
    return pdata->tDPH.strName;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::SetPkt(MemToken& SendToken)
{
    SendToken.TokenAdd_32(m_tMap.size());

	TMapDBPoNcPtnSPUnitItor begin, end;
    begin = m_tMap.begin();	end = m_tMap.end();
    for(begin; begin != end; begin++)
    {
    	SetPkt(&(begin->second), SendToken);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::SetPkt(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_NC_PTN_SP_UNIT pdata = FindItem(nID);
	if(!pdata)	return -1;

	return SetPkt(pdata, SendToken);
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::SetPkt(PDB_PO_NC_PTN_SP_UNIT pdata, MemToken& SendToken)
{
	SendToken.TokenAdd_DPH(pdata->tDPH);

	SendToken.TokenAdd_32(pdata->nBlockMode);
	SendToken.TokenAdd_32(pdata->nConfirmLevel);	
	SendToken.TokenAdd_32(pdata->nConfirmDay);
	SendToken.TokenAdd_32(pdata->nFltChkType);

	SendToken.TokenAdd_String(pdata->tDFI.strName);
	SendToken.TokenAdd_String(pdata->tDFI.strPath);
	SendToken.TokenAdd_String(pdata->tDFI.strPublisher);
	SendToken.TokenAdd_String(pdata->tDFI.strDescription);
	SendToken.TokenAdd_String(pdata->tDFI.strHash);
	SendToken.TokenAdd_String(pdata->tDFI.strSignPubName);
	SendToken.TokenAdd_String(pdata->tDFI.strSignPubSN);
	SendToken.TokenAdd_String(pdata->tDFI.strSignCntName);	
	SendToken.TokenAdd_String(pdata->tDFI.strSignCntSN);

	SendToken.TokenSet_Block();
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSPUnit::GetPkt(MemToken& RecvToken, DB_PO_NC_PTN_SP_UNIT& data)
{
	if (!RecvToken.TokenDel_DPH(data.tDPH))							goto	INVALID_PKT;

	if (!RecvToken.TokenDel_32(data.nBlockMode))					goto	INVALID_PKT;
	if(!RecvToken.TokenDel_32(data.nConfirmLevel))					goto	INVALID_PKT;
	if(!RecvToken.TokenDel_32(data.nConfirmDay))					goto	INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nFltChkType))					goto	INVALID_PKT;

	if ( RecvToken.TokenDel_String(data.tDFI.strName) < 0)			goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strPath) < 0)			goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strPublisher) < 0)		goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strDescription) < 0)	goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strHash) < 0)			goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strSignPubName) < 0)	goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strSignPubSN) < 0)		goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strSignCntName) < 0)	goto	INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.tDFI.strSignCntSN) < 0)		goto	INVALID_PKT;

	RecvToken.TokenSkip_Block();
	return 0;
INVALID_PKT:
	return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



