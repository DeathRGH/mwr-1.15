#include "host.h"

#include "cache.h"
#include "functions.h"
#include "imports.h"
#include "utility.h"

NAMESPACE(Host)

void AddFriendlyBot() {
	if ((*(char *)(0x00000000148BAAF0 + 0x0F) + *(char *)(0x00000000148BAAF0 + 0x10)) < 17)
		(*(char *)(0x00000000148BAAF0 + 0x0F))++;
}

void RemoveFriendlyBot() {
	if (*(char *)(0x00000000148BAAF0 + 0x0F) > 0)
		(*(char *)(0x00000000148BAAF0 + 0x0F))--;
}

void AddEnemyBot() {
	if((*(char *)(0x00000000148BAAF0 + 0x0F) + *(char *)(0x00000000148BAAF0 + 0x10)) < 17)
		(*(char *)(0x00000000148BAAF0 + 0x10))++;
}

void RemoveEnemyBot() {
	if (*(char *)(0x00000000148BAAF0 + 0x10) > 0)
		(*(char *)(0x00000000148BAAF0 + 0x10))--;
}

void FireMagicBullet(short entNum, const char *projectile) {
	float playerAngles[3];
	playerAngles[0] = *(float *)((entNum * gclient_size) + gclient_t + 0x12C);
	playerAngles[1] = *(float *)((entNum * gclient_size) + gclient_t + 0x12C + 4);
	playerAngles[2] = *(float *)((entNum * gclient_size) + gclient_t + 0x12C + 8);

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);
	//forward[0] *= 999999999.0f;
	//forward[1] *= 999999999.0f;
	//forward[2] *= 999999999.0f;

	float viewOrigin[3];
	viewOrigin[0] = *(float *)((entNum * gclient_size) + gclient_t + 0x78);
	viewOrigin[1] = *(float *)((entNum * gclient_size) + gclient_t + 0x78 + 4);
	viewOrigin[2] = *(float *)((entNum * gclient_size) + gclient_t + 0x78 + 8) + 65.0f;
	//G_DObjGetWorldTagPos((gentity_s *)0x00000000064293D0 + (entNum * 0x2E0), SL_GetString("tag_weapon_right", 0), startPos);

	float startPos[3];
	startPos[0] = viewOrigin[0] + forward[0] * 50.0f;
	startPos[1] = viewOrigin[1] + forward[1] * 50.0f;
	startPos[2] = viewOrigin[2] + forward[2] * 50.0f;

	forward[0] *= 999999999.0f;
	forward[1] *= 999999999.0f;
	forward[2] *= 999999999.0f;

	Scr_AddVector(forward);
	Scr_AddVector(startPos);
	Scr_AddString(projectile);
	Scr_SetNumParam(3);

	Scr_MagicBullet();
}

int BulletTrace(float *start, float *end, unsigned short *entityId) { //NOT UPDATED
	char trace[0x200];//trace_t *trace;
	G_LocationalTrace(trace, start, end, 0, 0x280E831, 0);

	unsigned short id = Trace_GetEntityHitId(trace);
	if (entityId) {
		if (id < 0x7FE)
			*entityId = id;
		else {
			*entityId = 0;
			return 1;
		}
	}

	return 0;
}

int ClosestClient(int i) {
	int closestClientNum = -1;
	float distance[MAX_CLIENTS];
	float min = 1234567890123456789024.0f;
	for (int j = 0; j < MAX_CLIENTS; j++)
		distance[j] = min;

	for (int j = 0; j < MAX_CLIENTS; j++) {
		if (!Host::Entity::IsAlive(j))
			continue;
		//this needs a gametype check for dm
		if (Host::Entity::GetEntityPtr(j)->client->team == Host::Entity::GetEntityPtr(i)->client->team)
			continue;

		distance[j] = Distance(Host::Entity::GetEntityPtr(j)->client->origin, Host::Entity::GetEntityPtr(i)->client->origin);
	}

	for (int j = 0; j < MAX_CLIENTS; j++) {
		if (distance[j] < min) {
			min = distance[j];
			closestClientNum = j;
		}
	}

	return closestClientNum;
}

