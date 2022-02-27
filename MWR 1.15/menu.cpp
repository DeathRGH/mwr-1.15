#include "menu.h"

#include "cache.h"
#include "defines.h"
#include "functions.h"
#include "host.h"
#include "imports.h"
#include "menuoptions.h"
#include "structs.h"
#include "utility.h"

NAMESPACE(Menu)

void DrawButton(const char *text, ButtonMenuOption *value, bool enabled = true) {
	Options.menuMaxScroll++;

	float *textColor = value->enabled ? (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));

	value->scrollIndex = Options.menuOptionIndex;
	AddButtonMenuOptionToList(value);
	Options.menuOptionIndex++;
}

void DrawToggle(const char *text, BoolMenuOption *value) {
	Options.menuMaxScroll++;

	float *textColor = value->enabled ? (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.boxSize.current - 5, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.boxSize.current) / 2) + (Options.menuBorder.current * 2), Options.boxSize.current, Options.boxSize.current, value->enabled ? Options.color_menuText.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.boxSize.current - 4, Options.menuY.current + Options.menuTabHeight + 1 + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.boxSize.current) / 2) + (Options.menuBorder.current * 2), Options.boxSize.current - 2, Options.boxSize.current - 2, Options.color_menuControlBackground.color.ToFloatArray());

	if (!value->state) {
		value->scrollIndex = Options.menuOptionIndex;
		AddBoolMenuOptionToList(value);
		Options.menuOptionIndex++;
		return;
	}

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.boxSize.current - 2, Options.menuY.current + Options.menuTabHeight + 3 + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.boxSize.current) / 2) + (Options.menuBorder.current * 2), Options.boxSize.current - 6, Options.boxSize.current - 6, value->enabled ? Options.color_menuToggle.color.ToFloatArray() : Options.color_menuToggle.color.ToFloatArray(true, 0.3f));
	value->scrollIndex = Options.menuOptionIndex;
	AddBoolMenuOptionToList(value);
	Options.menuOptionIndex++;
}

void DrawSubMenuButton(const char *text, SubMenuMenuOption *value, int newMenu, bool enabled = true) {
	Options.menuMaxScroll++;

	float *textColor = value->enabled ? (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	int textWidth = R_TextWidth(text, 0x7FFFFFFF, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));
	DrawText("-->", Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - textWidth - 6, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2) - 2, Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));

	SetupSubMenu(text, value, newMenu, Options.menuPageIndex, Options.menuOptionIndex, enabled);
	value->scrollIndex = Options.menuOptionIndex;
	AddSubMenuMenuOptionToList(value);
	Options.menuOptionIndex++;
}

void DrawIntSlider(const char *text, IntMenuOption *value, const char *fmt = "%i") {
	Options.menuMaxScroll++;

	float *textColor = value->enabled ? (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	int additiveRange = value->min >= 0 ? 0 : -value->min;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));
	char temp[100];
	snprintf(temp, sizeof(temp), fmt, value->current);
	int fmtWidth = R_TextWidth(temp, 0x7FFFFFFF, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;
	DrawText(temp, Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 10 - fmtWidth, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + (Options.menuBorder.current * 2), Options.sliderWidth.current, Options.sliderHeight.current, value->enabled ? white10 : white05);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 1, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 1 + (Options.menuBorder.current * 2), Options.sliderWidth.current - 2, Options.sliderHeight.current - 2, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 2 + (Options.menuBorder.current * 2), Options.sliderWidth.current - 4, Options.sliderHeight.current - 4, value->enabled ? white10 : white05);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 1, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 1 + (Options.menuBorder.current * 2), ((Options.sliderWidth.current - 2) / (float)(value->max + additiveRange)) * (value->current + additiveRange), Options.sliderHeight.current - 2, Options.color_menuControlBackground.color.ToFloatArray());

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + ((Options.sliderWidth.current - 2) / (float)(value->max + additiveRange)) * (value->current + additiveRange) - 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) - 2 + (Options.menuBorder.current * 2), 4, Options.sliderHeight.current + 4, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + ((Options.sliderWidth.current - 2) / (float)(value->max + additiveRange)) * (value->current + additiveRange) + 1 - 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) - 1 + (Options.menuBorder.current * 2), 2, Options.sliderHeight.current + 2, value->enabled ? white10 : white05);

	value->scrollIndex = Options.menuOptionIndex;
	AddIntMenuOptionToList(value);
	Options.menuOptionIndex++;
}

