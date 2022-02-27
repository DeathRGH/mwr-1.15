#include "functions.h"

#include "imports.h"

AngleVectors_t AngleVectors;

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

hks_obj_tolstring_t hks_obj_tolstring;

HudElem_Alloc_t HudElem_Alloc;
HudElem_DestroyAll_t HudElem_DestroyAll;

LUI_GetRootElement_t LUI_GetRootElement;
LUI_Interface_DrawLine_t LUI_Interface_DrawLine;

Material_RegisterHandle_t Material_RegisterHandle;

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
Scr_MagicBullet_t Scr_MagicBullet;
Scr_NotifyNum_t Scr_NotifyNum;

SL_GetString_t SL_GetString;

SP_script_model_t SP_script_model;

SV_LinkEntity_t SV_LinkEntity;
SV_SendServerCommand_t SV_SendServerCommand;
SV_SetBrushModel_t SV_SetBrushModel;
SV_UnlinkEntity_t SV_UnlinkEntity;

Trace_GetEntityHitId_t Trace_GetEntityHitId;












AimTarget_GetTagPos_t AimTarget_GetTagPos;
AimTarget_IsTargetVisible_t AimTarget_IsTargetVisible;

CG_CanSeeFriendlyHeadTrace_t CG_CanSeeFriendlyHeadTrace;
CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos;
CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;

CL_DrawText_t CL_DrawText;

R_AddCmdDrawQuadPicW_t R_AddCmdDrawQuadPicW;

SL_GetStringOfSize_t SL_GetStringOfSize;

UI_DrawText_t UI_DrawText;
UI_FillRectPhysical_t UI_FillRectPhysical;

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

//MWR

void Cbuf_AddText(LocalClientNum_t localClientNum, const char *text) { //reversed from 0x000000000075D702 (GScr_EndLobby + 0xE2)
	//we ignore the localClientNum param for now
	int stringLength = strlen(text);
	strcpy((char *)(*(uint64_t *)0x0000000002DBF390), text);
	*(char *)(*(uint64_t *)0x0000000002DBF390 + stringLength + 1) = 0;
	*(int *)(0x0000000002DBF390 + 0x0C) = stringLength + 1;
}

void LUI_Interface_DebugPrint(const char *fmt, ...) { //custom
	char buffer[2048];
	va_list args;
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	va_end(args);

	char buffer2[2048];
	snprintf(buffer2, sizeof(buffer2), "[MWR 1.15] <LUI> %s", buffer);
	sceKernelDebugOutText(DGB_CHANNEL_TTYL, buffer2);
}

unsigned int Scr_GetSelf(unsigned int threadId) { //reversed from 0x0000000000BE2525 (Scr_CancelNotifyList + 0x25)
	//lea r12, word_F52A000
	//mov r8w, [r12+r15*8+2] //r15 = threadId
	return (unsigned int)(*(unsigned short *)(0x000000000F52A000 + (threadId * 8) + 2));
}

void Scr_SetNumParam(int paramcount) { //reversed from 0x0000000000A4E076 (GScr_notifyOnPlayerCommand + 0x06)
	*(int *)0x000000000FBC6E34 = paramcount;
}

const char *SL_ConvertToString(scr_string_t stringValue) { //reversed from 0x0000000000B1C672
	if (!stringValue)
		return 0;

	return (const char *)(*(uint64_t *)0x000000000F0A1D58 + (stringValue << 4) + 8);
}

const char *SL_ConvertToStringSafe(scr_string_t stringValue) { //reversed from 0x0000000000B1C672
	if (!stringValue)
		return "(NULL)";

	return SL_ConvertToString(stringValue);
}

void SV_GameSendServerCommand(signed char clientNum, svscmd_type type, const char *text) { //reversed from 0x0000000000A4D03A (VisionSetForPlayer + 0xEA)
	if (clientNum == -1)
		SV_SendServerCommand(0, type, text);
	else {
		uint64_t client_s = *(uint64_t *)(0x00000000026B7E10) + (clientNum * 0xE7680);
		SV_SendServerCommand((client_t *)client_s, type, text);
	}
}
