#include "functions.h"

NAMESPACE(Functions)

void Init() {
	//AngleVectors = (AngleVectors_t)0x0000000000921200;

	//Cmd_TokenizeStringKernel = (Cmd_TokenizeStringKernel_t)0x00000000007F6980;
	
	DB_FindXAssetHeader = (DB_FindXAssetHeader_t)0x00000000009B6590;
	
	//G_DObjGetWorldTagPos = (G_DObjGetWorldTagPos_t)0x000000000076B250;
	G_FindConfigstringIndex = (G_FindConfigstringIndex_t)0x00000000004F8650;
	G_FreeEntity = (G_FreeEntity_t)0x0000000000AFBBE0;
	//G_GetAngles = (G_GetAngles_t)0x000000000076C310;
	//G_GetPlayerViewOrigin = (G_GetPlayerViewOrigin_t)0x0000000000708BB0;
	//G_LocalizedStringIndex = (G_LocalizedStringIndex_t)0x0000000000442410;
	//G_LocationalTrace = (G_LocationalTrace_t)0x0000000000726550;
	//G_MaterialIndex = (G_MaterialIndex_t)0x000000000043C4A0;
	//G_ModelName = (G_ModelName_t)0x000000000043C510;
	//G_SetAngle = (G_SetAngle_t)0x000000000076C230;
	//G_GetOrigin = (G_GetOrigin_t)0x000000000076C2D0;
	G_Spawn = (G_Spawn_t)0x0000000000AFBAB0;
	
	//GScr_MapRestart = (GScr_MapRestart_t)0x00000000007583E0;

	hks_obj_tolstring = (hks_obj_tolstring_t)0x00000000007AE0B0;
	
	//HudElem_Alloc = (HudElem_Alloc_t)0x000000000071BC20;
	//HudElem_DestroyAll = (HudElem_DestroyAll_t)0x000000000071BE00;
	
	//LUI_GetRootElement = (LUI_GetRootElement_t)0x00000000004CF350;
	//LUI_Interface_DrawLine = (LUI_Interface_DrawLine_t)0x00000000004F2CA0;
	
	//Material_RegisterHandle = (Material_RegisterHandle_t)0x0000000000A058D0;
		
	//PlayerCmd_AllowBoostJump = (PlayerCmd_AllowBoostJump_t)0x000000000070F100;
	//PlayerCmd_AllowDodge = (PlayerCmd_AllowDodge_t)0x000000000070F180;
	//PlayerCmd_AllowHighJumpDrop = (PlayerCmd_AllowHighJumpDrop_t)0x000000000070F280;
	//PlayerCmd_AllowLadder = (PlayerCmd_AllowLadder_t)0x000000000070F300;
	//PlayerCmd_AllowMantle = (PlayerCmd_AllowMantle_t)0x000000000070F3B0;
	//PlayerCmd_AllowPowerSlide = (PlayerCmd_AllowPowerSlide_t)0x000000000070F200;
	//PlayerCmd_AllowSprint = (PlayerCmd_AllowSprint_t)0x000000000070F460;
	//PlayerCmd_ForceMantle = (PlayerCmd_ForceMantle_t)0x0000000000710740;
	//PlayerCmd_SetClientDvar = (PlayerCmd_SetClientDvar_t)0x000000000070EA60;
	//PlayerCmd_setOrigin = (PlayerCmd_setOrigin_t)0x000000000070C800;
	
	//R_AddCmdDrawStretchPic = (R_AddCmdDrawStretchPic_t)0x0000000000A15D10;
	//R_AddCmdDrawText = (R_AddCmdDrawText_t)0x0000000000A16340;
	//R_AddCmdDrawTextWithEffects = (R_AddCmdDrawTextWithEffects_t)0x0000000000A16480;
	//R_GetCommandBuffer = (R_GetCommandBuffer_t)0x0000000000A15660;
	//R_RegisterFont = (R_RegisterFont_t)0x00000000009FB230;
	//R_TextHeight = (R_TextHeight_t)0x00000000009FB480;
	//R_TextWidth = (R_TextWidth_t)0x00000000009FB2E0;

	RemoveRefToValue = (RemoveRefToValue_t)0x0000000000BDFEF0;
	
	Scr_AddEntityNum = (Scr_AddEntityNum_t)0x0000000000BE3F50;
	Scr_AddString = (Scr_AddString_t)0x0000000000BE41E0;
	//Scr_AddVector = (Scr_AddVector_t)0x0000000000854CE0;
	//Scr_MagicBullet = (Scr_MagicBullet_t)0x000000000073BBB0;

	ScriptEntCmd_CloneBrushModelToScriptModel = (ScriptEntCmd_CloneBrushModelToScriptModel_t)0x0000000000AEFE40;
	ScriptEntCmd_ScriptModelPlayAnim = (ScriptEntCmd_ScriptModelPlayAnim_t)0x0000000000AF0090;
	ScriptEntCmd_Solid = (ScriptEntCmd_Solid_t)0x0000000000AF06C0;
	
	SL_GetStringOfSize = (SL_GetStringOfSize_t)0x0000000000BDDA80;
	
	SP_script_model = (SP_script_model_t)0x0000000000AEBE50;
	
	SV_LinkEntity = (SV_LinkEntity_t)0x0000000000C6FF00;
	SV_SendServerCommand = (SV_SendServerCommand_t)0x0000000000648070;
	//SV_SetBrushModel = (SV_SetBrushModel_t)0x000000000089CFB0;
	//SV_UnlinkEntity = (SV_UnlinkEntity_t)0x00000000008B7460;

	Sys_Error = (Sys_Error_t)0x000000000051B820;
	
	//Trace_GetEntityHitId = (Trace_GetEntityHitId_t)0x00000000007ED970;

	
	
	
	//AimTarget_GetTagPos = (AimTarget_GetTagPos_t)vHandler->addresses.addr_AimTarget_GetTagPos;
	//AimTarget_IsTargetVisible = (AimTarget_IsTargetVisible_t)vHandler->addresses.addr_AimTarget_IsTargetVisible;

	//CG_CanSeeFriendlyHeadTrace = (CG_CanSeeFriendlyHeadTrace_t)0x00;
	//CG_DObjGetWorldTagPos = (CG_DObjGetWorldTagPos_t)0x00;
	//CG_DrawRotatedPicPhysical = (CG_DrawRotatedPicPhysical_t)vHandler->addresses.addr_CG_DrawRotatedPicPhysical;

	//CL_DrawText = (CL_DrawText_t)0x00;

	//R_AddCmdDrawQuadPicW = (R_AddCmdDrawQuadPicW_t)vHandler->addresses.addr_R_AddCmdDrawQuadPicW;

	//UI_DrawText = (UI_DrawText_t)vHandler->addresses.addr_UI_DrawText;
	//UI_FillRectPhysical = (UI_FillRectPhysical_t)vHandler->addresses.addr_UI_FillRectPhysical;
}

END
