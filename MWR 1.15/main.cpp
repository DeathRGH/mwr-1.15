#include <stdint.h>
#include <stdarg.h>

#include "debug.h"
#include "defines.h"
#include "detour.h"
#include "functions.h"
#include "global.h"
#include "hooks.h"
#include "host.h"
#include "host_huds.h"
#include "imports.h"
#include "library_functions.h"
#include "menu.h"
#include "menuoptions.h"
#include "types.h"
#include "utility.h"

static int step;
void RgbThread() {
	uartprintf("[MWR 1.15] RgbThread() -> THREAD STARTED!\n");
	while (ShouldRun()) {
		float inc = 0.005f;//Menu::options.rgbFadingSpeed.current;

		if (step == 0)
			(rgbColor10[2] < (1.0f - inc * 2.0f)) ? rgbColor10[2] += inc : step = 1;
		if (step == 1)
			(rgbColor10[0] > (inc * 2.0f)) ? rgbColor10[0] -= inc : step = 2;
		if (step == 2)
			(rgbColor10[1] < (1.0f - inc * 2.0f)) ? rgbColor10[1] += inc : step = 3;
		if (step == 3)
			(rgbColor10[2] > (inc * 2.0f)) ? rgbColor10[2] -= inc : step = 4;
		if (step == 4)
			(rgbColor10[0] < (1.0f - inc * 2.0f)) ? rgbColor10[0] += inc : step = 5;
		if (step == 5)
			(rgbColor10[1] > (inc * 2.0f)) ? rgbColor10[1] -= inc : step = 0;

		UpdateRGB();
		Sleep(10);
	}

	uartprintf("[MWR 1.15] RgbThread() -> THREAD ENDED!\n");
}

