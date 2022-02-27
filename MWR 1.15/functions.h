#pragma once

#include "host_huds.h"
#include "structs.h"
#include "types.h"

typedef void(*AngleVectors_t)(const float *angles, float *forward, float *right, float *up);

typedef void(*Cbuf_AddText_t)(LocalClientNum_t localClientNum, const char *text);

typedef void(*Cmd_RegisterNotification_t)(int clientNum, const char *commandString, const char *notifyString);
typedef void(*Cmd_TokenizeStringKernel_t)(const char *text_in, int max_tokens, CmdArgs *args, CmdArgsPrivate *argsPriv);

typedef uint64_t(*DB_FindXAssetHeader_t)(XAssetType type, const char *name, int allowCreateDefault);

typedef int(*G_DObjGetWorldTagPos_t)(const gentity_s *, scr_string_t, float *);
typedef void(*G_FreeEntity_t)(gentity_s *);
typedef void(*G_GetAngles_t)(LocalClientNum_t localClientNum, short entIndex, float *outAngles);
typedef void(*G_GetOrigin_t)(LocalClientNum_t localClientNum, short entIndex, float *outPosition);
typedef void(*G_GetPlayerViewOrigin_t)(const playerState_s *, float *);
typedef uint64_t(*G_LocalizedStringIndex_t)(const char *text);
typedef void(*G_LocationalTrace_t)(/*trace_t **/void *results, const float *start, const float *end, short passEntityNum, int contentmask, unsigned char *priorityMap);
typedef uint64_t(*G_MaterialIndex_t)(const char *material);
typedef unsigned int(*G_ModelName_t)(int index);
typedef void(*G_SetAngle_t)(gentity_s *, const float *);
typedef void(*G_SetModel_t)(gentity_s *, const char *);
typedef void(*G_SetOrigin_t)(gentity_s *, const float *);
typedef gentity_s *(*G_Spawn_t)();

typedef void(*GScr_MapRestart_t)();

typedef game_hudelem_t(*HudElem_Alloc_t)(int clientNum, int teamNum);
typedef void(*HudElem_DestroyAll_t)();

typedef LUIElement *(*LUI_GetRootElement_t)(const char *, lua_State *);
typedef void(*LUI_Interface_DrawLine_t)(LUIElement *, float x1, float y1, float x2, float y2, unsigned char, float, float r, float g, float b, float a);

typedef Material *(*Material_RegisterHandle_t)(const char *name, int imageTrack);

typedef void(*Menus_OpenByName_t)(UiContext *, const char *);

typedef void(*PlayerCmd_AllowBoostJump_t)(scr_entref_t entref);
typedef void(*PlayerCmd_AllowDodge_t)(scr_entref_t entref);
typedef void(*PlayerCmd_AllowHighJumpDrop_t)(scr_entref_t entref);
typedef void(*PlayerCmd_AllowLadder_t)(scr_entref_t entref);
typedef void(*PlayerCmd_AllowMantle_t)(scr_entref_t entref);
typedef void(*PlayerCmd_AllowPowerSlide_t)(scr_entref_t entref);
typedef void(*PlayerCmd_AllowSprint_t)(scr_entref_t entref);
typedef void(*PlayerCmd_ForceMantle_t)(scr_entref_t entref);
typedef void(*PlayerCmd_SetClientDvar_t)(scr_entref_t entref);
typedef void(*PlayerCmd_setOrigin_t)(scr_entref_t entref);

typedef void(*R_AddCmdDrawStretchPic_t)(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const float *color, Material *material);
typedef void(*R_AddCmdDrawText_t)(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const float *color, int style);
typedef void(*R_AddCmdDrawTextWithEffects_t)(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const float *color, int style, const float *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration);
typedef void *(*R_GetCommandBuffer_t)(GfxRenderCommand renderCmd, unsigned long bytes);
typedef Font_s *(*R_RegisterFont_t)(const char *name, int imageTrack);
typedef int(*R_TextHeight_t)(Font_s *font);
typedef int(*R_TextWidth_t)(const char *text, int maxChars, Font_s *font);

