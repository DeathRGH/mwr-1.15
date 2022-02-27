#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Hooks)

typedef void(*ClientThink_real_t)(gentity_s *, usercmd_s *);
extern ClientThink_real_t ClientThink_real_Stub;

typedef void(*LUI_CoD_Render_t)(LocalClientNum_t, int);
extern LUI_CoD_Render_t LUI_CoD_Render_Stub;

typedef void(*LUIElement_Render_t)(LocalClientNum_t, void *, void *, void *, int, void *, float);
extern LUIElement_Render_t LUIElement_Render_Stub;

typedef void(*VM_Notify_t)(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top);
extern VM_Notify_t VM_Notify_Stub;

//

void ClientThink_real_Hook(gentity_s *ent, usercmd_s *ucmd);

void LUI_CoD_Render_Hook(LocalClientNum_t rdi, int rsi);
void LUI_Interface_DebugPrint_Hook(const char *fmt, ...);

void LUIElement_Render_Hook(LocalClientNum_t rdi, LUIElement *rsi, LUIElement *rdx, RootUserData *rcx, int r8d, lua_State *r9, float xmm0);

void R_EndFrame_Hook();

void Scr_Notify_Hook(gentity_s *ent, scr_string_t stringValue, unsigned int paramcount);

void SV_Cmd_TokenizeString_Hook(const char *text_in);

void VM_Notify_Hook(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top);

END
