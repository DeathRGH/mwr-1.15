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

int ClosestClient(int i);

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

enum hostSub {
	SUB_NONE,
	SUB_SELF,
	SUB_LOBBY,
	SUB_WEAPONS,
	SUB_CLIENTS,
	SUB_ALLCLIENTS,
	SUB_TELEPORT,
	SUB_AIMBOT,
	SUB_PROJECTILE
};

#define MAX_MENU_CLIENTS 18
#define MAX_MENU_OPTIONS 12
#define MAX_MENU_DEPTH 5

struct MenuStruct {
	bool unfairAimbot;
	bool aimbotUseHeadhsots;
	bool magicBullet;
	int magicBulletIndex;
};

extern MenuStruct Menu[MAX_MENU_CLIENTS];

extern bool menuOpen[MAX_MENU_CLIENTS];
extern int menuScroll[MAX_MENU_CLIENTS];
extern int menuSize[MAX_MENU_CLIENTS];
extern hostSub menuSub[MAX_MENU_CLIENTS];
extern int menuDepth[MAX_MENU_CLIENTS];
extern hostSub menuLastSub[MAX_MENU_CLIENTS][MAX_MENU_DEPTH];
extern char menuText[MAX_MENU_CLIENTS][MAX_MENU_OPTIONS][128];

extern struct game_hudelem_s *background[MAX_MENU_CLIENTS];
extern struct game_hudelem_s *header[MAX_MENU_CLIENTS];
extern struct game_hudelem_s *options[MAX_MENU_CLIENTS][MAX_MENU_OPTIONS];

void UpdateMenu(int i, hostSub subMenu, int maxScroll, const char *headerText, ...);
void SwitchToMainMenu(int i);
void SwitchMenu(int i, hostSub subMenu);
void OnPlayerSpawned(int i);
void OpenCloseMenu(int i);
void ScrollUp(int i);
void ScrollDown(int i);
void Select(int i);
void GoBack(int i);

END
NAMESPACE(Forge)

extern gentity_s *clientCurrentEntity[MAX_MENU_CLIENTS];

void MoveEntity(gentity_s *player, gentity_s *ent);
void DeleteEntity(gentity_s *player);
void PickupEntity(gentity_s *player);

void MoveForgeEntities();

END
END
