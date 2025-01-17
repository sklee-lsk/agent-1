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


#ifndef COM_DEFINE_STATUS_EVENT_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_STATUS_EVENT_H_938EF200_F60B_452A_BD30_A10E8507EDCC



//-------------------------------------------------------------------
enum ENUM_SS_GLOBAL_LOG_REC_MODE_INDEX
{
	SS_GLOBAL_LOG_REC_MODE_INDEX_ALLOW = 0,
	SS_GLOBAL_LOG_REC_MODE_INDEX_DENY,
	SS_GLOBAL_LOG_REC_MODE_INDEX_TOTAL_NUMBER
};
//--------------------------------------------------------------------
//event notify type
#define EVENT_NOTIFY_TYPE_ALL									0
#define EVENT_NOTIFY_TYPE_ADMIN									1
#define EVENT_NOTIFY_TYPE_GROUP									2
#define EVENT_NOTIFY_TYPE_HOST									3
#define EVENT_NOTIFY_TYPE_USER									4
#define EVENT_NOTIFY_TYPE_USER_GROUP							5

//--------------------------------------------------------------------
//event subject type
#define EVENT_SUBJECT_TYPE_ADMIN								0x00000001
#define EVENT_SUBJECT_TYPE_GROUP								0x00000002
#define EVENT_SUBJECT_TYPE_HOST									0x00000003
#define EVENT_SUBJECT_TYPE_SVR									0x00000004
#define EVENT_SUBJECT_TYPE_USER									0x00000005
#define EVENT_SUBJECT_TYPE_SUB_SVR								0x00000006
#define EVENT_SUBJECT_TYPE_ASHIN								0x00000010

//--------------------------------------------------------------------
//Event log target
#define	EVENT_TARGET_TYPE_ADMIN									1
#define EVENT_TARGET_TYPE_GROUP									2
#define EVENT_TARGET_TYPE_HOST									3
#define EVENT_TARGET_TYPE_SVR									4
#define EVENT_TARGET_TYPE_USER									5
#define EVENT_TARGET_TYPE_USER_GROUP							6
#define EVENT_TARGET_TYPE_SUB_SVR								7
#define EVENT_TARGET_TYPE_LOGICAL_GROUP							8
#define EVENT_TARGET_TYPE_LOGICAL_HOST							9

//--------------------------------------------------------------------
//event operation type
#define EVENT_OPERATION_TYPE_ADD								0x00000001
#define EVENT_OPERATION_TYPE_EDIT								0x00000002
#define EVENT_OPERATION_TYPE_DEL								0x00000003
#define EVENT_OPERATION_TYPE_APPLY								0x00000004
#define EVENT_OPERATION_TYPE_RELEASE							0x00000005
#define EVENT_OPERATION_TYPE_COPY								0x00000006
#define EVENT_OPERATION_TYPE_CONNECT							0x00000100
#define EVENT_OPERATION_TYPE_DISCONNECT							0x00000101
#define EVENT_OPERATION_TYPE_LOCK								0x00000102
#define EVENT_OPERATION_TYPE_MOVE								0x00000103
#define EVENT_OPERATION_TYPE_ROLLBACK							0x00000104
#define EVENT_OPERATION_TYPE_CONTROL							0x00000105
#define EVENT_OPERATION_TYPE_SYNC								0x00000106
#define EVENT_OPERATION_TYPE_MAKE								0x00000107
#define EVENT_OPERATION_TYPE_UNINSTALL							0x00000108
#define EVENT_OPERATION_TYPE_REMOVE								0x00000109
#define EVENT_OPERATION_TYPE_INFO								0x00000110
#define EVENT_OPERATION_TYPE_SCAN								0x00000200
#define EVENT_OPERATION_TYPE_START								0x00000300
#define EVENT_OPERATION_TYPE_STOP								0x00000301
#define EVENT_OPERATION_TYPE_RESTART							0x00000302
#define EVENT_OPERATION_TYPE_COMPLETE							0x00000303
#define EVENT_OPERATION_TYPE_END								0x00000304
#define EVENT_OPERATION_TYPE_REGIST								0x00000305
#define EVENT_OPERATION_TYPE_SCHEDULE							0x00000400
#define EVENT_OPERATION_TYPE_CHANGE								0x00000401
#define EVENT_OPERATION_TYPE_LOGBACKUP							0x00000402
#define EVENT_OPERATION_TYPE_LOGIN								0x00000500
#define EVENT_OPERATION_TYPE_LOGOFF								0x00000501
#define EVENT_OPERATION_TYPE_EDITPW								0x00000502

