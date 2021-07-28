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
 */
#ifndef COM_DEFINE_DB_PTN_VULN_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_PTN_VULN_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//-------------------------------------------------------------------
//RISK
#define SS_PTN_VULN_SUPPORT_OPTION_NON_CHECK_SUCCESS	0x00000001
#define SS_PTN_VULN_SUPPORT_OPTION_LOCK_SAFE_VALUE		0x00000002
#define SS_PTN_VULN_SUPPORT_OPTION_AUTO_REPAIR			0x00000004
#define SS_PTN_VULN_SUPPORT_OPTION_USE_PRESCAN_RESULT	0x00000008

#define SS_PTN_VULN_CLASS_TYPE_ALL						0x0000003F
#define SS_PTN_VULN_CLASS_TYPE_SECURITY_UPDATE			0x00000001
#define SS_PTN_VULN_CLASS_TYPE_PASSWORD_CHECK			0x00000002
#define SS_PTN_VULN_CLASS_TYPE_SCREEN_SAVER				0x00000004
#define SS_PTN_VULN_CLASS_TYPE_SHARE_FOLDER				0x00000008
#define SS_PTN_VULN_CLASS_TYPE_SECURITY_PROG			0x00000010
#define SS_PTN_VULN_CLASS_TYPE_EXTENSION_SCAN			0x00000020

//--------------------------------------------------------------------


#define SS_PTN_VULN_TYPE_NONE							0x00000000
#define SS_PTN_VULN_TYPE_FILE							0x00000001
#define SS_PTN_VULN_TYPE_REGISTRY						0x00000002
#define SS_PTN_VULN_TYPE_WMI							0x00000004
#define SS_PTN_VULN_TYPE_PROCESS						0x00000008
#define SS_PTN_VULN_TYPE_CUSTOM							0x00000010
//-------------------------------------------------------------------

#define SS_PTN_VULN_SCAN_RESULT_NONE					0x00000000
#define SS_PTN_VULN_SCAN_RESULT_SAFE					0x00000001
#define SS_PTN_VULN_SCAN_RESULT_DANGER					0x00000010
#define SS_PTN_VULN_SCAN_RESULT_CHK_FAIL				0x00000100
#define SS_PTN_VULN_SCAN_RESULT_SCANNING				0x00001000
#define SS_PTN_VULN_SCAN_RESULT_READY					0x00002000
#define SS_PTN_VULN_SCAN_RESULT_NOT_SUPPORT				0x00010000
#define SS_PTN_VULN_SCAN_RESULT_REPAIR_SUCCESS			0x00100000
#define SS_PTN_VULN_SCAN_RESULT_REPAIR_FAIL				0x01000000
#define SS_PTN_VULN_SCAN_RESULT_UNKNOWN					0xFFFFFFFF

typedef enum
{
	SS_PTN_VULN_CUSTOM_ID_NONE					= 0,
	SS_PTN_VULN_CUSTOM_ID_VC_PROCESS,
	SS_PTN_VULN_CUSTOM_ID_VC_PATCH,
	SS_PTN_VULN_CUSTOM_ID_WIN_UPDATE,
	SS_PTN_VULN_CUSTOM_ID_HWP_UPDATE,
	SS_PTN_VULN_CUSTOM_ID_WIN_PW_SAFE,
	SS_PTN_VULN_CUSTOM_ID_WIN_PW_CHANGE,
	SS_PTN_VULN_CUSTOM_ID_WIN_SCREEN_SAFE,
	SS_PTN_VULN_CUSTOM_ID_WIN_SHARE_FOLDER,
	SS_PTN_VULN_CUSTOM_ID_WIN_USB_RUN,
	SS_PTN_VULN_CUSTOM_ID_WIN_ACTIVEX,
	SS_PTN_VULN_CUSTOM_ID_EDIT_PROGRAM,
	SS_PTN_VULN_CUSTOM_ID_PDF_UPDATE,
	SS_PTN_VULN_CUSTOM_ID_SECU_USB_PROGRAM,
	SS_PTN_VULN_CUSTOM_ID_WIRELESS_CARD,
	SS_PTN_VULN_CUSTOM_ID_NONCONFIRM_PROGRAM,
	SS_PTN_VULN_CUSTOM_ID_USER_PROCESS_LIST,
	SS_PTN_VULN_CUSTOM_ID_EOS_SYSTEM,
	SS_PTN_VULN_CUSTOM_ID_WIN_PW_USED,

	SS_PTN_VULN_CUSTOM_ID_ACTIVE_FIREWALL = 100,
	SS_PTN_VULN_CUSTOM_ID_SECURITY_CENTER_ALERT,

}SS_PTN_VULN_CUSTOM_ID;
//--------------------------------------------------------------------
#endif	//COM_DEFINE_DB_PTN_VULN_H_938EF200_F60B_452A_BD30_A10E8507EDCC