int trophyClient = 0;
void UnlockAllTrophies_Internal() {
	int trophyClientInternal = trophyClient;
	const char trophies[50][100] = {
		"4 EARN_A_WINGED_DAGGER",
		"4 MAKE_THE_JUMP",
		"4 DANCING_IN_THE_DARK",
		"4 SAVE_THE_BACON",
		"4 DEATH_FROM_ABOVE",
		"4 WRONG_NUMBER",
		"4 PIGGYBACK_RIDE",
		"4 DESPERATE_MEASURES",
		"4 CAMPAIGN_COMPLETE",
		"4 LOOK_SHARP",
		"4 EYES_AND_EARS",
		"4 DOWN_BOY_DOWN",
		"4 NEW_SQUADRON_RECORD",
		"4 RESCUE_ROYCEWICZ",
		"4 YOUR_SHOW_SUCKS",
		"4 MAN_OF_THE_PEOPLE",
		"4 STRAIGHT_FLUSH",
		"4 GHILLIES_IN_THE_MIST",
		"4 MILE_HIGH_CLUB",
		"4 NO_REST_FOR_THE_WEARY",
		"4 DEEP_AND_HARD",
		"4 THE_PACKAGE",
		"4 THE_RESCUE",
		"4 THE_SEARCH",
		"4 THE_BOG",
		"4 THE_ESCAPE",
		"4 THE_FIRST_HORSEMAN",
		"4 THE_SECOND_HORSEMAN",
		"4 THE_SHOT",
		"4 THE_THIRD_HORSEMAN",
		"4 THE_ULTIMATUM",
		"4 THE_FOURTH_HORSEMAN",
		"4 DAREDEVIL",
		"4 ROADKILL",
		"4 BIRD_ON_THE_GROUND",
		"4 FOUR_OF_A_KIND",
		"4 THREE_OF_A_KIND",
		"4 TIME_PARADOX",
		"4 WEAPON_MASTER",
		"4 FLYSWATTER",
		"4 DESERT_STORM",
		"4 MASTER_NINJA",
		"4 DOGS_I_HATE_DOGS",
		"4 THE_MAN_IN_THE_HIGH_TOWER",
		"4 FEEL_THE_HEAT",
		"4 RETRO_SHOOTER",
		"4 BEST_OF_THE_BEST",
		"4 MAN_VERSUS_MACHINE",
		"4 REINFORCEMENT_DENIED",
		"4 EXPLOSION_MAN"
	};

	for (int j = 0; j < 50; j++) {
		SV_GameSendServerCommand(trophyClientInternal, svscmd_type::SV_CMD_RELIABLE, trophies[j]);
		Sleep(50);
		SV_GameSendServerCommand(trophyClientInternal, svscmd_type::SV_CMD_RELIABLE, trophies[j]);
		Sleep(50);
		char temp[100];
		snprintf(temp, sizeof(temp), j == 49 ? "c \"Trophy [^2%i^7/^250^7] Unlocked\"" : "c \"Trophy [^3%i^7/^250^7] Unlocked\"", j + 1);
		SV_GameSendServerCommand(trophyClientInternal, svscmd_type::SV_CMD_RELIABLE, temp);
		Sleep(1000);
	}

	Menu::Menu[trophyClientInternal].isUnlockingTrophies = false;
}

void UnlockAllTrophies(int i) {
	if (Menu::Menu[i].isUnlockingTrophies) {
		SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "f \"^1Already unlocking trophies...\"");
		return;
	}

	Menu::Menu[i].isUnlockingTrophies = true;
	trophyClient = i;
	ScePthread trophyThread;
	scePthreadCreate(&trophyThread, NULL, (void *)UnlockAllTrophies_Internal, NULL, "trophyUnlock_thread");
}