//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//event object type
#define EVENT_OBJECT_TYPE_ADMIN									0x00000001
#define EVENT_OBJECT_TYPE_GROUP									0x00000002
#define EVENT_OBJECT_TYPE_HOST									0x00000003
#define EVENT_OBJECT_TYPE_USER									0x00000004
#define EVENT_OBJECT_TYPE_USER_GROUP							0x00000005
#define EVENT_OBJECT_TYPE_POLICY								0x00000010
#define EVENT_OBJECT_TYPE_POLICY_UNIT							0x00000011
#define EVENT_OBJECT_TYPE_PENV									0x00000012
#define EVENT_OBJECT_TYPE_ENV									0x00000020
#define EVENT_OBJECT_TYPE_SVR									0x00000021
#define EVENT_OBJECT_TYPE_COMMON								0x00000022
#define EVENT_OBJECT_TYPE_SUB_SVR								0x00000023
#define EVENT_OBJECT_TYPE_LOGICAL								0x00000024
#define EVENT_OBJECT_TYPE_DEPLOY								0x00000025
#define EVENT_OBJECT_TYPE_INFO									0x00000030

//--------------------------------------------------------------------
//event object code

//EVENT_OBJECT_TYPE_ADMIN
#define EVENT_OBJECT_CODE_ADMIN_ENV								0x00000001
#define EVENT_OBJECT_CODE_ADMIN_ENV_DT							0x00000002
#define EVENT_OBJECT_CODE_ADMIN_ENV_MN							0x00000003
#define EVENT_OBJECT_CODE_ADMIN_ENV_DT_UNIT						0x00000004
#define EVENT_OBJECT_CODE_ADMIN_ENV_MN_PAGE						0x00000005

//EVENT_OBJECT_TYPE_GROUP
#define EVENT_OBJECT_CODE_GROUP_NAME							0x00000001
#define EVENT_OBJECT_CODE_GROUP_ADMIN							0x00000002
#define EVENT_OBJECT_CODE_GROUP_MOVE							0x00000003

//EVENT_OBJECT_TYPE_HOST
#define EVENT_OBJECT_CODE_HOST_NAME								0x00000001
#define EVENT_OBJECT_CODE_HOST_MOVE								0x00000003
#define EVENT_OBJECT_CODE_HOST_CHG_USED_FLAG					0x00000004
#define EVENT_OBJECT_CODE_HOST_CHG_STATUS_PO					0x00000005
#define EVENT_OBJECT_CODE_HOST_BK_KEY							0x00000006
#define EVENT_OBJECT_CODE_HOST_CTRL_REMOTE_REQUEST				0x00000011
#define EVENT_OBJECT_CODE_HOST_CTRL_REMOTE_POWER				0x00000012
#define EVENT_OBJECT_CODE_HOST_CTRL_INSTANT_MSG					0x00000013
#define EVENT_OBJECT_CODE_HOST_CTRL_RESTORE						0x00000014
#define EVENT_OBJECT_CODE_HOST_CTRL_REMOTE_ORDER				0x00000015
#define EVENT_OBJECT_CODE_HOST_SW								0x00000016
#define EVENT_OBJECT_CODE_HOST_PATCH							0x00000017
#define EVENT_OBJECT_CODE_HOST_VULN_RST							0x00000018

