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

#ifndef DB_PO_NC_PTN_BL_H_4D39CDDB_PO_E289_4d56_9F98_FE42776F4467
#define DB_PO_NC_PTN_BL_H_4D39CDDB_PO_E289_4d56_9F98_FE42776F4467

typedef struct _db_po_nc_ptn_bl
{
	_db_po_nc_ptn_bl()
	{		
	}

	DB_PO_HEADER		tDPH;
	DB_PTN_FILE_INFO	tDPFI;
}DB_PO_NC_PTN_BL, *PDB_PO_NC_PTN_BL;

typedef list<DB_PO_NC_PTN_BL>				TListDBPoNcPtnBL;
typedef TListDBPoNcPtnBL::iterator			TListDBPoNcPtnBLItor;

typedef map<UINT32, DB_PO_NC_PTN_BL>		TMapDBPoNcPtnBL;
typedef TMapDBPoNcPtnBL::iterator			TMapDBPoNcPtnBLItor;
//---------------------------------------------------------------------------

typedef struct _db_po_nc_ptn_bl_pkg
{
	_db_po_nc_ptn_bl_pkg()
	{
	}

	DB_PO_HEADER		tDPH;

}DB_PO_NC_PTN_BL_PKG, *PDB_PO_NC_PTN_BL_PKG;

typedef list<DB_PO_NC_PTN_BL_PKG>			TListDBPoNcPtnBLPkg;
typedef TListDBPoNcPtnBLPkg::iterator		TListDBPoNcPtnBLPkgItor;

typedef map<UINT32, DB_PO_NC_PTN_BL_PKG>	TMapDBPoNcPtnBLPkg;
typedef TMapDBPoNcPtnBLPkg::iterator		TMapDBPoNcPtnBLPkgItor;
//---------------------------------------------------------------------------

typedef struct _db_po_nc_ptn_bl_unit
{
	_db_po_nc_ptn_bl_unit()
	{
		nRTMode		= 0;
	}

	DB_PO_HEADER		tDPH;

	UINT32				nRTMode;
	UINT32				nFltChkType;
	DB_FILE_INFO		tDFI;

}DB_PO_NC_PTN_BL_UNIT, *PDB_PO_NC_PTN_BL_UNIT;

typedef list<DB_PO_NC_PTN_BL_UNIT>			TListDBPoNcPtnBLUnit;
typedef TListDBPoNcPtnBLUnit::iterator		TListDBPoNcPtnBLUnitItor;

typedef map<UINT32, DB_PO_NC_PTN_BL_UNIT>	TMapDBPoNcPtnBLUnit;
typedef TMapDBPoNcPtnBLUnit::iterator		TMapDBPoNcPtnBLUnitItor;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


#endif //DB_PO_NC_PTN_BL_H_4D39CDDB_PO_E289_4d56_9F98_FE42776F4467



