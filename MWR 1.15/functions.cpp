#include "functions.h"

#include "imports.h"

AddBaseDrawTextCmd_t AddBaseDrawTextCmd;

AngleVectors_t AngleVectors;

CG_DrawRotatedPic_t CG_DrawRotatedPic;
CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;

Cmd_TokenizeStringKernel_t Cmd_TokenizeStringKernel;

DB_FindXAssetHeader_t DB_FindXAssetHeader;

G_Damage_t G_Damage;
G_DObjGetWorldTagPos_t G_DObjGetWorldTagPos;
G_FindConfigstringIndex_t G_FindConfigstringIndex;
G_FreeEntity_t G_FreeEntity;
G_GetAngles_t G_GetAngles;
G_GetOrigin_t G_GetOrigin;
G_GetPlayerViewOrigin_t G_GetPlayerViewOrigin;
G_GetWeaponForName_t G_GetWeaponForName;
G_LocationalTrace_t G_LocationalTrace;
G_ModelName_t G_ModelName;
G_SetAngle_t G_SetAngle;
G_Spawn_t G_Spawn;

GScr_MapRestart_t GScr_MapRestart;

hks_obj_tolstring_t hks_obj_tolstring;

HudElem_Alloc_t HudElem_Alloc;

LUI_GetRootElement_t LUI_GetRootElement;
LUI_Interface_DrawLine_t LUI_Interface_DrawLine;

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
R_TextWidth_t R_TextWidth;

RemoveRefToValue_t RemoveRefToValue;

Scr_AddEntityNum_t Scr_AddEntityNum;
Scr_AddString_t Scr_AddString;
Scr_AddVector_t Scr_AddVector;
Scr_MagicBullet_t Scr_MagicBullet;

ScriptEntCmd_CloneBrushModelToScriptModel_t ScriptEntCmd_CloneBrushModelToScriptModel;
ScriptEntCmd_ScriptModelPlayAnim_t ScriptEntCmd_ScriptModelPlayAnim;
ScriptEntCmd_Solid_t ScriptEntCmd_Solid;

SL_GetStringOfSize_t SL_GetStringOfSize;

SP_script_model_t SP_script_model;

SV_LinkEntity_t SV_LinkEntity;
SV_SendServerCommand_t SV_SendServerCommand;
SV_SetBrushModel_t SV_SetBrushModel;
SV_UnlinkEntity_t SV_UnlinkEntity;

Sys_Error_t Sys_Error;

Trace_GetEntityHitId_t Trace_GetEntityHitId;












AimTarget_GetTagPos_t AimTarget_GetTagPos;
AimTarget_IsTargetVisible_t AimTarget_IsTargetVisible;

CG_CanSeeFriendlyHeadTrace_t CG_CanSeeFriendlyHeadTrace;
CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos;

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

//MWR

void Cbuf_AddText(LocalClientNum_t localClientNum, const char *text) { //reversed from 0x000000000075D702 (GScr_EndLobby + 0xE2)
	//we ignore the localClientNum param for now
	int stringLength = strlen(text);
	strcpy((char *)(*(uint64_t *)0x0000000002DBF390), text);
	*(char *)(*(uint64_t *)0x0000000002DBF390 + stringLength + 1) = 0;
	*(int *)(0x0000000002DBF390 + 0x0C) = stringLength + 1;
}

void Cmd_RegisterNotification(int clientNum, const char *commandString, const char *notifyString) { //reversed from 0x0000000000A4E227 (GScr_notifyOnPlayerCommand + 0x1F7)
	int numOfNotifications = *(int *)0x0000000002DC9610;
	if (numOfNotifications == 512)
		return;

	int bindKey = Key_GetBindingForCmd(commandString);
	scr_string_t bindString = SL_GetString(notifyString, 0);

	for (int i = 0; i < numOfNotifications; i++) {
		uint64_t commandStart = 0x0000000002DC9620 + (i * 0x0C);
		if (*(int *)commandStart == clientNum && *(int *)(commandStart + 4) == bindKey && *(scr_string_t *)(commandStart + 8) == bindString)
			return;
	}
	
	uint64_t newCommandStart = 0x0000000002DC9620 + (numOfNotifications * 0x0C);
	*(int *)newCommandStart = clientNum;
	*(int *)(newCommandStart + 0x04) = bindKey;
	*(scr_string_t *)(newCommandStart + 0x08) = bindString;
	*(int *)0x0000000002DC9610 = ++numOfNotifications;
}

int G_LocalizedStringIndex(const char *string) { //reversed from 0x0000000000A66DA0 (HECmd_SetText + 0x90)
	int create = *(int *)0x000000000B0FE8B0;
	return G_FindConfigstringIndex(string, (ConfigString)0x21D, 0x28A, create == 0 ? 1 : 0, "localized string");
}

int G_MaterialIndex(const char *name) { //reversed from 0x0000000000AF322A
	return G_FindConfigstringIndex(name, (ConfigString)0xD9A, 0x1A0, 0, "material");
}

int G_ModelIndex(const char *name) { //reversed from 0x0000000000A45DCD (PlayerCmd_SetViewmodel + 0xCD)
	return G_FindConfigstringIndex(name, (ConfigString)0x4D8, 0x400, 0, "model");
	//G_HasCachedModel and G_SetCachedModel still missing, works fine without
}