void PrintCoordinates(int i) {
	char temp[100];
	snprintf(temp, sizeof(temp), "c \"%.2f, %.2f, %.2f\"", Entity::GetEntityPtr(i)->client->origin[0], Entity::GetEntityPtr(i)->client->origin[1], Entity::GetEntityPtr(i)->client->origin[2]);
	SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, temp);
}

void SavePosition(int i) {
	Menu::Menu[i].savedPosition[0] = Entity::GetEntityPtr(i)->client->origin[0];
	Menu::Menu[i].savedPosition[1] = Entity::GetEntityPtr(i)->client->origin[1];
	Menu::Menu[i].savedPosition[2] = Entity::GetEntityPtr(i)->client->origin[2];

	SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"Position: ^2Saved\"");
}

void LoadPosition(int i) {
	if (!Menu::Menu[i].savedPosition) {
		SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Save a position first!\"");
		return;
	}

	Entity::GetEntityPtr(i)->client->origin[0] = Menu::Menu[i].savedPosition[0];
	Entity::GetEntityPtr(i)->client->origin[1] = Menu::Menu[i].savedPosition[1];
	Entity::GetEntityPtr(i)->client->origin[2] = Menu::Menu[i].savedPosition[2];

	SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"Position: ^2Loaded\"");
}

void TeleportUp(int i, float addition) {
	Entity::GetEntityPtr(i)->client->origin[2] += addition;
}

NAMESPACE(Lobby)

void Godmode(bool state) { //NOT UPDATED
	memcpy((void *)0x00000000007138BA, state ? "\x90\x90\x90\x90\x90\x90\x90" : "\x45\x29\xA7\xD0\x01\x00\x00", 7);
}

void InfiniteAmmo(bool state) { //NOT UPDATED
	memcpy((void *)0x00000000005768EF, state ? "\x90\x90\x90\x90\x90" : "\x44\x29\x7C\x81\x08", 5);
}

END
NAMESPACE(Entity)

gentity_s *GetEntityPtr(int i) {
	return (gentity_s *)(gentity_t + (i * gentity_size));
}

bool IsAlive(int i) {
	return GetEntityPtr(i)->health > 0;
}

void ToggleNoclip(int i) {
	GetEntityPtr(i)->client->mFlag0[1] = 0;
	GetEntityPtr(i)->client->mFlag0[2] = 0;
	GetEntityPtr(i)->client->mFlag0[3] = 0;
	GetEntityPtr(i)->client->mFlag0[0] ^= 2;
}

gentity_s *SpawnScriptModel(const char *modelName, float *origin) {
	gentity_s *entity = G_Spawn();
	if (entity) {
		if (modelName)
			G_SetModel(entity, modelName);

		if (origin)
			G_SetOrigin(entity, origin);

		//entity->spawnflags = 0;
		SP_script_model(entity);
	}

	return entity;
}

void CloneBrushModelToScriptModel(gentity_s *scriptModel, gentity_s *brushModel) { //NOT UPDATED
	if (!scriptModel || !brushModel)
		return;

	SV_UnlinkEntity(scriptModel);
	*(int *)((uint8_t *)scriptModel + 0x10) = *(int *)((uint8_t *)brushModel + 0x10); //ScriptEntCmd_CloneBrushModelToScriptModel + 0xA8   mov eax, [r14+10h]
	*(uint8_t *)((uint8_t *)scriptModel + 0x101) = 4; //ScriptEntCmd_CloneBrushModelToScriptModel + 0xAF   mov byte ptr [rbx+101h], 4
	int contents = *(int *)((uint8_t *)scriptModel + 0x11C); //ScriptEntCmd_CloneBrushModelToScriptModel + 0xB6   mov r14d, [rbx+11Ch]
	SV_SetBrushModel(scriptModel);
	*(int *)((uint8_t *)scriptModel + 0x11C) |= contents; //ScriptEntCmd_CloneBrushModelToScriptModel + 0xC5   or [rbx+11Ch], r14d
	SV_LinkEntity(scriptModel);
}

