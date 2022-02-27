#pragma once

#include "global.h"
#include "structs.h"

#define MAX_CLIENTS 18
#define MAX_ENTITYS 2048
#define NUM_FONTS 6
#define NUM_BONES 20

#define ScrPlace (ScreenPlacement *)0x00//vHandler->defs.addr_CustomScreenPlacement
#define bg_weaponCompleteDefs 0x3DF7400 //

#define gentity_t 0x00000000064293D0
#define gentity_size 0x2E0
#define gclient_t 0x000000000659C180
#define gclient_size 0x5780
#define lua_state (lua_State *)(*(uint64_t *)0x00000000025A6920)
#define UI_Context (UiContext *)0x000000000B80C540
#define scr_const 0x00000000066B4500

//00000000026EE8A0 weapondef ( & 0x3FF)

//0x00000000064293D0 //gentity //0x2E0

//0x000000000659C180 //gclient //0x5780
//0x5370 - mflag

#define SV_CMD_R2_DOWN			"n 1"
#define SV_CMD_R2_UP			"n 2"
#define SV_CMD_R1_DOWN			"n 5"
#define SV_CMD_R1_UP			"n 6"
#define SV_CMD_L1_DOWN			"n 7"
#define SV_CMD_L1_UP			"n 8"
#define SV_CMD_L3_DOWN			"n 9"
#define SV_CMD_L3_UP			"n 10"
#define SV_CMD_SQUARE_DOWN		"n 11"
#define SV_CMD_SQUARE_UP		"n 12"
#define SV_CMD_L2_DOWN			"n 13"
#define SV_CMD_L2_UP			"n 14"
#define SV_CMD_DPAD_UP_DOWN		"n 15"
#define SV_CMD_DPAD_UP_UP		"n 16"
#define SV_CMD_DPAD_DOWN_DOWN	"n 17"
#define SV_CMD_DPAD_DOWN_UP		"n 18"
#define SV_CMD_DPAD_LEFT_DOWN	"n 19"
#define SV_CMD_DPAD_LEFT_UP		"n 20"
#define SV_CMD_DPAD_RIGHT_DOWN	"n 21"
#define SV_CMD_DPAD_RIGHT_UP	"n 22"
#define SV_CMD_CIRCLE_DOWN		"n 23"
#define SV_CMD_CIRCLE_UP		"n 24"
#define SV_CMD_X_DOWN			"n 25"
#define SV_CMD_X_UP				"n 26"
#define SV_CMD_R3_DOWN			"n 27"
#define SV_CMD_R3_UP			"n 28"
#define SV_CMD_OPTIONS			"n 39"
#define SV_CMD_TRIANGLE			"n 40"
#define SV_CMD_TOUCHPAD			"n 42"

//dvars
#define dvar_s_current 0x10
#define dvar_s_default 0x30
#define dvar_s_min 0x40
#define dvar_s_max 0x44
//dvar types (dvar_s + 0x0C) (1 byte)
//0 = bool
//1 = float
//1 = int
//6 = string

#define cg_fov 0x0000000000F2FF08

#define cl_ingame 0x00000000027AB638

#define FONT_DEFAULT 0x00 //vHandler->defs.addr_Font_Default

#define MENU_FONT FONT_DEFAULT

const char *FontForIndex(int index);
const char *FontDisplayNameForIndex(int index);
const char *AimbotBoneForIndex(int index);
const char *MagicBulletProjectileForIndex(int index);

const char *GetRawWeaponNameForIndex(int id);
const char *GetWeaponNameForIndex(int id);

uint64_t GetTTFForFont(uint64_t font);

bool WorldToScreen(float *worldLocation, float *screen);

void OffHost_EndGame();
void SendConsoleCommand();

extern bool gameEnded;
void PreventCrash();
bool InGame();
const char *GetRawGametype();
const char *GetRawMapname();

void DrawText(const char *text, float x, float y, float fontSize, float *color, struct Font_s *font);
void DrawText(const char *text, float x, float y, float fontSize, float *color, const char *font);
void DrawText(const char *text, float x, float y, float fontSize, float *color);
void DrawTextWithGlow(const char *text, float x, float y, float fontSize, float *color, float *glowColor, Font_s *font);
void DrawTextWithGlow(const char *text, float x, float y, float fontSize, float *color, float *glowColor, const char *font);
void DrawTextWithGlow(const char *text, float x, float y, float fontSize, float *color, float *glowColor);
void DrawShader(float x, float y, float width, float height, float *color, struct Material *material);
void DrawShader(float x, float y, float width, float height, float *color, const char *material);
void DrawShader(float x, float y, float width, float height, float *color);
void DrawCenterTextWithBackground(const char *text, float x, float y, float fontSize, float *color, float *backgroundColor, Font_s *font);
void DrawCenterTextWithBackground(const char *text, float x, float y, float fontSize, float *color, float *backgroundColor, const char *font);
void DrawCenterTextWithBackground(const char *text, float x, float y, float fontSize, float *color, float *backgroundColor);
void DrawCenterTextWithBackgroundWithBorder(const char *text, float x, float y, float *color = white10, float fontSize = 0.5f, float *backgroundColor = black08, int borderSize = 2, float *borderColor = white10);
void DrawLine(float x1, float y1, float x2, float y2, float width, float *color);
void DrawHexDump(float x, float y, uint64_t address, int length, float fontSize);
