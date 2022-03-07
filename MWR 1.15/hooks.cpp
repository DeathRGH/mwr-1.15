#include "hooks.h"

#include "cache.h"
#include "defines.h"
#include "functions.h"
#include "global.h"
#include "host.h"
#include "imports.h"
#include "menu.h"
#include "menuoptions.h"
#include "structs.h"
#include "utility.h"

NAMESPACE(Hooks)

CG_Draw2D_t CG_Draw2D_Stub;

LUI_CoD_Render_t LUI_CoD_Render_Stub;

LUIElement_Render_t LUIElement_Render_Stub;

Scr_NotifyNum_t Scr_NotifyNum_Stub;

VM_Notify_t VM_Notify_Stub;

void CG_Draw2D_Hook(LocalClientNum_t localClientNum, float *rsi, float(*rdx)[3]) {
	CG_Draw2D_Stub(localClientNum, rsi, rdx);

	Menu::DrawMenu();

	//DrawShader(1000.0f, 500.0f, 200.0f, 400.0f, black08);
	//DrawText("MWR 1.15 Test Text DeathRGH", 1000.0f, 500.0f, 1.0f, white10);
}

typedef void(*LUI_Interface_DrawRectangle_t)(LUIElement *, float x, float y, float width, float height, float, float, float, float, float, float, float, Material *, float *, LUI_QuadRenderMode, bool, lua_State *);
LUI_Interface_DrawRectangle_t LUI_Interface_DrawRectangle = (LUI_Interface_DrawRectangle_t)0x00000000004F2650;

typedef void(*LUI_Interface_DrawTextWithCursor_t)(LUIElement *, float, float, float, float, float, float, const char *, Font_s *, float, float, int, char, lua_State *);
LUI_Interface_DrawTextWithCursor_t LUI_Interface_DrawTextWithCursor = (LUI_Interface_DrawTextWithCursor_t)0x00000000004F3560;

typedef void(*LUI_Interface_DrawBoundingBox_t)(LUIElement *, lua_State *);
LUI_Interface_DrawBoundingBox_t LUI_Interface_DrawBoundingBox = (LUI_Interface_DrawBoundingBox_t)0x00000000004F2E90;

void LUI_CoD_Render_Hook(LocalClientNum_t rdi, int rsi) {
	LUI_CoD_Render_Stub(rdi, rsi);

	//LUIElement *rootElem = LUI_GetRootElement("UIRootFull", lua_state);
	//LUI_Interface_DrawLine(rootElem, 0.0f, 0.0f, 500.0f, 500.0f, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	//LUI_Interface_DrawLine(rootElem, 500.0f, 0.0f, 0.0f, 500.0f, 0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);

	//LUI_Interface_DrawTextWithCursor(rootElem, 100.0f, 100.0f, 10.0f, 10.0f, 10.0f, 10.0f, "LUI Test Text", R_RegisterFont("fonts/bodyFont", 0), 10.0f, 10.0f, 20, 0, lua_state);
	//LUI_Interface_DrawRectangle(rootElem, 100.0f, 200.0f, 300.0f, 500.0f, 100.0f, 200.0f, 100.0f, 200.0f, 300.0f, 400.0f, 600.0f, Material_RegisterHandle("white", 0), red10, (LUI_QuadRenderMode)0, true, lua_state);
}

void LUI_LuaCall_DebugPrint(lua_State *rdi) {
	HksObject *rsi = (HksObject *)(*(uint64_t *)((uint64_t)rdi + 0x50));
	unsigned long *rdx = (unsigned long *)((uint64_t)rdi + 0x48);

	if ((uint64_t)rsi < *(uint64_t *)((uint64_t)rdi + 0x48))
		rdx = 0;

	const char *ret = hks_obj_tolstring(rdi, rsi, rdx);
	LUI_Interface_DebugPrint("%s\n", ret);
}

void LUIElement_Render_Hook(LocalClientNum_t rdi, LUIElement *rsi, LUIElement *rdx, RootUserData *rcx, int r8d, lua_State *r9, float xmm0) {
	LUIElement_Render_Stub(rdi, rsi, rdx, rcx, r8d, r9, xmm0);
	//uartprintf("0x%llX, 0x%llX, 0x%llX, 0x%llX\n", rsi, rdx, rcx, r9);

	//LUIElement *rootElem = LUI_GetRootElement("UIRootFull", r9);
	//LUI_Interface_DrawLine(rootElem, 0.0f, 0.0f, 500.0f, 500.0f, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	//LUI_Interface_DrawLine(rootElem, 500.0f, 0.0f, 0.0f, 500.0f, 0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	
	//LUI_Interface_DrawBoundingBox(rootElem, r9);

	//LUI_Interface_DrawTextWithCursor(rootElem, 100.0f, 100.0f, 10.0f, 10.0f, 10.0f, 10.0f, "LUI Test Text", R_RegisterFont("fonts/bodyFont", 0), 10.0f, 10.0f, 20, 0, r9);

	//((void(*)(LUIElement *, float x, float y, float, float, float, float, float, float, float, float, float, Material *, float *, LUI_QuadRenderMode, bool, lua_State *))0x00000000004F2CA0)(rsi, 100.0f, 100.0f, 300.0f, 200.0f, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, );
	//LUI_Interface_DrawRectangle(rootElem, 100.0f, 200.0f, 300.0f, 200.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, Material_RegisterHandle("white", 0), red10, (LUI_QuadRenderMode)0, true, r9);
}

