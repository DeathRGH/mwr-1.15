#include "cache.h"

#include "defines.h"
#include "functions.h"
#include "imports.h"
#include "structs.h"

NAMESPACE(Cache)

Game_s Game;

void CacheGame() {
	Game.inGame = InGame();
	Game.gametype = /*Game.inGame ? GetRawGametype() : */"Unknown";
	Game.mapname = /*Game.inGame ? GetRawMapname() : */"Unknown";
	Game.hostname = /*Game.inGame ? cgs.hostname : */"Unknown Host";
	Game.inZombies = false;//!strcmp(Game.gametype, "zclassic"); //check this !!!
}

void CacheAll() {
	CacheGame();
}

END