void DrawFloatSlider(const char *text, FloatMenuOption *value, const char *fmt) {
	Options.menuMaxScroll++;

	float *textColor = value->enabled ? (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	float additiveRange = value->min >= 0 ? 0 : -value->min;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));
	char temp[100];
	snprintf(temp, sizeof(temp), fmt, value->current);
	int fmtWidth = R_TextWidth(temp, 0x7FFFFFFF, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;
	DrawText(temp, Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 10 - fmtWidth, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + (Options.menuBorder.current * 2), Options.sliderWidth.current, Options.sliderHeight.current, value->enabled ? white10 : white05);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 1, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 1 + (Options.menuBorder.current * 2), Options.sliderWidth.current - 2, Options.sliderHeight.current - 2, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 2 + (Options.menuBorder.current * 2), Options.sliderWidth.current - 4, Options.sliderHeight.current - 4, value->enabled ? white10 : white05);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 1, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 1 + (Options.menuBorder.current * 2), ((Options.sliderWidth.current - 2) / (float)(value->max + additiveRange)) * (value->current + additiveRange), Options.sliderHeight.current - 2, Options.color_menuControlBackground.color.ToFloatArray());

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + ((Options.sliderWidth.current - 2) / (float)(value->max + additiveRange)) * (value->current + additiveRange) - 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) - 2 + (Options.menuBorder.current * 2), 4, Options.sliderHeight.current + 4, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + ((Options.sliderWidth.current - 2) / (float)(value->max + additiveRange)) * (value->current + additiveRange) + 1 - 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) - 1 + (Options.menuBorder.current * 2), 2, Options.sliderHeight.current + 2, value->enabled ? white10 : white05);

	value->scrollIndex = Options.menuOptionIndex;
	AddFloatMenuOptionToList(value);
	Options.menuOptionIndex++;
}

void DrawStringSlider(const char *text, IntMenuOption *value, const char *string) {
	Options.menuMaxScroll++;

	float *textColor = value->enabled ? (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (value->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	int stringWidth = R_TextWidth(string, 0x7FFFFFFF, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));
	DrawText(string, Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 10 - stringWidth, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + (Options.menuBorder.current * 2), Options.sliderWidth.current, Options.sliderHeight.current, value->enabled ? white10 : white05);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 1, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 1 + (Options.menuBorder.current * 2), Options.sliderWidth.current - 2, Options.sliderHeight.current - 2, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 2 + (Options.menuBorder.current * 2), Options.sliderWidth.current - 4, Options.sliderHeight.current - 4, value->enabled ? white10 : white05);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + 1, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) + 1 + (Options.menuBorder.current * 2), ((Options.sliderWidth.current - 2) / (float)value->max) * value->current, Options.sliderHeight.current - 2, Options.color_menuControlBackground.color.ToFloatArray());

	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + ((Options.sliderWidth.current - 2) / (float)value->max) * value->current - 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) - 2 + (Options.menuBorder.current * 2), 4, Options.sliderHeight.current + 4, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.sliderWidth.current - 5 + ((Options.sliderWidth.current - 2) / (float)value->max) * value->current + 1 - 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.sliderHeight.current) / 2) - 1 + (Options.menuBorder.current * 2), 2, Options.sliderHeight.current + 2, value->enabled ? white10 : white05);

	value->scrollIndex = Options.menuOptionIndex;
	AddIntMenuOptionToList(value);
	Options.menuOptionIndex++;
}

