#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Hooks)

typedef void(*CG_Draw2D_t)(LocalClientNum_t localClientNum, float *rsi, float(*rdx)[3]);
extern CG_Draw2D_t CG_Draw2D_Stub;

typedef void(*db_inflate_t)(void *rdi, int esi);
extern db_inflate_t db_inflate_Stub;

typedef void(*Scr_NotifyNum_t)(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount);
extern Scr_NotifyNum_t Scr_NotifyNum_Stub;

typedef void(*VM_Notify_t)(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top);
extern VM_Notify_t VM_Notify_Stub;

//

void CG_Draw2D_Hook(LocalClientNum_t localClientNum, float *rsi, float(*rdx)[3]);

void db_inflate_Hook(void *rdi, int esi);

void LUI_LuaCall_DebugPrint(lua_State *);

void R_EndFrame_Hook();

void Scr_NotifyNum_Hook(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount);

void VM_Notify_Hook(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top);

END