int Solid(gentity_s *ent) { //NOT UPDATED
	int *scrconst = (int *)scr_const;
	int classname = ent->classname;
	if (classname != *(scrconst + 0x57)) { //ScriptEntCmd_Solid + 0x6C   cmp eax, [rcx+15Ch]   (0x15C / 4)
		if (classname == *(scrconst + 0x56)) { //ScriptEntCmd_Solid + 0x7B   cmp eax, [rcx+158h]   (0x158 / 4)
			*(int *)((uint8_t *)ent + 0x11C) = 0x2080; //ScriptEntCmd_Solid + 0x83   mov dword ptr [rbx+11Ch], 2080h
		}
		else {
			*(int *)((uint8_t *)ent + 0x11C) = 1; //ScriptEntCmd_Solid + 0x8F   mov dword ptr [rbx+11Ch], 1
			*(uint8_t *)((uint8_t *)ent + 0x58) &= 0xFE; //ScriptEntCmd_Solid + 0x99   and byte ptr [rbx+58h], 0FEh
		}

		SV_LinkEntity(ent);
		return 0;
	}
	else
		return 1;
}

gentity_s *FindCollision(const char *name) { //NOT UPDATED
	for (int i = 0; i < 2048; i++) {
		gentity_s *ent = GetEntityPtr(i);
		// check if it is a brushmodel
		if (*(uint8_t *)((uint8_t *)ent + 0x101) == 4) {
			const char *targetname = SL_ConvertToString(ent->targetname);
			uartprintf("[MWR 1.15] FindCollision(%s) -> %i %s\n", name, i, targetname);
			if (targetname) {
				// see d3dbsp files for maps
				if (!strcmp(targetname, name)) {
					uartprintf("[MWR 1.15] FindCollision(%s) -> 0x%llX (%i): %s\n", name, ent, i, targetname);
					return ent;
				}
			}
		}
	}

	uartprintf("[MWR 1.15] FindCollision(%s) -> Collision for \"%s\" not found!\n", name, name);
	return 0;
}

const char *GetModelNameFromEntity(int i) {
	gentity_s *ent = GetEntityPtr(i);

	unsigned int modelNameIndex = G_ModelName(ent->modelIndex);
	return SL_ConvertToString((scr_string_t)modelNameIndex);
}

const char *GetModelNameFromEntity(gentity_s *ent) {
	unsigned int modelNameIndex = G_ModelName(ent->modelIndex);
	return SL_ConvertToString((scr_string_t)modelNameIndex);
}

END
NAMESPACE(Menu)

MenuStruct Menu[MAX_MENU_CLIENTS];

bool menuOpen[MAX_MENU_CLIENTS];
int menuScroll[MAX_MENU_CLIENTS];
int menuSize[MAX_MENU_CLIENTS];
hostSub menuSub[MAX_MENU_CLIENTS];
int menuDepth[MAX_MENU_CLIENTS];
hostSub menuLastSub[MAX_MENU_CLIENTS][MAX_MENU_DEPTH];
char menuText[MAX_MENU_CLIENTS][MAX_MENU_OPTIONS][128];

game_hudelem_s *background[MAX_MENU_CLIENTS];
game_hudelem_s *header[MAX_MENU_CLIENTS];
game_hudelem_s *options[MAX_MENU_CLIENTS][MAX_MENU_OPTIONS];

