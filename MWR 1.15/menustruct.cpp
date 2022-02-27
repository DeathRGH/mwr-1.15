#include "menustruct.h"

#include "imports.h"
#include "menuoptions.h"

NAMESPACE(Menu)

void SetupSubMenu(const char *text, SubMenuMenuOption *option, int newMenu, int previousPageIndex, int previousScroll, bool enabled) {
	option->newMenu = newMenu;
	option->previousPageIndex = previousPageIndex;
	option->previousScroll = previousScroll;

	strncpy((char *)option->text, text, strlen(text) + 1);

	option->enabled = enabled;
}

void SwitchToSubMenu(SubMenuMenuOption *option, int &menuPageIndex) {
	if (!option->enabled)
		return;

	menuPageIndex = option->newMenu;

	strncpy(Options.menuHeaderText, option->text, strlen(option->text) + 1);

	Options.previousPages[Options.menuSubMenuPageIndex] = option->previousPageIndex;
	Options.previousScrolls[Options.menuSubMenuPageIndex] = option->previousScroll;
	Options.menuSubMenuPageIndex++;
}

void SetupButton(ButtonMenuOption *option, bool enabled) {
	option->enabled = enabled;
}

void SetupBool(BoolMenuOption *option, bool state, bool enabled) {
	option->state = state;

	option->enabled = enabled;
}
void ToggleBool(BoolMenuOption *option) {
	if (!option->enabled)
		return;

	option->state = !option->state;
}

void SetupInt(IntMenuOption *option, int current, int init, int max, int min, int step, bool enabled) {
	option->current = current;
	option->init = init;
	option->max = max;
	option->min = min;
	option->step = step;

	option->enabled = enabled;
}

void AddInt(IntMenuOption *option) {
	if (!option->enabled)
		return;

	if (option->max > option->current)
		option->current += option->step;
}

void SubInt(IntMenuOption *option) {
	if (!option->enabled)
		return;

	if (option->min < option->current)
		option->current -= option->step;
}

void ResetInt(IntMenuOption *option) {
	if (!option->enabled)
		return;

	option->current = option->init;
}

void SetupFloat(FloatMenuOption *option, float current, float init, float max, float min, float step, bool enabled) {
	option->current = current;
	option->init = init;
	option->max = max;
	option->min = min;
	option->step = step;

	option->enabled = enabled;
}

void AddFloat(FloatMenuOption *option) {
	if (!option->enabled)
		return;

	if (option->max > option->current)
		option->current += option->step;

	if (option->current > option->max)
		option->current = option->max;
}

void SubFloat(FloatMenuOption *option) {
	if (!option->enabled)
		return;

	if (option->min < option->current)
		option->current -= option->step;

	if (option->current < option->min)
		option->current = option->min;
}

void ResetFloat(FloatMenuOption *option) {
	if (!option->enabled)
		return;

	option->current = option->init;
}

void SetupColor(ColorMenuOption *option, float r, float g, float b, float a, float minAlpha, float maxAlpha, float step, bool enabled, bool rgb) {
	SetupFloat(&option->color.r, r, r, 1.0f, 0.0f, step);
	SetupFloat(&option->color.g, g, g, 1.0f, 0.0f, step);
	SetupFloat(&option->color.b, b, b, 1.0f, 0.0f, step);
	SetupFloat(&option->color.a, a, a, maxAlpha, minAlpha, step);

	SetupBool(&option->color.rgbOverride, rgb);

	option->maxAlpha = maxAlpha;
	option->minAlpha = minAlpha;
	option->step = step;

	option->enabled = enabled;
}

// lists

SubMenuMenuOption *SubMenuMenuOption_List[MAX_OPTIONS];
ButtonMenuOption *ButtonMenuOption_List[MAX_OPTIONS];
BoolMenuOption *BoolMenuOption_List[MAX_OPTIONS];
IntMenuOption *IntMenuOption_List[MAX_OPTIONS];
FloatMenuOption *FloatMenuOption_List[MAX_OPTIONS];

void StartMenuPage() {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		SubMenuMenuOption_List[i] = NULL;
		BoolMenuOption_List[i] = NULL;
		IntMenuOption_List[i] = NULL;
		FloatMenuOption_List[i] = NULL;
	}
}

// Sub Menu

void AddSubMenuMenuOptionToList(SubMenuMenuOption *option) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (SubMenuMenuOption_List[i] == NULL) {
			SubMenuMenuOption_List[i] = option;
			break;
		}
	}
}

void SwitchToSubMenu_List(int menuScroll, int &menuPageIndex, bool &isInSubMenu, int &scroll, int &previousPageIndex, int &previousScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (SubMenuMenuOption_List[i] == NULL)
			break;

		if (SubMenuMenuOption_List[i]->scrollIndex == menuScroll) {
			if (!SubMenuMenuOption_List[i]->enabled)
				continue;

			previousPageIndex = menuPageIndex;
			previousScroll = menuScroll;

			SwitchToSubMenu(SubMenuMenuOption_List[i], menuPageIndex);

			isInSubMenu = true;
			scroll = 0;
		}
	}
}

// button

void AddButtonMenuOptionToList(ButtonMenuOption *option) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (ButtonMenuOption_List[i] == NULL) {
			ButtonMenuOption_List[i] = option;
			break;
		}
	}
}

// bool

void AddBoolMenuOptionToList(BoolMenuOption *option) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (BoolMenuOption_List[i] == NULL) {
			BoolMenuOption_List[i] = option;
			break;
		}
	}
}

void ToggleBool_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (BoolMenuOption_List[i] == NULL)
			break;

		if (BoolMenuOption_List[i]->scrollIndex == menuScroll)
			ToggleBool(BoolMenuOption_List[i]);
	}
}

// int

void AddIntMenuOptionToList(IntMenuOption *option) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (IntMenuOption_List[i] == NULL) {
			IntMenuOption_List[i] = option;
			break;
		}
	}
}

void AddInt_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (IntMenuOption_List[i] == NULL)
			break;

		if (IntMenuOption_List[i]->scrollIndex == menuScroll)
			AddInt(IntMenuOption_List[i]);
	}
}

void SubInt_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (IntMenuOption_List[i] == NULL)
			break;

		if (IntMenuOption_List[i]->scrollIndex == menuScroll)
			SubInt(IntMenuOption_List[i]);
	}
}

void ResetInt_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (IntMenuOption_List[i] == NULL)
			break;

		if (IntMenuOption_List[i]->scrollIndex == menuScroll)
			ResetInt(IntMenuOption_List[i]);
	}
}

// float

void AddFloatMenuOptionToList(FloatMenuOption *option) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (FloatMenuOption_List[i] == NULL) {
			FloatMenuOption_List[i] = option;
			break;
		}
	}
}

void AddFloat_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (FloatMenuOption_List[i] == NULL)
			break;

		if (FloatMenuOption_List[i]->scrollIndex == menuScroll)
			AddFloat(FloatMenuOption_List[i]);
	}
}

void SubFloat_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (FloatMenuOption_List[i] == NULL)
			break;

		if (FloatMenuOption_List[i]->scrollIndex == menuScroll)
			SubFloat(FloatMenuOption_List[i]);
	}
}

void ResetFloat_List(int menuScroll) {
	for (int i = 0; i < MAX_OPTIONS; i++) {
		if (FloatMenuOption_List[i] == NULL)
			break;

		if (FloatMenuOption_List[i]->scrollIndex == menuScroll)
			ResetFloat(FloatMenuOption_List[i]);
	}
}

END
