#include "structs.h"

#include "cache.h"
#include "defines.h"
#include "functions.h"
#include "imports.h"

//UiContext_t *UiContext = (UiContext_t *)vHandler->structDefs.addr_UiContext;

cg_t cg;
cgs_t cgs;
centity_t centity[2048];
clientActive_t clientActive;

void ReadStructs() {
	/*UiContext = GetUiContextForVersion();
	if (*(uint64 *)vHandler->structDefs.addr_cg != 0)
		cg = GetCgForVersion();
	if (*(uint64 *)vHandler->structDefs.addr_cgs != 0)
		cgs = GetCgsForVersion();
	if (*(uint64 *)vHandler->structDefs.addr_centity != 0)
		for (int i = 0; i < 2048; i++)
			centity[i] = GetCentityForVersion(i);
	if (*(uint64 *)vHandler->structDefs.addr_clientActive != 0)
		clientActive = GetClientActiveForVersion();*/
}

bool IsAlive(int i) {
	if (Cache::Game.inZombies)
		return centity[i].alive != 0 && !(centity[i].alive & 0x900000000);
	else
		return centity[i].alive != 0;
}
