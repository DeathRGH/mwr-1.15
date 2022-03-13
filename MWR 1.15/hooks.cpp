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

db_inflate_t db_inflate_Stub;

Scr_NotifyNum_t Scr_NotifyNum_Stub;

VM_Notify_t VM_Notify_Stub;

void CG_Draw2D_Hook(LocalClientNum_t localClientNum, float *rsi, float(*rdx)[3]) {
	CG_Draw2D_Stub(localClientNum, rsi, rdx);

	Menu::DrawMenu();
}

bool shouldWriteFile = false;
void db_inflate_Hook(void *rdi, int esi) {
	int fileHandle;
	register uint64_t r15 asm("r15");
	if (r15) {
		//uartprintf("\ndb_inflate_Hook r15: 0x%llX\n", r15);
		//uartprintf("db_inflate_Hook: %s\n", (char *)(*(uint64_t *)r15));
		//uartprintf("db_inflate_Hook: packed: 0x%llX, final: 0x%llX\n", *(int *)(r15 + 0x08), *(int *)(r15 + 0x0C));

		uint64_t strPtr = *(uint64_t *)r15;

		if (strPtr) {
			char fullFileName[1000];
			strcpy(fullFileName, (char *)(*(uint64_t *)r15));
			uartprintf("[MWR 1.15] db_inflate: %s\n", fullFileName);

			char folderBuffer[1000];
			strcpy(folderBuffer, "/data/dump");

			char *pch = strtok((char *)fullFileName, "/");

			while (pch != NULL) {
				snprintf(folderBuffer, sizeof(folderBuffer), "%s/%s", folderBuffer, pch);
				if (strstr(pch, (char *)".")) {
					int mode = O_CREAT | O_RDWR | O_TRUNC;
					fileHandle = syscall(5, folderBuffer, mode, 0777); //open
					shouldWriteFile = true;
					break;
				}
				else {
					pch = strtok(NULL, "/");
					syscall(136, folderBuffer, 0777); //mkdir
				}
			}
		}
	}

	db_inflate_Stub(rdi, esi);

	if (r15) {
		register uint64_t r14 asm("r14");
		if (r14 && shouldWriteFile) {
			syscall(4, fileHandle, r14, *(int *)(r15 + 0x0C)); //write
		}
	}
	shouldWriteFile = false;
}

void LUI_LuaCall_DebugPrint(lua_State *rdi) {
	HksObject *rsi = (HksObject *)(*(uint64_t *)((uint64_t)rdi + 0x50));
	unsigned long *rdx = (unsigned long *)((uint64_t)rdi + 0x48);

	if ((uint64_t)rsi < *(uint64_t *)((uint64_t)rdi + 0x48))
		rdx = 0;

	const char *ret = hks_obj_tolstring(rdi, rsi, rdx);
	LUI_Interface_DebugPrint("%s\n", ret);
}

void R_EndFrame_Hook() { //NOT UPDATED
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
		if (Host::Menu::Menu[entnum].magicBullet)
			Host::FireMagicBullet(entnum, MagicBulletProjectileForIndex(Host::Menu::Menu[entnum].magicBulletIndex));

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

		if (Host::Menu::Menu[entnum].unfairAimbot) {
			float playerAngles[3];
			playerAngles[0] = Host::Entity::GetEntityPtr(entnum)->client->angles[0];
			playerAngles[1] = Host::Entity::GetEntityPtr(entnum)->client->angles[1];
			playerAngles[2] = Host::Entity::GetEntityPtr(entnum)->client->angles[2];

			float forward[3];
			AngleVectors(playerAngles, forward, 0, 0);
			G_Damage(Host::Entity::GetEntityPtr(Host::ClosestClient(entnum)), Host::Entity::GetEntityPtr(entnum), Host::Entity::GetEntityPtr(entnum), forward, playerAngles, 100000, 0, MeansOfDeathForIndex(Host::Menu::Menu[entnum].aimbotMod), Host::Entity::GetEntityPtr(entnum)->client->weapon, false, 0, hitLocation_t::HITLOC_TORSO_UPR, 0, 84, 0);
		}

		if (Host::Menu::Menu[entnum].infiniteAmmo) {
			Add_Ammo((playerState_s *)Host::Entity::GetEntityPtr(entnum)->client, Host::Entity::GetEntityPtr(entnum)->client->weapon, false, 999, 1);
			Add_Ammo((playerState_s *)Host::Entity::GetEntityPtr(entnum)->client, Host::Entity::GetEntityPtr(entnum)->client->weapon, true, 999, 1);
		}
	}

	if (!strcmp(SL_ConvertToString(stringValue), "grenade_fire")) {
		if (Host::Menu::Menu[entnum].infiniteAmmo) {
			Add_Ammo((playerState_s *)Host::Entity::GetEntityPtr(entnum)->client, Host::Entity::GetEntityPtr(entnum)->client->lethalWeapon, false, 999, 1);
			Add_Ammo((playerState_s *)Host::Entity::GetEntityPtr(entnum)->client, Host::Entity::GetEntityPtr(entnum)->client->tacticalWeapon, false, 999, 1);
		}
	}

	Scr_NotifyNum_Stub(entnum, classnum, stringValue, paramcount);
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
			Cmd_RegisterNotification(spawnedClientIndex, "+gostand", "BTN_X");
			Cmd_RegisterNotification(spawnedClientIndex, "+usereload", "BTN_SQUARE");
			Cmd_RegisterNotification(spawnedClientIndex, "+frag", "BTN_R1");
			//Cmd_RegisterNotification(spawnedClientIndex, "+melee_zoom", "BUTTON_R3");

			Host::Menu::OnPlayerSpawned(spawnedClientIndex);
		}
		if (!strcmp(notifyString, "DPAD_UP")) {
			Host::Menu::ScrollUp(entityNum);

			//float pos[3] = { 0.0f, 0.0f, 1000000.0f };
			//gentity_s *ent = Host::Entity::SpawnScriptModel("com_plasticcase_green_big_us_dirt", pos);
			//gentity_s *collision = Host::Entity::FindCollision("pf1_auto1");//pf13_auto1
			//Host::Entity::CloneBrushModelToScriptModel(ent, collision);
			//Host::Entity::Solid(ent);
			//Host::Forge::clientCurrentEntity[entityNum] = ent;
		}
		if (!strcmp(notifyString, "DPAD_DOWN")) {
			Host::Menu::ScrollDown(entityNum);

			/*if (Host::Forge::clientCurrentEntity[entityNum] != 0)
				Host::Forge::clientCurrentEntity[entityNum] = 0;
			else
				Host::Forge::PickupEntity(Host::Entity::GetEntityPtr(entityNum))*/;
		}
		if (!strcmp(notifyString, "BTN_X")) {
			Host::Menu::Select(entityNum);
		}
		if (!strcmp(notifyString, "BTN_SQUARE")) {
			Host::Menu::GoBack(entityNum);
		}
		if (!strcmp(notifyString, "DPAD_LEFT")) {
			char temp[100];
			snprintf(temp, sizeof(temp), "f \"^3client: %i hit DPAD_LEFT\"", entityNum);
			SV_GameSendServerCommand(-1, svscmd_type::SV_CMD_RELIABLE, temp);
		}
		if (!strcmp(notifyString, "DPAD_RIGHT")) {
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
		if (!strcmp(notifyString, "weapon_inspection")) {
			if (Host::Menu::menuOpen[entityNum])
				return;
		}
	}

	VM_Notify_Stub(notifyListOwnerId, stringValue, top);
}

END