#define EVENT_OBJECT_CODE_HOST_DOC_ROLLBACK						0x00000019
#define EVENT_OBJECT_CODE_HOST_DOC_ROLLBACK_EACH_HOST			0x00000020


//EVENT_OBJECT_TYPE_GROUP
#define EVENT_OBJECT_CODE_USER_GROUP_NAME						0x00000001
#define EVENT_OBJECT_CODE_USER_GROUP_ADMIN						0x00000002
#define EVENT_OBJECT_CODE_USER_GROUP_MOVE						0x00000003
#define EVENT_OBJECT_CODE_USER_PC								0x00000004
#define EVENT_OBJECT_CODE_USER_GROUP_SET_LOGOFF					0x00000005


//EVENT_OBJECT_TYPE_USER
#define EVENT_OBJECT_CODE_USER_SET_LOGOFF						0x00000001


#define EVENT_OBJECT_CODE_LOGICAL_GROUP							0x00000001
#define EVENT_OBJECT_CODE_LOGICAL_HOST							0x00000002

#define EVENT_OBJECT_CODE_DEPLOY_PATCH							0x00000001


//EVENT_OBJECT_TYPE_ENV
#define EVENT_OBJECT_CODE_ENV_SVR_INFO							0x00000003
#define EVENT_OBJECT_CODE_ENV_HOST_LICENSE						0x00000004
#define EVENT_OBJECT_CODE_ENV_SOCKET							0x00000005
#define EVENT_OBJECT_CODE_ENV_WEB_SVR							0x00000006
#define EVENT_OBJECT_CODE_ENV_NOTIFY_INFO						0x00000007
#define EVENT_OBJECT_CODE_ENV_LOG								0x00000008
#define EVENT_OBJECT_CODE_ENV_LOG_UNIT							0x00000009
#define EVENT_OBJECT_CODE_ENV_LICENSE							0x0000000A
#define EVENT_OBJECT_CODE_ENV_POLICY							0x0000000B
#define EVENT_OBJECT_CODE_ENV_RES_USAGE							0x0000000C
#define EVENT_OBJECT_CODE_ENV_SELF_PROTECT_AGT					0x0000000D
#define EVENT_OBJECT_CODE_ENV_SELF_PROTECT_SVR					0x0000000E
#define EVENT_OBJECT_CODE_ENV_TRUST_SUBJECT						0x0000000F
#define EVENT_OBJECT_CODE_ENV_SORG_LINK							0x00000011
#define EVENT_OBJECT_CODE_ENV_SORG_LINK_DB						0x00000012
#define EVENT_OBJECT_CODE_ENV_SUB_SVR_LGN						0x00000013
#define EVENT_OBJECT_CODE_ENV_SUB_SVR_MGR						0x00000014
#define EVENT_OBJECT_CODE_ENV_SUB_SVR_UDT						0x00000015
#define EVENT_OBJECT_CODE_ENV_SUB_SVR_RPT						0x00000016
#define EVENT_OBJECT_CODE_ENV_SVR_SECU							0x00000017
#define EVENT_OBJECT_CODE_ENV_TRUST_SUBJECT_SVR					0x00000018
#define EVENT_OBJECT_CODE_ENV_INFO_REC							0x00000019
#define EVENT_OBJECT_CODE_ENV_INFO_REC_SITE_REF					0x0000001A
#define EVENT_OBJECT_CODE_ENV_LOG_BACKUP						0x0000001B
#define EVENT_OBJECT_CODE_ENV_PTN								0x0000001C
#define EVENT_OBJECT_CODE_ENV_PTN_FILE							0x0000001D
#define EVENT_OBJECT_CODE_ENV_ORG								0x0000001E
#define EVENT_OBJECT_CODE_ENV_SORG_LINK_EXCLUDE_MATCH			0x0000001F
#define EVENT_OBJECT_CODE_ENV_SORG_LINK_EXCLUDE_DB				0x00000020


