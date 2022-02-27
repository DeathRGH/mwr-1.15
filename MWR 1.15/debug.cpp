#include "debug.h"

#include "utility.h"

void PrintLoadedZones() {
	uartprintf("[AW 1.24] ========== Loaded Zones ==========\n");
	uint64_t ptr = 0x0000000002F08140;
	int count = 0;

	while (*(char *)(ptr + 0x110) != 0) {
		uartprintf("[AW 1.24] %s\n", (char *)(ptr + 0x110));
		ptr += 0xF8;
		count++;
	}

	uartprintf("[AW 1.24] -> A total of %i zones are loaded.\n", count);
	uartprintf("[AW 1.24] ==================================\n");
}