void UpdateMenu(int i, hostSub subMenu, int maxScroll, const char *headerText, ...) {
	if (menuSub[i] != subMenu) {
		if (subMenu == hostSub::SUB_NONE)
			menuDepth[i] = 0;
		else {
			menuLastSub[i][menuDepth[i]] = menuSub[i];

			if (menuDepth[i] > 1) {
				if (menuLastSub[i][menuDepth[i] - 1] == subMenu)
					menuDepth[i]--;
				else
					menuDepth[i]++;
			}
			else
				menuDepth[i]++;
		}
	}

	for (int j = 0; j < MAX_MENU_OPTIONS; j++)
		strcpy(menuText[i][j], "");

	va_list list;
	va_start(list, maxScroll);
	for (int j = 0; j < maxScroll; j++) {
		char *temp = va_arg(list, char *);
		strcpy(menuText[i][j], temp);
	}
	va_end(list);

	menuSub[i] = subMenu;
	menuSize[i] = maxScroll;
	Hud(header[i]).ChangeText(headerText);

	Hud(options[i][menuScroll[i]]).ScaleTextOverTime(0, 0.5f);
	Hud(options[i][menuScroll[i]]).FadeOverTime(0, 255, 255, 255, 255);
	menuScroll[i] = 0;
	Hud(options[i][0]).ScaleTextOverTime(100, 0.6f);
	Hud(options[i][0]).FadeOverTime(250, 255, 0, 0, 255);

	for (int j = 0; j < MAX_MENU_OPTIONS; j++)
		Hud(options[i][j]).ChangeText(menuText[i][j]);

	if (!menuOpen[i])
		return;

	for (int j = 0; j < MAX_MENU_OPTIONS; j++)
		Hud(options[i][j]).MoveOverTime(0, 1000.0f, 100.0f + (j * 15.0f));
	for (int j = 0; j < MAX_MENU_OPTIONS; j++)
		Hud(options[i][j]).MoveOverTime(250 + (j * 50), 600.0f, 100.0f + (j * 15.0f));
}

void SwitchToMainMenu(int i) {
	UpdateMenu(i, hostSub::SUB_NONE, 12, "MWR 1.15", "Self Menu", "Lobby Menu", "Weapon Menu", "Clients", "All Clients", "Teleport Menu", "Aimbot Menu", "Projectile Menu", "Sub Menu 9", "Sub Menu 10", "Sub Menu 11", "Sub Menu 12");
}

void SwitchMenu(int i, hostSub subMenu) {
	switch (subMenu) {
		case hostSub::SUB_NONE:
			SwitchToMainMenu(i);
			break;
		case hostSub::SUB_SELF:
			UpdateMenu(i, hostSub::SUB_SELF, 4, "Self Menu", "Godmode", "Infinite Ammo", "2x Movement Speed", "Unlock All Trophies");
			break;
		case hostSub::SUB_LOBBY:
			UpdateMenu(i, hostSub::SUB_LOBBY, 8, "Lobby Menu", "Godmode", "Infinite Ammo", "Super Jump", "Add Friendly Bot", "Remove Friendly Bot", "Add Enemy Bot", "Remove Enemy Bot", "Restart Match");
			break;
		case hostSub::SUB_WEAPONS:
			UpdateMenu(i, hostSub::SUB_WEAPONS, 5, "Weapon Menu", "h1_ak47_mp", "h1_fal_mp", "h1_pp2000_mp", "h1_striker_mp", "h1_deserteagle55_mp");
			break;
		case hostSub::SUB_CLIENTS:
			UpdateMenu(i, hostSub::SUB_CLIENTS, 4, "Clients Menu", "Client 0", "Client 1", "Client 2", "Client 3");
			break;
		case hostSub::SUB_ALLCLIENTS:
			UpdateMenu(i, hostSub::SUB_ALLCLIENTS, 4, "All CLients", "Unverify All", "Verify All", "All Client Godmode", "All Client Infinite Ammo");
			break;
		case hostSub::SUB_TELEPORT:
			UpdateMenu(i, hostSub::SUB_TELEPORT, 7, "Teleport Menu", "Print Coordinates", "Save Position", "Load Position", "Teleport Up 100", "Teleport Up 1000", "Teleport Down 1000", "Teleport Down 100");
			break;
		case hostSub::SUB_AIMBOT:
			UpdateMenu(i, hostSub::SUB_AIMBOT, 2, "Aimbot Menu", "Unfair Aimbot", "Toggle Means Of Death");
			break;
		case hostSub::SUB_PROJECTILE:
			UpdateMenu(i, hostSub::SUB_PROJECTILE, 2, "Projectile Menu", "Magic Bullet", "Set RPG");
			break;
		default:
			break;
	}
}