void DrawColorSubMenuButton(const char *text, ColorMenuOption *value, SubMenuMenuOption *subValue, int newMenu, bool enabled = true) {
	Options.menuMaxScroll++;

	float *textColor = subValue->enabled ? (subValue->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray() : Options.color_menuText.color.ToFloatArray()) : (subValue->scrollIndex == Options.menuScroll ? Options.color_menuScroller.color.ToFloatArray(true, 0.5f) : Options.color_menuText.color.ToFloatArray(true, 0.5f));
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0)) * Options.menuFontSize.current;

	DrawText(text, Options.menuX.current + Options.menuBorder.current + 5, Options.menuY.current + textHeight + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + (Options.menuBorder.current * 2), Options.menuFontSize.current, textColor, R_RegisterFont(FontForIndex(Options.menuFontIndex.current), 0));
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.boxSize.current - 5, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.boxSize.current) / 2) + (Options.menuBorder.current * 2), Options.boxSize.current, Options.boxSize.current, black10);
	DrawShader(Options.menuX.current + Options.menuWidth.current - Options.menuBorder.current - Options.boxSize.current - 5 + 2, Options.menuY.current + Options.menuTabHeight + (Options.menuOptionIndex * textHeight) + ((textHeight - Options.boxSize.current) / 2) + (Options.menuBorder.current * 2) + 2, Options.boxSize.current - 4, Options.boxSize.current - 4, value->color.ToFloatArray());

	SetupSubMenu(text, subValue, newMenu, Options.menuPageIndex, Options.menuOptionIndex, enabled);
	value->scrollIndex = subValue->scrollIndex = Options.menuOptionIndex;
	AddSubMenuMenuOptionToList(subValue);
	Options.menuOptionIndex++;
}

void DrawColorEditor(ColorMenuOption *value) {
	DrawFloatSlider("Red", &value->color.r, "%.2f");
	DrawFloatSlider("Green", &value->color.g, "%.2f");
	DrawFloatSlider("Blue", &value->color.b, "%.2f");
	DrawFloatSlider("Alpha", &value->color.a, "%.2f");
	DrawToggle("Fade", &value->color.rgbOverride);
}

void DrawBackgroundShader() {
	DrawShader(Options.menuX.current, Options.menuY.current, Options.menuWidth.current, Options.menuHeight.current, Options.color_menuBackground.color.ToFloatArray());
}

