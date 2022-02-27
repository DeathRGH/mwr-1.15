#pragma once

#include "global.h"

NAMESPACE(Menu)

#define MAX_OPTIONS 100

struct SubMenuMenuOption {
	int newMenu;
	int previousPageIndex;
	int previousScroll;

	char text[200];

	int scrollIndex;
	bool enabled;
};

struct ButtonMenuOption {
	int scrollIndex;
	bool enabled;
};

struct BoolMenuOption {
	bool state;

	int scrollIndex;
	bool enabled;
};

struct IntMenuOption {
	int current;
	int init;
	int max;
	int min;
	int step;

	int scrollIndex;
	bool enabled;
};

struct FloatMenuOption {
	float current;
	float init;
	float max;
	float min;
	float step;

	int scrollIndex;
	bool enabled;
};

struct Color {
	FloatMenuOption r;
	FloatMenuOption g;
	FloatMenuOption b;
	FloatMenuOption a;
	BoolMenuOption rgbOverride;

	float *ToFloatArray(bool alphaOverride = false, float alpha = 1.0f) {
		static float retVal[4];
		retVal[0] = rgbOverride.state ? rgbColor10[0] : r.current;
		retVal[1] = rgbOverride.state ? rgbColor10[1] : g.current;
		retVal[2] = rgbOverride.state ? rgbColor10[2] : b.current;
		
		if (alphaOverride)
			retVal[3] = alpha;
		else
			retVal[3] = a.current;

		return retVal;
	}
};

struct ColorMenuOption {
	Color color;

	float maxAlpha;
	float minAlpha;
	float step;

	int scrollIndex;
	bool enabled;
};

void SetupSubMenu(const char *text, SubMenuMenuOption *option, int newMenu, int previousPageIndex, int previousScroll, bool enabled = true);
void SwitchToSubMenu(SubMenuMenuOption *option, int &menuPageIndex);

void SetupColor(ColorMenuOption *option, float r, float g, float b, float a, float minAlpha = 0.0f, float maxAlpha = 1.0f, float step = 0.01f, bool enabled = true, bool rgb = false);

void SetupButton(ButtonMenuOption *option, bool enabled = true);

void SetupBool(BoolMenuOption *option, bool state, bool enabled = true);
void ToggleBool(BoolMenuOption *option);

void SetupInt(IntMenuOption *option, int current, int init, int max, int min, int step = 1, bool enabled = true);
void AddInt(IntMenuOption *option);
void SubInt(IntMenuOption *option);
void ResetInt(IntMenuOption *option);

void SetupFloat(FloatMenuOption *option, float current, float init, float max, float min, float step, bool enabled = true);
void AddFloat(FloatMenuOption *option);
void SubFloat(FloatMenuOption *option);
void ResetFloat(FloatMenuOption *option);

extern SubMenuMenuOption *SubMenuMenuOption_List[MAX_OPTIONS];
extern ButtonMenuOption *ButtonMenuOption_List[MAX_OPTIONS];
extern BoolMenuOption *BoolMenuOption_List[MAX_OPTIONS];
extern IntMenuOption *IntMenuOption_List[MAX_OPTIONS];
extern FloatMenuOption *FloatMenuOption_List[MAX_OPTIONS];

void StartMenuPage();

void AddSubMenuMenuOptionToList(SubMenuMenuOption *option);
void SwitchToSubMenu_List(int menuScroll, int &menuPageIndex, bool &isInSubMenu, int &scroll, int &previousPageIndex, int &previousScroll);

void AddButtonMenuOptionToList(ButtonMenuOption *option);

void AddBoolMenuOptionToList(BoolMenuOption *option);
void ToggleBool_List(int menuScroll);

void AddIntMenuOptionToList(IntMenuOption *option);
void AddInt_List(int menuScroll);
void SubInt_List(int menuScroll);
void ResetInt_List(int menuScroll);

void AddFloatMenuOptionToList(FloatMenuOption *option);
void AddFloat_List(int menuScroll);
void SubFloat_List(int menuScroll);
void ResetFloat_List(int menuScroll);

END
