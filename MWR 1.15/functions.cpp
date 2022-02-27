#include "functions.h"

AngleVectors_t AngleVectors;

Cbuf_AddText_t Cbuf_AddText;

Cmd_RegisterNotification_t Cmd_RegisterNotification;
Cmd_TokenizeStringKernel_t Cmd_TokenizeStringKernel;

DB_FindXAssetHeader_t DB_FindXAssetHeader;

G_DObjGetWorldTagPos_t G_DObjGetWorldTagPos;
G_FreeEntity_t G_FreeEntity;
G_GetAngles_t G_GetAngles;
G_GetOrigin_t G_GetOrigin;
G_GetPlayerViewOrigin_t G_GetPlayerViewOrigin;
G_LocalizedStringIndex_t G_LocalizedStringIndex;
G_LocationalTrace_t G_LocationalTrace;
G_MaterialIndex_t G_MaterialIndex;
G_ModelName_t G_ModelName;
G_SetAngle_t G_SetAngle;
G_SetModel_t G_SetModel;
G_SetOrigin_t G_SetOrigin;
G_Spawn_t G_Spawn;

GScr_MapRestart_t GScr_MapRestart;

HudElem_Alloc_t HudElem_Alloc;
HudElem_DestroyAll_t HudElem_DestroyAll;

LUI_GetRootElement_t LUI_GetRootElement;
LUI_Interface_DrawLine_t LUI_Interface_DrawLine;

Material_RegisterHandle_t Material_RegisterHandle;

Menus_OpenByName_t Menus_OpenByName;

PlayerCmd_AllowBoostJump_t PlayerCmd_AllowBoostJump;
PlayerCmd_AllowDodge_t PlayerCmd_AllowDodge;
PlayerCmd_AllowHighJumpDrop_t PlayerCmd_AllowHighJumpDrop;
PlayerCmd_AllowLadder_t PlayerCmd_AllowLadder;
PlayerCmd_AllowMantle_t PlayerCmd_AllowMantle;
PlayerCmd_AllowPowerSlide_t PlayerCmd_AllowPowerSlide;
PlayerCmd_AllowSprint_t PlayerCmd_AllowSprint;
PlayerCmd_ForceMantle_t PlayerCmd_ForceMantle;
PlayerCmd_SetClientDvar_t PlayerCmd_SetClientDvar;
PlayerCmd_setOrigin_t PlayerCmd_setOrigin;

R_AddCmdDrawStretchPic_t R_AddCmdDrawStretchPic;
R_AddCmdDrawText_t R_AddCmdDrawText;
R_AddCmdDrawTextWithEffects_t R_AddCmdDrawTextWithEffects;
R_GetCommandBuffer_t R_GetCommandBuffer;
R_RegisterFont_t R_RegisterFont;
R_TextHeight_t R_TextHeight;
R_TextWidth_t R_TextWidth;

Scr_AddEntity_t Scr_AddEntity;
Scr_AddInt_t Scr_AddInt;
Scr_AddString_t Scr_AddString;
Scr_AddVector_t Scr_AddVector;
Scr_GetSelf_t Scr_GetSelf;
Scr_MagicBullet_t Scr_MagicBullet;
Scr_NotifyNum_t Scr_NotifyNum;

SL_ConvertToString_t SL_ConvertToString;
SL_GetString_t SL_GetString;

SP_script_model_t SP_script_model;

SV_GameSendServerCommand_t SV_GameSendServerCommand;
SV_LinkEntity_t SV_LinkEntity;
SV_SetBrushModel_t SV_SetBrushModel;
SV_UnlinkEntity_t SV_UnlinkEntity;

Trace_GetEntityHitId_t Trace_GetEntityHitId;












AimTarget_GetTagPos_t AimTarget_GetTagPos;
AimTarget_IsTargetVisible_t AimTarget_IsTargetVisible;

CG_CanSeeFriendlyHeadTrace_t CG_CanSeeFriendlyHeadTrace;
CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos;
CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;
//CG_TracePoint_t CG_TracePoint;

CL_DrawText_t CL_DrawText;

R_AddCmdDrawQuadPicW_t R_AddCmdDrawQuadPicW;

SL_GetStringOfSize_t SL_GetStringOfSize;

UI_DrawText_t UI_DrawText;
UI_FillRectPhysical_t UI_FillRectPhysical;

sub_E9F770_t sub_E9F770;

//Custom
void AimTarget_GetTagPos_Custom(int entNum, const char *tagName, float *pos) {
	int dobj = 0;//Com_GetClientDObj(centity[entNum].nextState.number, 0);

	if (!dobj)
		return;

	//CG_DObjGetWorldTagPos(centity[entNum].__address, dobj, SL_GetString(tagName), pos);
}

bool AimTarget_IsTargetVisible_Custom(int targetEntNum, const char *visBone) {
	float tagPos[3];
	//AimTarget_GetTagPos_Custom(targetEntNum, visBone, tagPos);

	//float mins[3] = { 0.0f, 0.0f, 0.0f };
	//float maxs[3] = { 99999.0f, 99999.0f, 99999.0f };

	//trace_t trace;
	//col_context_t cont;
	//cont.mask = 0x280B001;
	//cont.passEntityNum0 = 0x3FF;
	//cont.passEntityNum1 = 0x3FF;
	//cont.param1 = 0xFFFFFFFF;

	//cont.mask = 0x280E813;
	//CM_Trace(&trace, cg.refdef.vieworg, tagPos, mins, maxs, 0, 0x280E813, &cont);

	//CG_TracePoint(&trace, cg.refdef.vieworg, tagPos, 0x3FF, 0x280B001, true, true, false, &cont, false);

	return AimTarget_IsTargetVisible(LocalClientNum_t::LOCAL_CLIENT_0, centity[targetEntNum].__address);
	//return true;//CG_CanSeeFriendlyHeadTrace(0, cent, cg.refdef.vieworg, tagPos); //AimTarget_IsTargetVisible(0, cent);
	//return trace.fraction >= 1.0f;
}

bool Dvar_GetBool(const char *dvarName) {
	int dvar_s = 0; //Dvar_FindVar(dvarName);
	if (dvar_s)
		return *(bool **)(dvar_s + 0x10);
}

const char *Dvar_GetString(const char *dvarName) {
	int dvar_s = 0; //Dvar_FindVar(dvarName);
	if (dvar_s)
		return *(const char **)(dvar_s + 0x10);
}

void Scr_SetNumParam(int paramcount) {
	*(int*)(0x000000000A6C6098 + 0x2C) = paramcount;
}
