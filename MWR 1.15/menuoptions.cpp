#include "menuoptions.h"

#include "defines.h"

NAMESPACE(Menu)

Options_t Options;

void Init() {
	Options.menuOpen = false;
	Options.isInSubMenu = false;
	Options.menuMaxScroll = 0;
	Options.menuScroll = 0;
	Options.menuPageIndex = 0;
	Options.menuTabHeight = 75;
	Options.menuOptionIndex = 0;

	SetupColor(&Options.color_menuBorder, 0.0f, 0.4f, 1.0f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuScroller, 0.0f, 0.48f, 0.8f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuBackground, 0.18f, 0.18f, 0.19f, 0.95f, 0.2f);
	SetupColor(&Options.color_menuText, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuToggle, 0.0f, 0.48f, 0.8f, 1.0f, 0.2f);
	SetupColor(&Options.color_menuControlBackground, 0.12f, 0.12f, 0.12f, 1.0f, 0.2f);

	SetupInt(&Options.menuX, 50, 50, 1920, 0);
	SetupInt(&Options.menuY, 50, 50, 1080, 0);
	SetupInt(&Options.menuWidth, 520, 520, 4000, 0);
	SetupInt(&Options.menuHeight, 655, 655, 3000, 0);
	SetupInt(&Options.menuBorder, 0, 0, 20, 0);
	SetupInt(&Options.menuFontIndex, 3, 3, NUM_FONTS, 0);
	SetupFloat(&Options.menuFontSize, 0.5f, 0.5f, 2.0f, 0.01f, 0.001f);
	SetupInt(&Options.menuScrollerInitialDelay, 30, 30, 500, 10);
	SetupInt(&Options.menuScrollerDelay, 5, 5, 50, 0);

	SetupInt(&Options.boxSize, 20, 20, 100, 5);
	SetupInt(&Options.sliderWidth, 100, 100, 200, 20);
	SetupInt(&Options.sliderHeight, 13, 13, 50, 4);

	SetupBool(&Options.debug_godmode, true);
	SetupBool(&Options.debug_infAmmo, true);
	SetupBool(&Options.debug_drawInfo, true);
	SetupBool(&Options.debug_test2, false);
	SetupBool(&Options.debug_testDisabled, true, false);

	SetupBool(&Options.host_magicBullet, false);
	SetupInt(&Options.host_magicBulletProjectileIndex, 0, 0, 24, 0);
}

END