#define EVENT_OBJECT_CODE_COMMON_SITE_CPU						0x00000001
#define EVENT_OBJECT_CODE_COMMON_SITE_SW						0x00000002
#define EVENT_OBJECT_CODE_COMMON_SITE_PATH						0x00000003
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE						0X00000004
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE_PUBLISHER			0X00000005
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE_CODE_SIGN			0x00000006
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE_BANK					0x00000007
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE_REF					0x00000008
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_FILE					0x00000009
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_PKG					0x0000000A
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_PKG_UNIT				0x0000000B
#define EVENT_OBJECT_CODE_COMMON_SITE_VULN						0x0000000C
#define EVENT_OBJECT_CODE_COMMON_SITE_VULN_SCAN					0x0000000D
#define EVENT_OBJECT_CODE_COMMON_SITE_VULN_REPAIR				0x0000000E
#define EVENT_OBJECT_CODE_COMMON_SITE_VULN_LOCK					0x0000000F
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE_PRODUCT				0x00000010
#define EVENT_OBJECT_CODE_COMMON_SITE_PATCH						0x00000011
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_PATCH					0x00000012
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_VULN					0x00000013
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_VULN_SCAN				0x00000014
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_VULN_MP				0x00000015
#define EVENT_OBJECT_CODE_COMMON_SITE_PTN_PROC_FILE				0x00000016
#define EVENT_OBJECT_CODE_COMMON_SITE_FILE_ALIAS				0x00000017

#define EVENT_OBJECT_CODE_INFO_PROC_REPUTATION					0x00000001

//EVENT_OBJECT_CODE_POLICY
#define EVENT_OBJECT_CODE_POLICY_UPDATE							0x00000001
#define EVENT_OBJECT_CODE_POLICY_SVR_INFO_LGN					0x00000002
#define EVENT_OBJECT_CODE_POLICY_HOST_RM_INFO					0x00000003
#define EVENT_OBJECT_CODE_POLICY_HOST_RUN						0x00000004
#define EVENT_OBJECT_CODE_POLICY_HOST_CLEAR						0x00000005
#define EVENT_OBJECT_CODE_POLICY_POWER							0x00000006
#define EVENT_OBJECT_CODE_POLICY_CTL_PANEL						0x00000007
#define EVENT_OBJECT_CODE_POLICY_CTL_PROC						0x00000008
#define EVENT_OBJECT_CODE_POLICY_SELF_PROTECT					0x00000009
#define EVENT_OBJECT_CODE_POLICY_DEPLOY_FILE					0x0000000A
#define EVENT_OBJECT_CODE_POLICY_FA_CLEAR						0x0000000B
#define EVENT_OBJECT_CODE_POLICY_FA_PROC						0x0000000C
#define EVENT_OBJECT_CODE_POLICY_FA_ENV							0x0000000D
#define EVENT_OBJECT_CODE_POLICY_FA_OP							0x0000000E
#define EVENT_OBJECT_CODE_POLICY_FA_BK							0x0000000F
#define EVENT_OBJECT_CODE_POLICY_WIN_RUN						0x00000010
#define EVENT_OBJECT_CODE_POLICY_SVR_INFO_UDT					0x00000011
#define EVENT_OBJECT_CODE_POLICY_SVR_INFO_MGR					0x00000012
#define EVENT_OBJECT_CODE_POLICY_FE_PTN_OP						0x00000013
#define EVENT_OBJECT_CODE_POLICY_FE_PTN_BL						0x00000014
#define EVENT_OBJECT_CODE_POLICY_FE_PTN_WL						0x00000015
#define EVENT_OBJECT_CODE_POLICY_FE_EXCLUDE						0x00000016
#define EVENT_OBJECT_CODE_POLICY_FE_NOTIFY						0x00000017
#define EVENT_OBJECT_CODE_POLICY_FE_SINGLE_PTN					0x00000018
#define EVENT_OBJECT_CODE_POLICY_FE_PTN_LO						0x00000019
#define EVENT_OBJECT_CODE_POLICY_FA_NOTIFY						0x0000001A
#define EVENT_OBJECT_CODE_POLICY_SCH							0x00000020

