#include "debug.h"

#include "utility.h"

void PrintLoadedZones() {
	uartprintf("[MWR 1.15] ========== Loaded Zones ==========\n");
	uint64_t ptr = 0x0000000002F08140;
	int count = 0;

	while (*(char *)(ptr + 0x110) != 0) {
		uartprintf("[MWR 1.15] %s\n", (char *)(ptr + 0x110));
		ptr += 0xF8;
		count++;
	}

	uartprintf("[MWR 1.15] -> A total of %i zones are loaded.\n", count);
	uartprintf("[MWR 1.15] ==================================\n");
}

//build string stuff
//0000000000527877 loc_527877