void OnPlayerSpawned(int i) {
	menuOpen[i] = false;
	menuScroll[i] = 0;
	menuSub[i] = hostSub::SUB_NONE;
	menuDepth[i] = 0;
	for (int j = 0; j < 5; j++)
		menuLastSub[i][j] = hostSub::SUB_NONE;

	HudElem_DestroyClient(i);

	background[i] = PrecacheElem(i);
	Hud(background[i]).SetShader("white", 200, 1000, 1000.0f, 200.0f, 5, 0, 0.0f, 0, 0, 0, 175);

	header[i] = PrecacheElem(i);
	Hud(header[i]).SetText("MWR 1.15", 1, 0.75f, 1000.0f, 70.0f, 5, 0, 10.0f, 255, 255, 255, 255, 255, 0, 0, 127);

	for (int j = 0; j < MAX_MENU_OPTIONS; j++) {
		options[i][j] = PrecacheElem(i);
		Hud(options[i][j]).SetText("Option", 1, 0.5f, 1000.0f, 100.0f + (j * 15.0f), 5, 0, 10.0f, 255, 255, 255, 255, 0, 0, 0, 0);
	}
	Hud(options[i][0]).SetText("Option", 1, 0.6f, 1000.0f, 100.0f, 5, 0, 10.0f, 255, 0, 0, 255, 0, 0, 0, 0);

	SwitchToMainMenu(i);
}

void OpenCloseMenu(int i) {
	if (!background[i] || !header[i])
		return;

	if (menuOpen[i]) {
		Entity::GetEntityPtr(i)->client->mflag &= ~4;

		Hud(background[i]).MoveOverTime(250, 1000.0f, 200.0f);
		Hud(header[i]).MoveOverTime(250, 1000.0f, 70.0f);
		for (int j = 0; j < MAX_MENU_OPTIONS; j++)
			Hud(options[i][j]).MoveOverTime(250, 1000.0f, 100.0f + (j * 15.0f));
	}
	else {
		Entity::GetEntityPtr(i)->client->mflag |= 4;

		Hud(background[i]).MoveOverTime(250, 600.0f, 200.0f);
		Hud(header[i]).MoveOverTime(250, 600.0f, 70.0f);
		for (int j = 0; j < MAX_MENU_OPTIONS; j++)
			Hud(options[i][j]).MoveOverTime(250 + (j * 50), 600.0f, 100.0f + (j * 15.0f));
	}

	menuOpen[i] = !menuOpen[i];
}

void ScrollUp(int i) {
	if (!menuOpen[i] || !options[i][0])
		return;

	if (menuScroll[i] > -1) {
		menuScroll[i]--;
		Hud(options[i][menuScroll[i] + 1]).ScaleTextOverTime(100, 0.5f);
		Hud(options[i][menuScroll[i] + 1]).FadeOverTime(250, 255, 255, 255, 255);
	}
	if (menuScroll[i] == -1) {
		menuScroll[i] = menuSize[i] - 1;
		Hud(options[i][0]).ScaleTextOverTime(100, 0.5f);
		Hud(options[i][0]).FadeOverTime(250, 255, 255, 255, 255);
	}
	Hud(options[i][menuScroll[i]]).ScaleTextOverTime(100, 0.6f);
	Hud(options[i][menuScroll[i]]).FadeOverTime(250, 255, 0, 0, 255);
}

void ScrollDown(int i) {
	if (!menuOpen[i] || !options[i][0])
		return;

	if (menuScroll[i] < menuSize[i]) {
		menuScroll[i]++;
		Hud(options[i][menuScroll[i] - 1]).ScaleTextOverTime(100, 0.5f);
		Hud(options[i][menuScroll[i] - 1]).FadeOverTime(250, 255, 255, 255, 255);
	}
	if (menuScroll[i] == menuSize[i]) {
		menuScroll[i] = 0;
		Hud(options[i][MAX_MENU_OPTIONS - 1]).ScaleTextOverTime(100, 0.5f);
		Hud(options[i][MAX_MENU_OPTIONS - 1]).FadeOverTime(250, 255, 255, 255, 255);
	}
	Hud(options[i][menuScroll[i]]).ScaleTextOverTime(100, 0.6f);
	Hud(options[i][menuScroll[i]]).FadeOverTime(250, 255, 0, 0, 255);
}