void R_EndFrame_Hook() {
	Menu::DrawMenu();

	//Font_s *newFont = R_RegisterFont("fonts/titleFont", 0);
	//DrawText(newFont->name, 500.0f, 500.0f, 1.0f, white10, newFont);

	//Material *newMaterial = Material_RegisterHandle("white", 0);
	//DrawText(newMaterial->name, 500.0f, 300.0f, 1.0f, white10, newFont);

	//DrawShader(500.0f, 650.0f, 600.0f, 100.0f, black08);
	//DrawTextWithGlow("Glowing Text", 500.0f, 750.0f, 1.0f, white10, cyan10);

	//DrawCenterTextWithBackground("ooo O ooo", 1920 / 2, 1080 / 2, 0.4f, white10, black05);
	//DrawShader(1920 / 2 - 2, 1080 / 2 - 2, 4.0f, 4.0f, cyan10);


	//reversed below
	R_GetCommandBuffer((GfxRenderCommand)0, 4);
	*(uint64_t *)((*(uint64_t *)(*(uint64_t *)0x000000000CA50200 + 0x546A40)) + 0x18) = 0;
	*(uint64_t *)((*(uint64_t *)(*(uint64_t *)0x000000000CA50200 + 0x546A40)) + 0x10) = 0;
	*(uint64_t *)((*(uint64_t *)(*(uint64_t *)0x000000000CA50200 + 0x546A40)) + 0x08) = 0;
	*(int *)(0x000000000C9C2400 + 0xD08) = 0;
	*(int *)0x000000000E35B2A4 = (*(int *)0x000000000E35B2A4 & 1) ^ 1;
}

void Scr_NotifyNum_Hook(int entnum, unsigned int classnum, scr_string_t stringValue, unsigned int paramcount) {
	if (!strcmp(SL_ConvertToString(stringValue), "weapon_fired")) {
		//SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, "f \"weapon_fired\"");
		if (Menu::Options.host_magicBullet.state)
			Host::FireMagicBullet(entnum, MagicBulletProjectileForIndex(Menu::Options.host_magicBulletProjectileIndex.current));

		//float newPos[3] = { 0.0f, 0.0f, 0.0f };
		//Scr_AddVector(newPos);
		//Scr_SetNumParam(1);
		//PlayerCmd_setOrigin(**(short *)ent);

		//Scr_AddInt(1);
		//Scr_AddString("cg_fov");
		//Scr_AddString("120");
		//Scr_SetNumParam(3);
		//PlayerCmd_SetClientDvar(*(short *)ent);

		//Scr_AddInt(0);
		//Scr_SetNumParam(1);
		//PlayerCmd_ForceMantle(*(short *)ent);

		//float playerPos[3];
		//playerPos[0] = Host::Entity::GetEntityPtr(entnum)->origin[0];
		//playerPos[1] = Host::Entity::GetEntityPtr(entnum)->origin[1];
		//playerPos[2] = Host::Entity::GetEntityPtr(entnum)->origin[2];
		//gentity_s *scriptModel = Host::Entity::SpawnScriptModel("rat", playerPos);//com_plasticcase_beige_big

		//not working yet
		//Scr_AddConstString(0);
		//Scr_AddInt(20);
		//Scr_AddString("animated_rat"); //h1_mp_rat_frantic_idle //frantic //animated_rat_frantic //animated_rat
		//Scr_SetNumParam(2);
		//ScriptEntCmd_ScriptModelPlayAnim(scriptModel->number);

		//gentity_s *collision = Host::Entity::FindCollision("pipe_shootable");//pf1958_auto1
		//
		//if (collision) {
		//	Scr_AddEntity(collision);
		//	Scr_SetNumParam(1);
		//	ScriptEntCmd_CloneBrushModelToScriptModel(scriptModel->number);
		//	ScriptEntCmd_Solid(scriptModel->number);
		//}

		//NOT TESTED:
		float playerAngles[3];
		playerAngles[0] = *(float*)((0 * 0x5780) + 0xB2FA880 + 0x12C);
		playerAngles[1] = *(float*)((0 * 0x5780) + 0xB2FA880 + 0x12C + 4);
		playerAngles[2] = *(float*)((0 * 0x5780) + 0xB2FA880 + 0x12C + 8);

		float forward[3];
		AngleVectors(playerAngles, forward, 0, 0);
		///G_Damage(Host::Entity::GetEntityPtr(1), Host::Entity::GetEntityPtr(0), Host::Entity::GetEntityPtr(0), forward, playerAngles, 0x186A0, 0, 0, G_GetWeaponForName("bomb_site_mp"), 0, 0, hitLocation_t::HITLOC_R_LEG_LWR, 0, 84, 0);
	}

	Scr_NotifyNum_Stub(entnum, classnum, stringValue, paramcount);
}