typedef void(*Scr_AddEntity_t)(const gentity_s *);
typedef void(*Scr_AddInt_t)(int value);
typedef void(*Scr_AddString_t)(const char *value);
typedef void(*Scr_AddVector_t)(const float *value);
typedef unsigned int(*Scr_GetSelf_t)(unsigned int threadId);
typedef void(*Scr_MagicBullet_t)();
typedef void(*Scr_NotifyNum_t)(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount);

typedef const char *(*SL_ConvertToString_t)(scr_string_t stringValue);
typedef scr_string_t(*SL_GetString_t)(const char *str, unsigned int user);

typedef void(*SP_script_model_t)(gentity_s *);

typedef void(*SV_GameSendServerCommand_t)(signed char clientNum, svscmd_type type, const char *text);
typedef void(*SV_LinkEntity_t)(gentity_s *);
typedef void(*SV_SetBrushModel_t)(gentity_s *);
typedef void(*SV_UnlinkEntity_t)(gentity_s *);

typedef unsigned short(*Trace_GetEntityHitId_t)(/*const trace_t **/void *trace);

//

extern AngleVectors_t AngleVectors;

extern Cbuf_AddText_t Cbuf_AddText;

extern Cmd_RegisterNotification_t Cmd_RegisterNotification;
extern Cmd_TokenizeStringKernel_t Cmd_TokenizeStringKernel;

extern DB_FindXAssetHeader_t DB_FindXAssetHeader;

extern G_DObjGetWorldTagPos_t G_DObjGetWorldTagPos;
extern G_FreeEntity_t G_FreeEntity;
extern G_GetAngles_t G_GetAngles;
extern G_GetOrigin_t G_GetOrigin;
extern G_GetPlayerViewOrigin_t G_GetPlayerViewOrigin;
extern G_LocalizedStringIndex_t G_LocalizedStringIndex;
extern G_LocationalTrace_t G_LocationalTrace;
extern G_MaterialIndex_t G_MaterialIndex;
extern G_ModelName_t G_ModelName;
extern G_SetAngle_t G_SetAngle;
extern G_SetModel_t G_SetModel;
extern G_SetOrigin_t G_SetOrigin;
extern G_Spawn_t G_Spawn;

extern GScr_MapRestart_t GScr_MapRestart;

extern HudElem_Alloc_t HudElem_Alloc;
extern HudElem_DestroyAll_t HudElem_DestroyAll;

extern LUI_GetRootElement_t LUI_GetRootElement;
extern LUI_Interface_DrawLine_t LUI_Interface_DrawLine;

extern Material_RegisterHandle_t Material_RegisterHandle;

extern Menus_OpenByName_t Menus_OpenByName;

extern PlayerCmd_AllowBoostJump_t PlayerCmd_AllowBoostJump;
extern PlayerCmd_AllowDodge_t PlayerCmd_AllowDodge;
extern PlayerCmd_AllowHighJumpDrop_t PlayerCmd_AllowHighJumpDrop;
extern PlayerCmd_AllowLadder_t PlayerCmd_AllowLadder;
extern PlayerCmd_AllowMantle_t PlayerCmd_AllowMantle;
extern PlayerCmd_AllowPowerSlide_t PlayerCmd_AllowPowerSlide;
extern PlayerCmd_AllowSprint_t PlayerCmd_AllowSprint;
extern PlayerCmd_ForceMantle_t PlayerCmd_ForceMantle;
extern PlayerCmd_SetClientDvar_t PlayerCmd_SetClientDvar;
extern PlayerCmd_setOrigin_t PlayerCmd_setOrigin;

extern R_AddCmdDrawStretchPic_t R_AddCmdDrawStretchPic;
extern R_AddCmdDrawText_t R_AddCmdDrawText;
extern R_AddCmdDrawTextWithEffects_t R_AddCmdDrawTextWithEffects;
extern R_GetCommandBuffer_t R_GetCommandBuffer;
extern R_RegisterFont_t R_RegisterFont;
extern R_TextHeight_t R_TextHeight;
extern R_TextWidth_t R_TextWidth;

