#include "host.h"

#include "cache.h"
#include "functions.h"
#include "imports.h"
#include "utility.h"

NAMESPACE(Host)

void FireMagicBullet(short entNum, const char *projectile) {
	float playerAngles[3];
	playerAngles[0] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4);
	playerAngles[1] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4 + 4);
	playerAngles[2] = *(float *)((entNum * 0x5780) + 0x000000000659C180 + 0x1B4 + 8);

	float forward[3];
	AngleVectors(playerAngles, forward, 0, 0);
	forward[0] *= 999999999.0f;
	forward[1] *= 999999999.0f;
	forward[2] *= 999999999.0f;

	float startPos[3];
	G_DObjGetWorldTagPos((gentity_s *)0x00000000064293D0 + (entNum * 0x2E0), SL_GetString("tag_weapon_right", 0), startPos);

	Scr_AddVector(forward);
	Scr_AddVector(startPos);
	Scr_AddString(projectile);
	Scr_SetNumParam(3);

	Scr_MagicBullet();
}

int BulletTrace(float *start, float *end, unsigned short *entityId) {
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

NAMESPACE(Lobby)

void Godmode(bool state) {
	memcpy((void *)0x00000000007138BA, state ? "\x90\x90\x90\x90\x90\x90\x90" : "\x45\x29\xA7\xD0\x01\x00\x00", 7);
}

void InfiniteAmmo(bool state) {
	memcpy((void *)0x00000000005768EF, state ? "\x90\x90\x90\x90\x90" : "\x44\x29\x7C\x81\x08", 5);
}

END
NAMESPACE(Entity)

gentity_s *GetEntityPtr(int i) {
	return (gentity_s *)(gentity_t + (i * gentity_size));
}

gentity_s *SpawnScriptModel(const char *modelName, float *origin) {
	gentity_s *entity = G_Spawn();
	if (entity) {
		if (modelName)
			G_SetModel(entity, modelName);

		if (origin)
			G_SetOrigin(entity, origin);

		entity->spawnflags = 0;
		SP_script_model(entity);
	}

	return entity;
}

void CloneBrushModelToScriptModel(gentity_s *scriptModel, gentity_s *brushModel) {
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

int Solid(gentity_s *ent) {
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

gentity_s *FindCollision(const char *name) {
	for (int i = 0; i < 2048; i++) {
		gentity_s *ent = GetEntityPtr(i);
		// check if it is a brushmodel
		if (*(uint8_t *)((uint8_t *)ent + 0x101) == 4) {
			const char *targetname = SL_ConvertToString(ent->targetname);
			//uartprintf("[AW 1.24] FindCollision(%s) -> %i %s\n", name, i, targetname);
			if (targetname) {
				// see d3dbsp files for maps
				if (!strcmp(targetname, name)) {
					//uartprintf("[AW 1.24] FindCollision(%s) -> 0x%llX (%i): %s\n", name, ent, i, targetname);
					return ent;
				}
			}
		}
	}

	uartprintf("[AW 1.24] FindCollision(%s) -> Collision for \"%s\" not found!\n", name, name);
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

int lastClientButton[MAX_MENU_CLIENTS];

END
NAMESPACE(Forge)

gentity_s *clientCurrentEntity[MAX_MENU_CLIENTS];

void MoveEntity(gentity_s *player, gentity_s *ent) {
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

void DeleteEntity(gentity_s *player) {
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

void PickupEntity(gentity_s *player) {
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

void MoveForgeEntities() {
	uartprintf("[AW 1.24] MoveForgeEntities() -> THREAD STARTED!\n");
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

	uartprintf("[AW 1.24] MoveForgeEntities() -> THREAD ENDED!\n");
}

END
END