void SV_Cmd_TokenizeString_Hook(const char *text_in) {
	//char temp[100];
	//snprintf(temp, sizeof(temp), "f \"^5%s\"", text_in);
	//SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);

	//if (!strcmp(text_in, SV_CMD_R1_DOWN))
		//*(char *)(0x000000000659C180 + 0x5370) ^= 1;

	//reversed below
	Cmd_TokenizeStringKernel(text_in, 0x200 - *(int *)0x0000000009A4C820, (CmdArgs *)0x0000000009A224E8, (CmdArgsPrivate *)0x0000000009A47800);
}

void VM_Notify_Hook(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue *top) {
	if (true) {
		const char *notifyString = SL_ConvertToString(stringValue);
		int entityNum = Scr_GetSelf(notifyListOwnerId);

		if (!strcmp(notifyString, "player_spawned")) {
			int spawnedClientIndex = Scr_GetSelf(top->u.entityOffset);

			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^2spawnedClientIndex: %i\"", spawnedClientIndex);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);

			SV_GameSendServerCommand(spawnedClientIndex, svscmd_type::SV_CMD_RELIABLE, "f \"Press \x0017 ^7to ^2open ^7the menu.\"");

			Cmd_RegisterNotification(spawnedClientIndex, "+actionslot 1", "DPAD_UP");
			Cmd_RegisterNotification(spawnedClientIndex, "+actionslot 2", "DPAD_DOWN");
			Cmd_RegisterNotification(spawnedClientIndex, "+actionslot 3", "DPAD_LEFT");
			Cmd_RegisterNotification(spawnedClientIndex, "+actionslot 4", "DPAD_RIGHT");
			Cmd_RegisterNotification(spawnedClientIndex, "+frag", "BTN_R1");
			//Cmd_RegisterNotification(spawnedClientIndex, "+gostand", "BUTTON_X");
			//Cmd_RegisterNotification(spawnedClientIndex, "+usereload", "BUTTON_SQUARE");
			//Cmd_RegisterNotification(spawnedClientIndex, "+melee_zoom", "BUTTON_R3");

			Host::Menu::OnPlayerSpawned(spawnedClientIndex);
		}
		if (!strcmp(notifyString, "DPAD_UP")) {
			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^3client: %i hit DPAD_UP\"", entityNum);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);

			//float pos[3] = { 0.0f, 0.0f, 1000000.0f };
			//gentity_s *ent = Host::Entity::SpawnScriptModel("com_plasticcase_green_big_us_dirt", pos);
			//gentity_s *collision = Host::Entity::FindCollision("pf1_auto1");//pf13_auto1
			//Host::Entity::CloneBrushModelToScriptModel(ent, collision);
			//Host::Entity::Solid(ent);
			//Host::Forge::clientCurrentEntity[entityNum] = ent;
		}
		if (!strcmp(notifyString, "DPAD_DOWN")) {
			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^3client: %i hit DPAD_DOWN\"", entityNum);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);

			/*if (Host::Forge::clientCurrentEntity[entityNum] != 0)
				Host::Forge::clientCurrentEntity[entityNum] = 0;
			else
				Host::Forge::PickupEntity(Host::Entity::GetEntityPtr(entityNum))*/;
		}
		if (!strcmp(notifyString, "DPAD_LEFT")) {
			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^3client: %i hit DPAD_LEFT\"", entityNum);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);
		}
		if (!strcmp(notifyString, "DPAD_RIGHT")) {
			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^3client: %i hit DPAD_RIGHT\"", entityNum);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);

			Host::Menu::OpenCloseMenu(entityNum);

			/*if (Host::Forge::clientCurrentEntity[entityNum] != 0)
				G_FreeEntity(Host::Forge::clientCurrentEntity[entityNum]);
			else
				Host::Forge::DeleteEntity(Host::Entity::GetEntityPtr(entityNum));

			Host::Forge::clientCurrentEntity[entityNum] = 0;*/
		}
		if (!strcmp(notifyString, "BTN_R1")) {
			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^3client: %i hit BTN_R1\"", entityNum);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);
			
			//*(char *)(gclient_t + 0x5370 + (entityNum * gclient_size)) ^= 1;
			///Host::Entity::ToggleNoclip(entityNum);
			///SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, Host::Entity::GetEntityPtr(entityNum)->client->mFlag[0] == 2 ? "f \"Noclip [^2ON^7]\"" : "f \"Noclip [^1OFF^7]\"");

			//float playerPos[3];
			//playerPos[0] = Host::Entity::GetEntityPtr(entityNum)->origin[0];
			//playerPos[1] = Host::Entity::GetEntityPtr(entityNum)->origin[1];
			//playerPos[2] = Host::Entity::GetEntityPtr(entityNum)->origin[2];
			//Host::Entity::SpawnScriptModel("com_plasticcase_beige_big", playerPos);
			//should try to use the script cmd for cloning here as it at most pushes 2 ents

			//gentity_s *collision = Host::Entity::FindCollision("pf1958_auto1");
		}
	}

	VM_Notify_Stub(notifyListOwnerId, stringValue, top);
}

END
