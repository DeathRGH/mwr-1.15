#pragma once

#include "global.h"
#include "structs.h"

NAMESPACE(Host)

void FireMagicBullet(short entNum, const char *projectile);

int BulletTrace(float *start, float *end, unsigned short *entityId);

NAMESPACE(Lobby)

void Godmode(bool state);
void InfiniteAmmo(bool state);

END
NAMESPACE(Entity)

gentity_s *GetEntityPtr(int i);
gentity_s *SpawnScriptModel(const char *modelName, float *origin);
void CloneBrushModelToScriptModel(gentity_s *scriptModel, gentity_s *brushModel);
int Solid(gentity_s *ent);
gentity_s *FindCollision(const char *name);

const char *GetModelNameFromEntity(int i);
const char *GetModelNameFromEntity(gentity_s *ent);

END
NAMESPACE(Menu)

#define MAX_MENU_CLIENTS 18
extern int lastClientButton[MAX_MENU_CLIENTS];

END
NAMESPACE(Forge)

extern gentity_s *clientCurrentEntity[MAX_MENU_CLIENTS];

void MoveEntity(gentity_s *player, gentity_s *ent);
void DeleteEntity(gentity_s *player);
void PickupEntity(gentity_s *player);

void MoveForgeEntities();

END
END
