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
#include "ManagePoNcPtnSP.h"

//---------------------------------------------------------------------------

CManagePoNcPtnSP*	t_ManagePoNcPtnSP = NULL;

//---------------------------------------------------------------------------

CManagePoNcPtnSP::CManagePoNcPtnSP()
{
	t_DBMgrPoNcPtnSP	= new CDBMgrPoNcPtnSP();
}
//---------------------------------------------------------------------------

CManagePoNcPtnSP::~CManagePoNcPtnSP()
{
	if(t_DBMgrPoNcPtnSP)	{	delete t_DBMgrPoNcPtnSP;	t_DBMgrPoNcPtnSP = NULL;	}
}
//---------------------------------------------------------------------------

INT32		CManagePoNcPtnSP::LoadDBMS()
{
	TListDBPoNcPtnSP tDBPoNcPtnSPList;
    TListDBPoNcPtnSPItor begin, end;
	if(SetER(t_DBMgrPoNcPtnSP->LoadExecute(&tDBPoNcPtnSPList)))
    {
    	return g_nErrRtn;
    }

    begin = tDBPoNcPtnSPList.begin();	end = tDBPoNcPtnSPList.end();
    for(begin; begin != end; begin++)
    {
    	AddItem(begin->tDPH.nID, *begin);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::InitHash()
{
	t_ManagePoNcPtnSPPkg->InitPkg();
	
	TListID tIDList;
	TListIDItor begin, end;

	GetItemIDList(tIDList);
	begin = tIDList.begin();		end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		InitHash(*begin);
	}	
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::InitHash(UINT32 nID)
{
	String strOrgValue;

	PDB_PO_NC_PTN_SP pdata 			= NULL;
	{
		if( (pdata = FindItem(nID)) == NULL)
		{
			WriteLogE("not find po_nc_ptn_sp by hash : [%d]", ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			return ERR_INFO_NOT_OP_BECAUSE_NOT_FIND;
		}
	}

	{
		strOrgValue = SPrintf("%s,"
							"%u,%u,", 
							GetHdrHashInfo(pdata).c_str(),
							pdata->nConfirmLevel, pdata->nConfirmDay);

		{
			TMapIDItor begin, end;
			begin = pdata->tDPH.tSubIDMap.begin();	end = pdata->tDPH.tSubIDMap.end();
			for(begin; begin != end; begin++)
			{
				String strPkgValue;
				t_ManagePoNcPtnSPPkg->GetHash(begin->first, strPkgValue);
				strOrgValue += strPkgValue;
			}
		}
	}

	{
		char pszHashValue[CHAR_MAX_SIZE] = {0, };
		SHAString(ASIHASH_SHA_LEN_TYPE_128, strOrgValue.c_str(), strOrgValue.length(), pszHashValue, CHAR_MAX_SIZE);
		pdata->tDPH.strHash = pszHashValue;
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::AddPoNcPtnSP(DB_PO_NC_PTN_SP&	data)
{
	if(SetER(t_DBMgrPoNcPtnSP->InsertExecute(&data)))
    {
    	return g_nErrRtn;
    }

    AddItem(data.tDPH.nID, data);
	InitHash(data.tDPH.nID);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::EditPoNcPtnSP(DB_PO_NC_PTN_SP&	data)
{
	PDB_PO_NC_PTN_SP pdata = FindItem(data.tDPH.nID);
	if(!pdata)	return ERR_DBMS_UPDATE_FAIL;

	if(SetER(t_DBMgrPoNcPtnSP->UpdateExecute(&data)))
    {
    	return g_nErrRtn;
    }

    EditItem(data.tDPH.nID, data);
	InitHash(data.tDPH.nID);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::DelPoNcPtnSP(UINT32 nID)
{
	PDB_PO_NC_PTN_SP pdata = FindItem(nID);
	if(!pdata)	return ERR_DBMS_DELETE_FAIL;

	if(SetER(t_DBMgrPoNcPtnSP->DeleteExecute(pdata->tDPH.nID)))
    {
    	return g_nErrRtn;
    }

    DeleteItem(nID);
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::ApplyPoNcPtnSP(DB_PO_NC_PTN_SP&	data)
{
	if(FindItem(data.tDPH.nID))
	{
		return EditPoNcPtnSP(data);
	}
	return AddPoNcPtnSP(data);
}
//---------------------------------------------------------------------------

String					CManagePoNcPtnSP::GetName(UINT32 nID)
{
	PDB_PO_NC_PTN_SP pdata = FindItem(nID);
    if(!pdata)	return "";
    return pdata->tDPH.strName;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::SetPkt(MemToken& SendToken)
{
    SendToken.TokenAdd_32(m_tMap.size());

	TMapDBPoNcPtnSPItor begin, end;
    begin = m_tMap.begin();	end = m_tMap.end();
    for(begin; begin != end; begin++)
    {
    	SetPkt(&(begin->second), SendToken);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::SetPkt(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_NC_PTN_SP pdata = FindItem(nID);
	if(!pdata)	return -1;

	SetPkt(pdata, SendToken);
	
	{
		SendToken.TokenAdd_32(pdata->tDPH.tSubIDMap.size());

		TMapIDItor begin, end;
		begin = pdata->tDPH.tSubIDMap.begin();	end = pdata->tDPH.tSubIDMap.end();
		for(begin; begin != end; begin++)
		{
			t_ManagePoNcPtnSPPkg->SetPkt(begin->first, SendToken);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::SetPktHost(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_NC_PTN_SP pdata = FindItem(nID);
	if(!pdata)	return -1;

	SetPkt(pdata, SendToken);

	{
		SendToken.TokenAdd_32(pdata->tDPH.tSubIDMap.size());

		TMapIDItor begin, end;
		begin = pdata->tDPH.tSubIDMap.begin();	end = pdata->tDPH.tSubIDMap.end();
		for(begin; begin != end; begin++)
		{
			t_ManagePoNcPtnSPPkg->SetPktHost(begin->first, SendToken);
		}
	}

	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::SetPkt(PDB_PO_NC_PTN_SP pdata, MemToken& SendToken)
{
	SendToken.TokenAdd_DPH(pdata->tDPH);

	SendToken.TokenAdd_32(pdata->nConfirmLevel);	
	SendToken.TokenAdd_32(pdata->nConfirmDay);

	SendToken.TokenSet_Block();
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoNcPtnSP::GetPkt(MemToken& RecvToken, DB_PO_NC_PTN_SP& data)
{
	if(!RecvToken.TokenDel_DPH(data.tDPH))				goto INVALID_PKT;

	if(!RecvToken.TokenDel_32(data.nConfirmLevel))		goto INVALID_PKT;
	if(!RecvToken.TokenDel_32(data.nConfirmDay))		goto INVALID_PKT;

	RecvToken.TokenSkip_Block();
	return 0;
INVALID_PKT:
	return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