void G_SetModel(gentity_s *ent, const char *modelName) { //custom
	ent->modelIndex = G_ModelIndex(modelName);
}

void G_SetOrigin(gentity_s *ent, const float *origin) { //custom
	ent->origin[0] = origin[0];
	ent->origin[1] = origin[1];
	ent->origin[2] = origin[2];
}

void HudElem_DestroyAll() { //custom
	int offset = 0;
	while (offset < 0x30000) {
		*(int *)(0x000000000B0BC840/*g_hudelems*/ + offset + 0x1C) = he_type_t::HE_TYPE_FREE;
		offset += 0xD0;
	}
}

void HudElem_DestroyClient(int clientIndex) { //custom
	if (clientIndex == -1) {
		HudElem_DestroyAll();
		return;
	}
	
	int offset = 0;
	uint64_t g_hudelems = 0x000000000B0BC840;
	while (offset < 0x30000) { //elem + 0x00 && elem + 0x01 //custom check applied in PrecacheElem
		if (*(short *)(g_hudelems + offset + 0x00) == 1 && *(short *)(g_hudelems + offset + 0x02) == 1 && *(int *)(g_hudelems + offset + 0xC0) == clientIndex)
			*(int *)(g_hudelems + offset + 0x1C) = he_type_t::HE_TYPE_FREE;
		offset += 0xD0;
	}
}

int Key_GetBindingForCmd(const char *cmd) { //reversed from 0x0000000000A4E0E6 (GScr_notifyOnPlayerCommand + 0xB6)
	uint64_t *g_bindCommands = (uint64_t *)0x000000000104EAA0;

	for (int i = 0; i < 45; i++)
		if (!strcmp((const char *)g_bindCommands[i], cmd))
			return i;

	return 0;
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

Material *Material_RegisterHandle(const char *name, int imageTrack) { //custom
	return (Material *)DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, name, 1);
}

int R_TextHeight(Font_s *font) { //custom
	return font->pixelHeight;
}

void Scr_AddConstString(scr_string_t value) { //reversed from 0x000000000064BDB6 (Scr_PlayerDamage + 0x126)
	Scr_ClearOutParams();

	uint64_t rax = *(uint64_t *)0x000000000FBC6E28;
	int r15d = *(int *)0x000000000FBC6E34;
	uint64_t rcx = 0x000000000FBD1370;

	if (rax == rcx || rax == *(uint64_t *)0x000000000FBC6E10) {
		Sys_Error("Internal script stack overflow");
		return;
	}

	rcx = rax + 0x10;
	*(uint64_t *)0x000000000FBC6E28 = rcx;
	(*(int *)0x000000000FBC6E30)++;
	*(int *)(rax + 0x18) = 2; //type
	*(int *)(rax + 0x10) = value;

	(*(int *)((value << 4) + *(uint64_t *)0x000000000F0A1D58))++;
}

void Scr_AddEntity(const gentity_s *ent) { //custom
	Scr_AddEntityNum(ent->number, 0);
}

void Scr_AddInt(int value) { //NOT TESTED
	Scr_ClearOutParams();

	uint64_t rax = *(uint64_t *)0x000000000FBC6E28;
	int r15d = *(int *)0x000000000FBC6E34;
	uint64_t rcx = 0x000000000FBD1370;

	if (rax == rcx || rax == *(uint64_t *)0x000000000FBC6E10) {
		Sys_Error("Internal script stack overflow");
		return;
	}

	rcx = rax + 0x10;
	*(uint64_t *)0x000000000FBC6E28 = rcx;
	(*(int *)0x000000000FBC6E30)++;
	*(int *)(rax + 0x18) = 6; //type
	*(int *)(rax + 0x10) = value;

	(*(int *)((value << 4) + *(uint64_t *)0x000000000F0A1D58))++;
}

void Scr_ClearOutParams() { //reversed from 0x0000000000BE41EA (Scr_AddString + 0x0A)
	int r15d = *(int *)0x000000000FBC6E34;
	if (!r15d)
		return;

	uint64_t rbx = *(uint64_t *)0x000000000FBC6E28;
	uint64_t rax = r15d << 4;
	uint64_t rcx = rbx;
	rbx += 8;
	rcx -= rax;
	*(uint64_t *)0x000000000FBC6E28 = rcx;
	*(int *)0x000000000FBC6E34 = 0;

	while (r15d != 0) {
		RemoveRefToValue(*(int *)rbx, *(VariableUnion *)(rbx - 8));
		rbx -= 0x10;
		r15d--;
	}
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

scr_string_t SL_GetString(const char *str, unsigned int user) { //reversed from 0x0000000000A4E151 (GScr_notifyOnPlayerCommand + 0x121)
	int len = strlen(str) + 1;

	return SL_GetStringOfSize(str, user, len, 0);
}

void SV_GameSendServerCommand(signed char clientNum, svscmd_type type, const char *text) { //reversed from 0x0000000000A4D03A (VisionSetForPlayer + 0xEA)
	if (clientNum == -1)
		SV_SendServerCommand(0, type, text);
	else {
		client_t *client_s = (client_t *)(*(uint64_t *)(0x00000000026B7E10) + (clientNum * 0xE7680));
		SV_SendServerCommand(client_s, type, text);
	}
}
