#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Hooks)

typedef void(*CG_Draw2D_t)(LocalClientNum_t localClientNum, float *rsi, float(*rdx)[3]);
extern CG_Draw2D_t CG_Draw2D_Stub;

typedef void(*LUI_CoD_Render_t)(LocalClientNum_t, int);
extern LUI_CoD_Render_t LUI_CoD_Render_Stub;

typedef void(*LUIElement_Render_t)(LocalClientNum_t, void *, void *, void *, int, void *, float);
extern LUIElement_Render_t LUIElement_Render_Stub;

typedef void(*Scr_NotifyNum_t)(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount);
extern Scr_NotifyNum_t Scr_NotifyNum_Stub;

typedef void(*VM_Notify_t)(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top);
extern VM_Notify_t VM_Notify_Stub;

//

void CG_Draw2D_Hook(LocalClientNum_t localClientNum, float *rsi, float(*rdx)[3]);

void LUI_CoD_Render_Hook(LocalClientNum_t rdi, int rsi);
void LUI_LuaCall_DebugPrint(lua_State *);

void LUIElement_Render_Hook(LocalClientNum_t rdi, LUIElement *rsi, LUIElement *rdx, RootUserData *rcx, int r8d, lua_State *r9, float xmm0);

void R_EndFrame_Hook();

void Scr_NotifyNum_Hook(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount);

void VM_Notify_Hook(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top);

END