extern Scr_AddEntity_t Scr_AddEntity;
extern Scr_AddInt_t Scr_AddInt;
extern Scr_AddString_t Scr_AddString;
extern Scr_AddVector_t Scr_AddVector;
extern Scr_GetSelf_t Scr_GetSelf;
extern Scr_MagicBullet_t Scr_MagicBullet;
extern Scr_NotifyNum_t Scr_NotifyNum;

extern SL_ConvertToString_t SL_ConvertToString;
extern SL_GetString_t SL_GetString;

extern SP_script_model_t SP_script_model;

extern SV_GameSendServerCommand_t SV_GameSendServerCommand;
extern SV_LinkEntity_t SV_LinkEntity;
extern SV_SetBrushModel_t SV_SetBrushModel;
extern SV_UnlinkEntity_t SV_UnlinkEntity;

extern Trace_GetEntityHitId_t Trace_GetEntityHitId;

















typedef void (*AimTarget_GetTagPos_t)(uint64_t ent, unsigned short tagName, float *pos);
typedef bool (*AimTarget_IsTargetVisible_t)(LocalClientNum_t localClientNum, uint64_t targetEnt);

typedef bool(*CG_CanSeeFriendlyHeadTrace_t)(int localClientNum, uint64_t cent, const float *start, const float *end);
typedef bool (*CG_DObjGetWorldTagPos_t)(uint64_t ent, int obj, unsigned short tagName, float *pos);
typedef void (*CG_DrawRotatedPicPhysical_t)(const ScreenPlacement *screenPlacement, float x, float y, float width, float height, float angle, const float *color, uint64_t material, uint64_t image);
//typedef void(*CG_TracePoint_t)(trace_t *results, const float *start, const float *end, int passEntityNum, unsigned int contentMask, bool locational, bool staticModels, bool checkRopes, col_context_t *context, bool checkGlass);

typedef void (*CL_DrawText_t)(const unsigned int scrPlace, const char *text, int maxChars, int font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const float *color, int style);

typedef void(*R_AddCmdDrawQuadPicW_t)(const float *verts, float w, const float *color, uint64_t material, uint64_t image);

typedef unsigned short (*SL_GetStringOfSize_t)(const char *str, unsigned int user, unsigned int len);

typedef void(*UI_DrawText_t)(const ScreenPlacement *screenPlacement, const char *text, int maxChars, uint64_t font, float x, float y, int horzAlign, int vertAlign, float scale, const float *color, int style, LocalClientNum_t localClientNum);
typedef void(*UI_FillRectPhysical_t)(float x, float y, float w, float h, const float *color);

typedef unsigned short(*sub_E9F770_t)(const char *str, unsigned int user, unsigned int u1);

//External
extern AimTarget_GetTagPos_t AimTarget_GetTagPos;
extern AimTarget_IsTargetVisible_t AimTarget_IsTargetVisible;

extern Cbuf_AddText_t Cbuf_AddText;

extern CG_CanSeeFriendlyHeadTrace_t CG_CanSeeFriendlyHeadTrace;
extern CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos;
extern CG_DrawRotatedPicPhysical_t CG_DrawRotatedPicPhysical;
//extern CG_TracePoint_t CG_TracePoint;

extern CL_DrawText_t CL_DrawText;

extern R_AddCmdDrawQuadPicW_t R_AddCmdDrawQuadPicW;

extern SL_GetStringOfSize_t SL_GetStringOfSize;

extern UI_DrawText_t UI_DrawText;
extern UI_FillRectPhysical_t UI_FillRectPhysical;

extern sub_E9F770_t sub_E9F770;

//Custom
extern void AimTarget_GetTagPos_Custom(int entNum, const char *tagName, float *pos);
extern bool AimTarget_IsTargetVisible_Custom(int targetEntNum, const char *visBone);

extern bool Dvar_GetBool(const char *dvarName);
extern const char *Dvar_GetString(const char *dvarName);

void Scr_SetNumParam(int paramcount);

#include "global.h"
NAMESPACE(Functions)

//Functions
void Init();

END
