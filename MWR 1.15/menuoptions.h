#pragma once

#include "global.h"
#include "menustruct.h"

NAMESPACE(Menu)

struct Options_t {
	bool menuOpen;
	bool isInSubMenu;
	int menuMaxScroll;
	int menuScroll;
	int previousScroll;
	int menuPageIndex;
	int previousPageIndex;
	int previousPages[10];
	int previousScrolls[10];
	int menuSubMenuPageIndex;
	int menuTabHeight;
	int menuOptionIndex;
	char menuHeaderText[200];

	ColorMenuOption color_menuBorder;
	ColorMenuOption color_menuScroller;
	ColorMenuOption color_menuBackground;
	ColorMenuOption color_menuText;
	ColorMenuOption color_menuToggle;
	ColorMenuOption color_menuControlBackground;

	IntMenuOption menuX;
	IntMenuOption menuY;
	IntMenuOption menuWidth;
	IntMenuOption menuHeight;
	IntMenuOption menuBorder;
	IntMenuOption menuFontIndex;
	FloatMenuOption menuFontSize;
	IntMenuOption menuScrollerInitialDelay;
	IntMenuOption menuScrollerDelay;

	IntMenuOption boxSize;
	IntMenuOption sliderWidth;
	IntMenuOption sliderHeight;

	BoolMenuOption debug_godmode;
	BoolMenuOption debug_infAmmo;
	BoolMenuOption debug_drawInfo;
	BoolMenuOption debug_test2;
	BoolMenuOption debug_testDisabled;

	BoolMenuOption host_magicBullet;
	IntMenuOption host_magicBulletProjectileIndex;

	//declare sub menus here
	SubMenuMenuOption Sub_Debug;

	SubMenuMenuOption Sub_Color_MenuBorder;
	SubMenuMenuOption Sub_Color_MenuScroller;
	SubMenuMenuOption Sub_Color_MenuBackground;
	SubMenuMenuOption Sub_Color_MenuText;
	SubMenuMenuOption Sub_Color_MenuToggle;
	SubMenuMenuOption Sub_Color_MenuControlBackground;
};

enum submenus {
	Main,

	Sub_Color_MenuBorder,
	Sub_Color_MenuScroller,
	Sub_Color_MenuBackground,
	Sub_Color_MenuText,
	Sub_Color_MenuToggle,
	Sub_Color_MenuControlBackground
};

extern Options_t Options;

void Init();

END