void DrawMenuText() {
	Options.menuMaxScroll = 0;
	Options.menuOptionIndex = 0;

	StartMenuPage();

	if (Options.menuPageIndex == submenus::Main) {
		DrawToggle("debug_infAmmo", &Options.debug_infAmmo);
		DrawToggle("debug_godmode", &Options.debug_godmode);
		DrawToggle("debug_drawInfo", &Options.debug_drawInfo);
		DrawToggle("debug_test2", &Options.debug_test2);
		DrawToggle("debug_testDisabled", &Options.debug_testDisabled);
		DrawIntSlider("menuX", &Options.menuX);
		DrawIntSlider("menuY", &Options.menuY);
		DrawIntSlider("menuWidth", &Options.menuWidth);
		DrawIntSlider("menuHeight", &Options.menuHeight);
		DrawIntSlider("menuScrollerInitialDelay", &Options.menuScrollerInitialDelay, "%i0ms");
		DrawIntSlider("menuScrollerDelay", &Options.menuScrollerDelay, "%i0ms");
		DrawFloatSlider("menuFontSize", &Options.menuFontSize, "%.3f");
		DrawIntSlider("menuFontIndex", &Options.menuFontIndex, FontDisplayNameForIndex(Options.menuFontIndex.current));
		DrawIntSlider("boxSize", &Options.boxSize);
		DrawIntSlider("sliderHeight", &Options.sliderHeight);
		DrawIntSlider("sliderWidth", &Options.sliderWidth);
		DrawColorSubMenuButton("Menu Border Color", &Options.color_menuBorder, &Options.Sub_Color_MenuBorder, submenus::Sub_Color_MenuBorder, false);
		DrawColorSubMenuButton("Menu Scroller Color", &Options.color_menuScroller, &Options.Sub_Color_MenuScroller, submenus::Sub_Color_MenuScroller);
		DrawColorSubMenuButton("Menu Background Color", &Options.color_menuBackground, &Options.Sub_Color_MenuBackground, submenus::Sub_Color_MenuBackground);
		DrawColorSubMenuButton("Menu Text Color", &Options.color_menuText, &Options.Sub_Color_MenuText, submenus::Sub_Color_MenuText);
		DrawColorSubMenuButton("Menu Toggle Color", &Options.color_menuToggle, &Options.Sub_Color_MenuToggle, submenus::Sub_Color_MenuToggle);
		DrawColorSubMenuButton("Menu Control Background Color", &Options.color_menuControlBackground, &Options.Sub_Color_MenuControlBackground, submenus::Sub_Color_MenuControlBackground);
		DrawToggle("host_magicBullet", &Options.host_magicBullet);
		DrawIntSlider("host_magicBulletProjectileIndex", &Options.host_magicBulletProjectileIndex, MagicBulletProjectileForIndex(Options.host_magicBulletProjectileIndex.current));
	}

	if (Options.menuPageIndex == submenus::Sub_Color_MenuBorder)
		DrawColorEditor(&Options.color_menuBorder);

	if (Options.menuPageIndex == submenus::Sub_Color_MenuScroller)
		DrawColorEditor(&Options.color_menuScroller);

	if (Options.menuPageIndex == submenus::Sub_Color_MenuBackground)
		DrawColorEditor(&Options.color_menuBackground);

	if (Options.menuPageIndex == submenus::Sub_Color_MenuText)
		DrawColorEditor(&Options.color_menuText);

	if (Options.menuPageIndex == submenus::Sub_Color_MenuToggle)
		DrawColorEditor(&Options.color_menuToggle);

	if (Options.menuPageIndex == submenus::Sub_Color_MenuControlBackground)
		DrawColorEditor(&Options.color_menuControlBackground);
}

void DrawMenu() {
	if (!Options.menuOpen)
		return;

	DrawBackgroundShader();
	DrawMenuText();

	DrawText("Advanced Warfare", Options.menuX.current + 10, Options.menuY.current + 0x40, Options.menuFontSize.current, Options.color_menuText.color.ToFloatArray());
}