void Select(int i) {
	if (!menuOpen[i])
		return;

	switch (menuSub[i]) {
	case hostSub::SUB_NONE:
		switch (menuScroll[i]) {
		case 0:
			SwitchMenu(i, hostSub::SUB_SELF);
			break;
		case 1:
			SwitchMenu(i, hostSub::SUB_LOBBY);
			break;
		case 2:
			SwitchMenu(i, hostSub::SUB_WEAPONS);
			break;
		case 3:
			SwitchMenu(i, hostSub::SUB_CLIENTS);
			break;
		case 4:
			SwitchMenu(i, hostSub::SUB_ALLCLIENTS);
			break;
		case 5:
			SwitchMenu(i, hostSub::SUB_TELEPORT);
			break;
		case 6:
			SwitchMenu(i, hostSub::SUB_AIMBOT);
			break;
		case 7:
			SwitchMenu(i, hostSub::SUB_PROJECTILE);
			break;
		default:
			break;
		}
		break;
	case hostSub::SUB_SELF:
		switch (menuScroll[i]) {
		case 0:
			//Godmode
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
			break;
		case 1:
			Menu[i].infiniteAmmo = !Menu[i].infiniteAmmo;
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, Menu[i].infiniteAmmo ? "c \"Infinite Ammo [^2ON^7]\"" : "c \"Infinite Ammo [^1OFF^7]\"");
			break;
		case 2:
			//2x Movement Speed
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
			break;
		case 3:
			UnlockAllTrophies(i);
			break;
		default:
			break;
		}
		break;
	case hostSub::SUB_LOBBY:
		switch (menuScroll[i]) {
		case 0:
			//Lobby Godmode
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
			break;
		case 1:
			//Lobby Infinite Ammo
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
			break;
		case 2:
			//Super Jump
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
			break;
		case 3:
			AddFriendlyBot();
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^2Friendly ^7Bot Added\"");
			break;
		case 4:
			RemoveFriendlyBot();
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^2Friendly ^7Bot Removed\"");
			break;
		case 5:
			AddEnemyBot();
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Enemy ^7Bot Added\"");
			break;
		case 6:
			RemoveEnemyBot();
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Enemy ^7Bot Removed\"");
			break;
		case 7:
			GScr_MapRestart();
			break;
		default:
			break;
		}
		break;
	case hostSub::SUB_WEAPONS:
		SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
		break;
	case hostSub::SUB_CLIENTS:
		SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
		break;
	case hostSub::SUB_ALLCLIENTS:
		SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"^1Not implemented!\"");
		break;
	case hostSub::SUB_TELEPORT:
		switch (menuScroll[i]) {
		case 0:
			PrintCoordinates(i);
			break;
		case 1:
			SavePosition(i);
			break;
		case 2:
			LoadPosition(i);
			break;
		case 3:
			TeleportUp(i, 100.0f);
			break;
		case 4:
			TeleportUp(i, 1000.0f);
			break;
		case 5:
			TeleportUp(i, -1000.0f);
			break;
		case 6:
			TeleportUp(i, -100.0f);
			break;
		default:
			break;
		}
		break;
	case hostSub::SUB_AIMBOT:
		switch (menuScroll[i]) {
		case 0:
			Menu[i].unfairAimbot = !Menu[i].unfairAimbot;
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, Menu[i].unfairAimbot ? "c \"Unfair Aimbot [^2ON^7]\"" : "c \"Unfair Aimbot [^1OFF^7]\"");
			break;
		case 1:
			if (Menu[i].aimbotMod < 5)
				Menu[i].aimbotMod++;
			else
				Menu[i].aimbotMod = 0;

			char temp[100];
			snprintf(temp, sizeof(temp), "c \"Aimbot Means Of Death [^3%i^7/^36^7]: ^2%s\"", Menu[i].aimbotMod + 1, MeansOfDeathDisplayNameForIndex(Menu[i].aimbotMod));
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, temp);
			break;
		default:
			break;
		}
		break;
	case hostSub::SUB_PROJECTILE:
		switch (menuScroll[i]) {
		case 0:
			Menu[i].magicBullet = !Menu[i].magicBullet;
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, Menu[i].magicBullet ? "c \"Magic Bullet [^2ON^7]\"" : "c \"Magic Bullet [^1OFF^7]\"");
			break;
		case 1:
			Menu[i].magicBulletIndex = 0;
			SV_GameSendServerCommand(i, svscmd_type::SV_CMD_RELIABLE, "c \"Bullet Type: ^2RPG\"");
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void GoBack(int i) {
	if (!menuOpen[i] || menuSub[i] == hostSub::SUB_NONE)
		return;

	if (menuDepth[i] > 0)
		SwitchMenu(i, menuLastSub[i][menuDepth[i] - 1]);
}

