#pragma once

#include "global.h"
#include "host_huds.h"
#include "structs.h"

NAMESPACE(Host)

void AddFriendlyBot();
void RemoveFriendlyBot();
void AddEnemyBot();
void RemoveEnemyBot();

void FireMagicBullet(short entNum, const char *projectile);

int BulletTrace(float *start, float *end, unsigned short *entityId);

NAMESPACE(Lobby)

void Godmode(bool state);
void InfiniteAmmo(bool state);

END
NAMESPACE(Entity)

gentity_s *GetEntityPtr(int i);
void ToggleNoclip(int i);
gentity_s *SpawnScriptModel(const char *modelName, float *origin);
void CloneBrushModelToScriptModel(gentity_s *scriptModel, gentity_s *brushModel);
int Solid(gentity_s *ent);
gentity_s *FindCollision(const char *name);

const char *GetModelNameFromEntity(int i);
const char *GetModelNameFromEntity(gentity_s *ent);

END
NAMESPACE(Menu)

#define MAX_MENU_CLIENTS 18

extern bool menuOpen[MAX_MENU_CLIENTS];

extern struct game_hudelem_s *background[MAX_MENU_CLIENTS];
extern struct game_hudelem_s *header[MAX_MENU_CLIENTS];
extern struct game_hudelem_s *options[MAX_MENU_CLIENTS][10];

void OnPlayerSpawned(int i);
void OnPlayerDeath(int i);
void OpenCloseMenu(int i);

END
NAMESPACE(Forge)

extern gentity_s *clientCurrentEntity[MAX_MENU_CLIENTS];

void MoveEntity(gentity_s *player, gentity_s *ent);
void DeleteEntity(gentity_s *player);
void PickupEntity(gentity_s *player);

void MoveForgeEntities();

END
END
