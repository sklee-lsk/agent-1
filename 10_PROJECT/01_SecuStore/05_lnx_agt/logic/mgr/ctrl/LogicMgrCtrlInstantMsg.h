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

#ifndef LogicMgrCtrlInstantMsgH
#define LogicMgrCtrlInstantMsgH
//---------------------------------------------------------------------------

class CLogicMgrCtrlInstantMsg	: public CLogicBase
{ 
private:
	INT32		AnalyzePkt_FromMgr_Ext();

	INT32		AnalyzePkt_FromMgr_Ext_Ctrl();

private:
	INT32		ApplyPolicy(PMEM_CTRL_INSTANT_MSG pInfo);

public:
	CLogicMgrCtrlInstantMsg();
    ~CLogicMgrCtrlInstantMsg();
};

extern CLogicMgrCtrlInstantMsg*		t_LogicMgrCtrlInstantMsg;

#endif