void Select() {
	switch (Options.menuPageIndex) {
	case submenus::Main:
		switch (Options.menuScroll) {
		case 0:
			//Cbuf_AddText(0, "disconnect");
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void GoBack() {
	if (Options.menuPageIndex != submenus::Main) {
		if (Options.menuSubMenuPageIndex > 0) {
			Options.menuPageIndex = Options.previousPages[Options.menuSubMenuPageIndex - 1];
			Options.menuScroll = Options.previousScrolls[Options.menuSubMenuPageIndex - 1];

			Options.menuSubMenuPageIndex--;
		}
	}

	if (Options.menuPageIndex < 5)
		Options.isInSubMenu = false;
}

int previousButton;
int ticks = 0;
int speed = 0;
ScePadData padData;
void MonitorButtons() {
	uartprintf("[AW 1.24] MonitorButtons() -> THREAD STARTED!\n");
	while (ShouldRun()) {
		if (!userPadHandle) {
			Sleep(10);
			continue;
		}

		scePadReadState(userPadHandle, &padData);

		if (previousButton != padData.buttons) {
			previousButton = padData.buttons;
			ticks = 0;

			if ((padData.buttons & SCE_PAD_BUTTON_LEFT) && (padData.analogButtons.l2 > 100))
				Options.menuOpen = !Options.menuOpen;

			if (!Options.menuOpen) {
				Sleep(10);
				continue;
			}

			if (padData.buttons & SCE_PAD_BUTTON_DOWN) {
				if (Options.menuScroll < Options.menuMaxScroll)
					Options.menuScroll++;
				if (Options.menuScroll == Options.menuMaxScroll)
					Options.menuScroll = 0;
				speed = 0;
			}

			if (padData.buttons & SCE_PAD_BUTTON_UP) {
				if (Options.menuScroll > -1)
					Options.menuScroll--;
				if (Options.menuScroll == -1)
					Options.menuScroll = Options.menuMaxScroll - 1;
				speed = 0;
			}

			if (padData.buttons & SCE_PAD_BUTTON_R1 && !Options.isInSubMenu) {
				if (Options.menuPageIndex < 4) {
					Options.menuPageIndex++;
					Options.menuScroll = 0;
				}
			}

			if (padData.buttons & SCE_PAD_BUTTON_L1 && !Options.isInSubMenu) {
				if (Options.menuPageIndex > 0) {
					Options.menuPageIndex--;
					Options.menuScroll = 0;
				}
			}

			if (padData.buttons & SCE_PAD_BUTTON_CROSS) {
				ToggleBool_List(Options.menuScroll);

				Select();

				SwitchToSubMenu_List(Options.menuScroll, Options.menuPageIndex, Options.isInSubMenu, Options.menuScroll, Options.previousPageIndex, Options.previousScroll);
			}

			if (padData.buttons & SCE_PAD_BUTTON_SQUARE) {
				ResetInt_List(Options.menuScroll);
				ResetFloat_List(Options.menuScroll);
			}

			if (padData.buttons & SCE_PAD_BUTTON_CIRCLE) {
				GoBack();
			}

			if (padData.buttons & SCE_PAD_BUTTON_RIGHT) {
				AddInt_List(Options.menuScroll);
				AddFloat_List(Options.menuScroll);
			}

			if (padData.buttons & SCE_PAD_BUTTON_LEFT && padData.analogButtons.l2 < 100) {
				SubInt_List(Options.menuScroll);
				SubFloat_List(Options.menuScroll);
			}
		}

		if (!Options.menuOpen) {
			Sleep(10);
			continue;
		}

		if (padData.buttons & SCE_PAD_BUTTON_DOWN) {
			if (ticks < Options.menuScrollerInitialDelay.current) {
				ticks++;
				Sleep(10);
				continue;
			}
			if (speed < Options.menuScrollerDelay.current) {
				speed++;
				Sleep(10);
				continue;
			}
			else
				speed = 0;

			if (Options.menuScroll < Options.menuMaxScroll)
				Options.menuScroll++;
			if (Options.menuScroll == Options.menuMaxScroll)
				Options.menuScroll = 0;
		}

		if (padData.buttons & SCE_PAD_BUTTON_UP) {
			if (ticks < Options.menuScrollerInitialDelay.current) {
				ticks++;
				Sleep(10);
				continue;
			}
			if (speed < Options.menuScrollerDelay.current) {
				speed++;
				Sleep(10);
				continue;
			}
			else
				speed = 0;

			if (Options.menuScroll > -1)
				Options.menuScroll--;
			if (Options.menuScroll == -1)
				Options.menuScroll = Options.menuMaxScroll - 1;
		}

		if (padData.buttons & SCE_PAD_BUTTON_RIGHT) {
			if (ticks < Options.menuScrollerInitialDelay.current) {
				ticks++;
				Sleep(10);
				continue;
			}

			AddInt_List(Options.menuScroll);
			AddFloat_List(Options.menuScroll);
		}

		if (padData.buttons & SCE_PAD_BUTTON_LEFT && padData.analogButtons.l2 < 100) {
			if (ticks < Options.menuScrollerInitialDelay.current) {
				ticks++;
				Sleep(10);
				continue;
			}

			SubInt_List(Options.menuScroll);
			SubFloat_List(Options.menuScroll);
		}

		Sleep(10);
	}

	uartprintf("[AW 1.24] MonitorButtons() -> THREAD ENDED!\n");
}

void LoopSettings() {
	uartprintf("[AW 1.24] LoopSettings() -> THREAD STARTED!\n");
	while (ShouldRun()) {
		Cache::CacheAll();

		Host::Lobby::Godmode(Options.debug_godmode.state);
		Host::Lobby::InfiniteAmmo(Options.debug_infAmmo.state);

		*(float *)(*(uint64_t *)cg_fov + dvar_s_current) = 90.0f;

		*(char *)0x00000000007D6F90 = Options.menuOpen ? 0xC3 : 0x55; //GPad_UpdateDigitals
		Sleep(10);
	}

	uartprintf("[AW 1.24] LoopSettings() -> THREAD ENDED!\n");
}

void DrawDebug() {
	/*char buf[1000];
	snprintf(buf, sizeof(buf), "Debug Info  -  ScreenResolution: %ix%i", Cache::screenWidth, Cache::screenHeight);
	if (Menu::Options.debug_drawInfo.state)
		DrawTextWithBackground(buf, 500, 20, white10, black06, 0.4f);

	char buf2[1000];
	snprintf(buf2, sizeof(buf2), "cg_t->origin: %.2f, %.2f, %.2f", cg->origin[0], cg->origin[1], cg->origin[2]);
	if (Menu::Options.debug_drawInfo.state)
		DrawTextWithBackground(buf2, 500, 50, white10, black06, 0.4f);

	float *origin = cg->refdef.view.org.DecryptOrigin();

	char buf3[1000];
	snprintf(buf3, sizeof(buf3), "cg_t->viewOrigin: %.2f, %.2f, %.2f", origin[0], origin[1], origin[2]);
	if (Menu::Options.debug_drawInfo.state)
		DrawTextWithBackground(buf3, 500, 80, white10, black06, 0.4f);

	float screen[2];
	for (int i = 0; i < 18; i++) {
		centity_t cent = centity[i];

		if (!(cent.stateFlag & 0x01))
			continue;

		if (WorldToScreen(cent.DecryptOrigin(), screen)) {
			DrawLine(uiContext->screenWidth / 2, uiContext->screenHeight, screen[0], screen[1], 2, red10);
			DrawShader(screen[0], screen[1], 50, 50, cyan10);
		}

		char buf4[1000];
		snprintf(buf4, sizeof(buf4), "centity_t[%i]->origin: %.2f, %.2f, %.2f", i, cent.DecryptOrigin()[0], cent.DecryptOrigin()[1], cent.DecryptOrigin()[2]);
		if (Menu::Options.debug_drawInfo.state)
			DrawTextWithBackground(buf4, 500, 110 + (i * 30), white10, black06, 0.4f);
	}*/
}

void DrawWeaponList() {
	/*DrawShader(100, 600, 400, 200, black01);
	DrawShader(100, 600, 400, 200, white10, 0x100A70CA50);

	for (int i = 1; i < 99999; i++) {
		if (*(uint64_t *)(bg_weaponDefs + i * 8) <= 0)
			return;

		uint64_t weaponAsset = *(uint64_t *)(bg_weaponDefs + i * 8);
		uint64_t weaponLocName = *(uint64_t *)(weaponAsset + 0x10);
		uint64_t assetPtr = Functions::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_LOCALIZE_ENTRY, (char *)weaponLocName, 1);
		uint64_t functionCallParam = *(uint64_t *)(assetPtr + 8);

		if (assetPtr == 0 || functionCallParam == 0)
			continue;

		uint64_t weaponDisplayName = ((uint64_t(*)(uint64_t))0x0000000000530140)(*(uint64_t *)(assetPtr + 8));

		char tempBuf[100];
		snprintf(tempBuf, sizeof(tempBuf), "%i, 0x%X, %s, %s", i, i, (char *)*(uint64_t *)assetPtr, (char *)weaponDisplayName);
		DrawText(tempBuf, 610, 5 + (i * 20), white10, 0.4f);
	}*/
}

END