#define EVENT_OBJECT_CODE_POLICY_IN_PTN_OP						0x00000021
#define EVENT_OBJECT_CODE_POLICY_IN_PTN_BL						0x00000022
#define EVENT_OBJECT_CODE_POLICY_IN_PTN_WL						0x00000023
#define EVENT_OBJECT_CODE_POLICY_IN_PTN_EX						0x00000024
#define EVENT_OBJECT_CODE_POLICY_IN_PTN_SP						0x00000025
#define EVENT_OBJECT_CODE_POLICY_IN_PTN_NO						0x00000026
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_OP						0x00000027
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_SCAN					0x00000028

#define EVENT_OBJECT_CODE_POLICY_HOST_NOTIFY					0x00000035
#define EVENT_OBJECT_CODE_POLICY_DV_OP							0x00000036
#define EVENT_OBJECT_CODE_POLICY_DV_BL							0x00000037
#define EVENT_OBJECT_CODE_POLICY_DV_WL							0x00000038
#define EVENT_OBJECT_CODE_POLICY_DV_EX							0x00000039
#define EVENT_OBJECT_CODE_POLICY_DV_INFO						0x0000003A
#define EVENT_OBJECT_CODE_POLICY_PM_OP							0x0000003B
#define EVENT_OBJECT_CODE_POLICY_PM_DM							0x0000003C
#define EVENT_OBJECT_CODE_POLICY_PM_SCAN						0x0000003D
#define EVENT_OBJECT_CODE_POLICY_PM_EX							0x0000003E
#define EVENT_OBJECT_CODE_POLICY_PM_NO							0x0000003F
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_AX						0x00000040
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_EDIT_APP				0x00000041
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_QNA					0x00000042
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_SECU_USB				0x00000043
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_SW						0x00000044
#define EVENT_OBJECT_CODE_POLICY_IN_VULN_PATCH_EXCEPTION		0x00000045
#define EVENT_OBJECT_CODE_POLICY_DV_NOTIFY						0x00000046
#define EVENT_OBJECT_CODE_POLICY_IN_RS_OP						0x00000047
#define EVENT_OBJECT_CODE_POLICY_IN_RS_NO						0x00000048
#define EVENT_OBJECT_CODE_POLICY_IN_RS_BK						0x00000049
#define EVENT_OBJECT_CODE_POLICY_SELF_PROTECT_SVR				0x0000004A

#define EVENT_OBJECT_CODE_POLICY_NC_PTN_OP						0x0000004B
#define EVENT_OBJECT_CODE_POLICY_NC_PTN_LO						0x0000004C
#define EVENT_OBJECT_CODE_POLICY_NC_PTN_BL						0x0000004D
#define EVENT_OBJECT_CODE_POLICY_NC_PTN_WL						0x0000004E
#define EVENT_OBJECT_CODE_POLICY_NC_PTN_EX						0x0000004F
#define EVENT_OBJECT_CODE_POLICY_NC_PTN_SP						0x00000050
#define EVENT_OBJECT_CODE_POLICY_NC_PTN_NO						0x00000051