END
NAMESPACE(Forge)

gentity_s *clientCurrentEntity[MAX_MENU_CLIENTS];

void MoveEntity(gentity_s *player, gentity_s *ent) { //NOT UPDATED
	float playerAngles[3];
	playerAngles[0] = player->angles[0];
	playerAngles[1] = player->angles[1];
	playerAngles[2] = player->angles[2];

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);

	float viewOrigin[3];
	G_GetPlayerViewOrigin((playerState_s *)player->client, viewOrigin);

	float origin[3];
	origin[0] = viewOrigin[0] + forward[0] * 100;
	origin[1] = viewOrigin[1] + forward[1] * 100;
	origin[2] = viewOrigin[2] + forward[2] * 100;
	G_SetOrigin(ent, origin);

	playerAngles[0] = 0;
	playerAngles[1] += 90;
	G_SetAngle(ent, playerAngles);

	SV_LinkEntity(ent);
}

void DeleteEntity(gentity_s *player) { //NOT UPDATED
	float playerAngles[3];
	playerAngles[0] = player->angles[0];
	playerAngles[1] = player->angles[1];
	playerAngles[2] = player->angles[2];

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);

	float start[3];
	G_DObjGetWorldTagPos(player, SL_GetString("tag_eye", 0), start);

	float end[3];
	end[0] = forward[0] * 999999999;
	end[1] = forward[1] * 999999999;
	end[2] = forward[2] * 999999999;

	unsigned short entityId = 0;
	int r = BulletTrace(start, end, &entityId);
	if (!r) {
		gentity_s *ent = Entity::GetEntityPtr(entityId);
		G_FreeEntity(ent);
	}
}

void PickupEntity(gentity_s *player) { //NOT UPDATED
	float playerAngles[3];
	playerAngles[0] = player->angles[0];
	playerAngles[1] = player->angles[1];
	playerAngles[2] = player->angles[2];

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);

	float start[3];
	G_DObjGetWorldTagPos(player, SL_GetString("tag_eye", 0), start);

	float end[3];
	end[0] = forward[0] * 999999999;
	end[1] = forward[1] * 999999999;
	end[2] = forward[2] * 999999999;

	unsigned short entityId = 0;
	int r = BulletTrace(start, end, &entityId);
	if (!r)
		clientCurrentEntity[player->number] = Entity::GetEntityPtr(entityId);
}

void MoveForgeEntities() { //NOT UPDATED
	uartprintf("[MWR 1.15] MoveForgeEntities() -> THREAD STARTED!\n");
	while (ShouldRun()) {
		if (!Cache::Game.inGame) {
			Sleep(10);
			continue;
		}
		for (int i = 0; i < MAX_MENU_CLIENTS; i++) {
			if (clientCurrentEntity[i] != 0) {
				MoveEntity(Entity::GetEntityPtr(i), clientCurrentEntity[i]);
			}
		}
		Sleep(10);
	}

	uartprintf("[MWR 1.15] MoveForgeEntities() -> THREAD ENDED!\n");
}

END
END
