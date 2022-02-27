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
	uartprintf("[AW 1.24] RgbThread() -> THREAD STARTED!\n");
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

	uartprintf("[AW 1.24] RgbThread() -> THREAD ENDED!\n");
}

void TestAllClientHuds() {
	HudElem_DestroyAll();
	game_hudelem_s *textTest = PrecacheElem(0x7FF);
	game_hudelem_s *testTypewriter = PrecacheElem(0x7FF);
	game_hudelem_s *testHud = PrecacheElem(0x7FF);

	Hud(testTypewriter).SetText("", 6, 1.0f, 300, 50, 5, 0, 10, 255, 255, 255, 255, 204, 0, 221, 255);
	Hud(testTypewriter).TypeWriterText("Typewriter text on AW 1.24");
	Hud(textTest).SetText("Testing all client text on AW", 6, 1.0f, 200, 150, 5, 0, 10, 255, 255, 255, 255, 204, 0, 221, 255);
	Hud(testHud).SetShader("white", 250, 50, 200, 150, 5, 0, 0, 0, 0, 0, 175);
}

void DetectGame() {
	if (!strcmp((char *)0x0000000000BFB355, "multiplayer")) {
		executionAddress = 0x0000000000D43FF0;
		NewRunID();
		Sleep(100);

		ScePthread thread1;
		scePthreadCreate(&thread1, NULL, (void *)RgbThread, NULL, "rgb_thread");
		ScePthread thread2;
		scePthreadCreate(&thread2, NULL, (void *)Menu::MonitorButtons, NULL, "monitorButtons_thread");
		ScePthread thread3;
		scePthreadCreate(&thread3, NULL, (void *)Menu::LoopSettings, NULL, "loopSettings_thread");
		ScePthread thread4;
		scePthreadCreate(&thread4, NULL, (void *)Host::Forge::MoveForgeEntities, NULL, "forgeMoveEntities_thread");

		char userName[20];
		sceUserServiceGetUserName(userId, userName, 20);

		char welcomeMessage[100];
		snprintf(welcomeMessage, sizeof(welcomeMessage), "Welcome %s!\n[AW 1.24] - Loaded\n\nHold  and press .", userName);
		sceSysUtilSendSystemNotificationWithText(222, welcomeMessage);

		Functions::Init();
		Menu::Init();

		//000000000B80C540 UI_Context
		//Menus_OpenByName((void *)0x000000000B80C540, "FriendsMenu");

		//TestAllClientHuds();

		//memcpy((void *)0x000000000090DFFE, "\x90\x90", 2); //enable FPS

		//restore ClientThink_real
		memcpy((void *)0x0000000000704320, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81\xE4\xE0\xFF\xFF\xFF", 20);
		Hooks::ClientThink_real_Stub = (Hooks::ClientThink_real_t)DetourFunction(0x0000000000704320, (void *)Hooks::ClientThink_real_Hook, 20);

		//restore LUI_CoD_Render
		memcpy((void *)0x00000000004F01B0, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x54\x53\x41\x89\xF6\x41\x89\xFF", 17);
		Hooks::LUI_CoD_Render_Stub = (Hooks::LUI_CoD_Render_t)DetourFunction(0x00000000004F01B0, (void *)Hooks::LUI_CoD_Render_Hook, 17);

		//restore LUIElement_Render
		memcpy((void *)0x00000000004D6EC0, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81\xEC\xD8\x00\x00\x00", 20);
		Hooks::LUIElement_Render_Stub = (Hooks::LUIElement_Render_t)DetourFunction(0x00000000004D6EC0, (void *)Hooks::LUIElement_Render_Hook, 20);

		//restore VM_Notify
		memcpy((void *)0x0000000000859090, "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81\xEC\x88\x00\x00\x00", 20);
		Hooks::VM_Notify_Stub = (Hooks::VM_Notify_t)DetourFunction(0x0000000000859090, (void *)Hooks::VM_Notify_Hook, 20);

		WriteJump(0x00000000004F0FD0, (uint64_t)Hooks::LUI_Interface_DebugPrint_Hook);
		WriteJump(0x0000000000A18320, (uint64_t)Hooks::R_EndFrame_Hook);
		WriteJump(0x0000000000766450, (uint64_t)Hooks::Scr_Notify_Hook);
		WriteJump(0x00000000007F6CC0, (uint64_t)Hooks::SV_Cmd_TokenizeString_Hook);

		//uint64_t assetHeader = DB_FindXAssetHeader(/*XAssetType::ASSET_TYPE_MAP_ENTS*/(XAssetType)0x1C, "maps/mp/mp_venus.d3dbsp", 0);
		//uartprintf("[AW 1.24] DB_FindXAssetHeader returned: 0x%llX\n", assetHeader);

		//PrintLoadedZones();
		//uartprintf("[AW 1.24] %s", Host::Entity::GetModelNameFromEntity(0));

		//float pos[3];
		//G_GetOrigin(LocalClientNum_t::LOCAL_CLIENT_0, 0, pos);
		//Host::Entity::SpawnScriptModel("dyn_ven_banners_tube_01_intct", pos);

		//GScr_MapRestart();
	}
	else {
		sceSysUtilSendSystemNotificationWithText(222, "Welcome to AW 1.24");
		OpenMessageDialog("AW 1.24\n\nWrong game or update version detected!\n\nSupported:\nCUSA00803 (Update 1.24)\nCUSA00851 (Update 1.24)");
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