#define EVENT_OBJECT_CODE_POLICY_HOST_WEB_SOCK					0x00000052

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//EVENT_OBJECT_CODE_POLICY_UNIT
#define EVENT_OBJECT_CODE_POLICY_UNIT_POWER						0x00000001
#define EVENT_OBJECT_CODE_POLICY_UNIT_CTL_PANEL					0x00000002
#define EVENT_OBJECT_CODE_POLICY_UNIT_CTL_PROC					0x00000003
#define EVENT_OBJECT_CODE_POLICY_UNIT_SELF_PROTECT				0x00000004
#define EVENT_OBJECT_CODE_POLICY_UNIT_DEPLOY_FILE				0x00000005
#define EVENT_OBJECT_CODE_POLICY_UNIT_DEPLOY_FILE_INFO			0x00000006
#define EVENT_OBJECT_CODE_POLICY_UNIT_DEPLOY_FILE_CHK			0x00000007
#define EVENT_OBJECT_CODE_POLICY_UNIT_DEPLOY_FILE_SCH			0x00000008
#define EVENT_OBJECT_CODE_POLICY_UNIT_HOST_CLEAR				0x00000009
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_CLEAR					0x0000000A
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_PROC					0x0000000B
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_ENV					0x0000000C
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_OP						0x0000000D
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_OP_SUB					0x0000000E
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_OP_OBJ					0x0000000F
#define EVENT_OBJECT_CODE_POLICY_UNIT_FA_OP_SCH					0x00000010
#define EVENT_OBJECT_CODE_POLICY_UNIT_DEPLOY_FILE_TAR			0x00000011
#define EVENT_OBJECT_CODE_POLICY_UNIT_FE_EXCLUDE				0x00000012
#define EVENT_OBJECT_CODE_POLICY_UNIT_FE_SINGLE_PTN				0x00000013

#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_OP					0x0000001A
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_WL					0x0000001B
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_WL_FILE			0x0000001C
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_BL					0x0000001D
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_BL_FILE			0x0000001E
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_EX					0x0000001F
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_SP					0x00000020
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_SP_RULE			0x00000021
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_NO					0x00000022
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_OP				0x00000023
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_SCAN				0x00000024

#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_PTN_EX_TRUST			0x00000035

#define EVENT_OBJECT_CODE_POLICY_UNIT_SCH						0x00000036
#define EVENT_OBJECT_CODE_POLICY_UNIT_HOST_NOTIFY				0x00000037

#define EVENT_OBJECT_CODE_POLICY_UNIT_DV_BL						0x00000038
#define EVENT_OBJECT_CODE_POLICY_UNIT_DV_WL						0x00000039
#define EVENT_OBJECT_CODE_POLICY_UNIT_DV_EX						0x0000003A

#define EVENT_OBJECT_CODE_POLICY_UNIT_PM_OP						0x0000003B
#define EVENT_OBJECT_CODE_POLICY_UNIT_PM_DM						0x0000003C
#define EVENT_OBJECT_CODE_POLICY_UNIT_PM_SCAN					0x0000003D
#define EVENT_OBJECT_CODE_POLICY_UNIT_PM_EX						0x0000003E
#define EVENT_OBJECT_CODE_POLICY_UNIT_PM_NO						0x0000003F

#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_AX				0x00000040
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_EDIT_APP			0x00000041
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_QNA				0x00000042
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_SECU_USB			0x00000043
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_SW				0x00000044
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_VULN_PATCH_EXCEPTION	0x00000045

#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_RS_OP					0x00000046
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_RS_OP_SUB				0x00000047
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_RS_OP_OBJ				0x00000048
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_RS_BK					0x00000049
#define EVENT_OBJECT_CODE_POLICY_UNIT_IN_RS_NO					0x0000004A

#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_OP					0x0000004B
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_LO					0x0000004C
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_WL					0x0000004D
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_WL_FILE			0x0000004E
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_BL					0x0000004F
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_BL_FILE			0x00000050
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_EX					0x00000051
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_SP					0x00000052
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_SP_RULE			0x00000053
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_NO					0x00000054
#define EVENT_OBJECT_CODE_POLICY_UNIT_NC_PTN_EX_TRUST			0x00000055

#endif	//COM_DEFINE_STATUS_EVENT_H_938EF200_F60B_452A_BD30_A10E8507EDCC