void DetectGame() {
	if (!strcmp((char *)0x0000000000FA57FE, "multiplayer")) {
		executionAddress = 0x0000000001047FF0;
		NewRunID();
		Sleep(100);

		ScePthread thread1;
		scePthreadCreate(&thread1, NULL, (void *)RgbThread, NULL, "rgb_thread");
		ScePthread thread2;
		scePthreadCreate(&thread2, NULL, (void *)Menu::MonitorButtons, NULL, "monitorButtons_thread");
		///ScePthread thread3;
		///scePthreadCreate(&thread3, NULL, (void *)Menu::LoopSettings, NULL, "loopSettings_thread");
		///ScePthread thread4;
		///scePthreadCreate(&thread4, NULL, (void *)Host::Forge::MoveForgeEntities, NULL, "forgeMoveEntities_thread");

		char userName[20];
		sceUserServiceGetUserName(userId, userName, 20);

		char welcomeMessage[100];
		snprintf(welcomeMessage, sizeof(welcomeMessage), "Welcome %s!\n[MWR 1.15] - Loaded\n\nHold  and press .", userName);
		sceSysUtilSendSystemNotificationWithText(222, welcomeMessage);

		Functions::Init();
		Menu::Init();

		//memcpy((void *)0x0000000000A34E36, "\x90\x90\x90\x90\x90\x90", 6); //patch G_SetClientContents in ClientEndFrame
		//after this set g_client + 0x02

		///memcpy((void *)0x0000000000A34E2C, "\x41\x8B\x45\x02\x83\xF8\x02\x90\x90\x90", 10); //patch G_SetClientContents in ClientEndFrame
		//this patch works fine but crashes if loaded pre-game and you get into a match
		// =>
		//#
		//# A user thread receives a fatal signal
		//#
		//# signal: 11 (SIGSEGV)
		//# thread ID : 101107
		//# thread name : Server
		//# proc ID : 243
		//# proc name : default_mp.elf
		//# reason : page fault(user read data, page not present)
		//# fault address : 000000000000000f
		//#
		//# registers :
		//# rax : 0000000000000000  rbx : 00000007ee9d3b20
		//# rcx : 000000000f066960  rdx : 0000000002d08fb0
		//# rsi : 00000007ee9d3b20  rdi : 0000000000000000
		//# rbp : 00000007ee9d3f80  rsp : 00000007ee9d3420
		//# r8 : fffffff8206b7d20  r9 : 0000000000000009
		//# r10: 0000000000000010  r11 : 0000002001313d80
		//# r12 : 00000fbee3614d73  r13 : 0000000000000012
		//# r14 : 000000000f066960  r15 : 0000000000000000
		//# rip : 0000000000cd36cc  eflags : 00010246
		//# BrF : 000000000067c32f  BrT : 0000000000cd36c0
		//#
		//# backtrace :
		//copyin : Server has nonsleeping lock
		//# 0000000000bcd370
		//# 0000000800006d44
		//# 0000000000000000
		//#

		//restore CG_Draw2D
		memcpy((void *)0x00000000005EE8E0, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81\xEC\x38\x02\x00\x00", 20);
		Hooks::CG_Draw2D_Stub = (Hooks::CG_Draw2D_t)DetourFunction(0x00000000005EE8E0, (void *)Hooks::CG_Draw2D_Hook, 20);
		//possible hook 00000000007E3D50 LUIElement_Render
		//CG_Draw2D -> LUI_CoD_RunFrame -> LUI_CoD_Render -> LUI_Render -> LUIElement_Render

		// experimental hook for dumping raw/script files
		// all raw files are compressed with zlib 1.1.4
		// fast files are not compressed, only the inner files
		//
		///syscall(136, "/data/dump", 0777); //mkdir
		//restore db_inflate
		///memcpy((void *)0x0000000000E2F090, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x50\x48\x89\xFB", 17);
		///Hooks::db_inflate_Stub = (Hooks::db_inflate_t)DetourFunction(0x0000000000E2F090, (void *)Hooks::db_inflate_Hook, 17);
		
		//restore Scr_NotifyNum
		memcpy((void *)0x0000000000BE21D0, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x83\xEC\x18", 17);
		Hooks::Scr_NotifyNum_Stub = (Hooks::Scr_NotifyNum_t)DetourFunction(0x0000000000BE21D0, (void *)Hooks::Scr_NotifyNum_Hook, 17);

		//restore VM_Notify
		memcpy((void *)0x0000000000BE5020, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81\xEC\xD8\x04\x00\x00", 20);
		Hooks::VM_Notify_Stub = (Hooks::VM_Notify_t)DetourFunction(0x0000000000BE5020, (void *)Hooks::VM_Notify_Hook, 20);

		WriteJump(0x00000000007E07E0, (uint64_t)Hooks::LUI_LuaCall_DebugPrint);
		///WriteJump(0x0000000000A18320, (uint64_t)Hooks::R_EndFrame_Hook);

		//uint64_t assetHeader = DB_FindXAssetHeader(/*XAssetType::ASSET_TYPE_MAP_ENTS*/(XAssetType)0x1C, "maps/mp/mp_pipeline.d3dbsp", 0);
		//uartprintf("[MWR 1.15] DB_FindXAssetHeader returned: 0x%llX\n", assetHeader);

		//uint64_t assetHeader = DB_FindXAssetHeader(XAssetType::ASSET_TYPE_STRINGTABLE, "mp/botNodePatch.csv", 0);
		//uartprintf("[MWR 1.15] DB_FindXAssetHeader returned: 0x%llX\n", assetHeader);

		//const char *retVal = SL_ConvertToString((scr_string_t)1278);
		//uartprintf("[MWR 1.15] SL_ConvertToString returned: 0x%llX\n", retVal);

		///PrintLoadedZones();
		///uartprintf("[MWR 1.15] %s", Host::Entity::GetModelNameFromEntity(0));

		//GScr_MapRestart();

		Cbuf_AddText(LocalClientNum_t::LOCAL_CLIENT_0, "cg_fov 90");
		//scr_string_t cinematic = SL_GetString("hunted_load", 0);
		//char temp[100];
		//snprintf(temp, sizeof(temp), "9 \"%i\" 0", (int)cinematic);
		//SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);
	}
	else {
		sceSysUtilSendSystemNotificationWithText(222, "Welcome to MWR 1.15");
		OpenMessageDialog("MWR 1.15\n\nWrong game or update version detected!\n\nSupported:\nCUSA03522 (Update 1.15)");
		return;
	}
}

extern "C" void _main(void) {
	initImports();
	Sleep(100);

	SceUserServiceLoginUserIdList userIdList;
	sceUserServiceGetLoginUserIdList(&userIdList);

	for (int i = 0; i < 4; i++) {
		if (userIdList.userId[i] != -1) {
			userId = userIdList.userId[i];
			break;
		}
	}

	userPadHandle = scePadGetHandle(userId, 0, 0);

	DetectGame();
}

//notes:
//maps d3dbsp at 0x000000000B0FE848 most be something like inside level_locals_t

//0x000000000B0FE8B0 + 0x2C (level_locals_t) set compass objective (0x14 = lines)

//0000000000AD904D   lea r8, dword_1074AB8   inlined G_GetRandomSeed
