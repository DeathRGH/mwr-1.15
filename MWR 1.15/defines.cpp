#include "defines.h"

#include "functions.h"
#include "imports.h"
#include "library_functions.h"
#include "structs.h"
#include "utility.h"

const char *FontForIndex(int index) {
	if (index == 0)
		return "fonts/default.otf";
	if (index == 1)
		return "fonts/defaultBold.otf";
	if (index == 2)
		return "fonts/fira_mono_regular.ttf";
	else
		return "fonts/default.otf";
}

const char *FontDisplayNameForIndex(int index) {
	if (index == 0)
		return "Default Font";
	if (index == 1)
		return "Bold Default Font";
	if (index == 2)
		return "Fira Mono Regular";
	else
		return "Default Font";
}

const char *AimbotBoneForIndex(int index) {
	if (index == 0)
		return "j_helmet";
	if (index == 1)
		return "j_head";
	if (index == 2)
		return "j_neck";
	if (index == 3)
		return "j_spine4";
	if (index == 4)
		return "j_spineupper";
	if (index == 5)
		return "j_spinelower";
	if (index == 6)
		return "j_mainroot";
	if (index == 7)
		return "j_shoulder_le";
	if (index == 8)
		return "j_shoulder_ri";
	if (index == 9)
		return "j_elbow_le";
	if (index == 10)
		return "j_elbow_ri";
	if (index == 11)
		return "j_wrist_le";
	if (index == 12)
		return "j_wrist_ri";
	if (index == 13)
		return "j_hip_le";
	if (index == 14)
		return "j_hip_ri";
	if (index == 15)
		return "j_knee_le";
	if (index == 16)
		return "j_knee_ri";
	if (index == 17)
		return "j_ankle_le";
	if (index == 18)
		return "j_ankle_ri";
	if (index == 19)
		return "j_ball_le";
	if (index == 20)
		return "j_ball_ri";
	else
		return "j_head";
}

const char *MagicBulletProjectileForIndex(int index) {
	if (index == 0)
		return "h1_rpg_mp";
	else
		return "h1_rpg_mp";
}

const char *AimbotWeaponForIndex(int index) {
	if (index == 0)
		return "airstrike_mp";
	if (index == 1)
		return "artillery_mp";
	if (index == 2)
		return "barrel_mp";
	if (index == 3)
		return "bomb_site_mp";
	if (index == 4)
		return "briefcase_bomb_defuse_mp";
	if (index == 5)
		return "briefcase_bomb_mp";
	if (index == 6)
		return "camera_10fov";
	if (index == 7)
		return "camera_20fov";
	if (index == 8)
		return "camera_30fov";
	if (index == 9)
		return "camera_45fov";
	if (index == 10)
		return "camera_5fov";
	if (index == 11)
		return "cobra_20mm_mp";
	if (index == 12)
		return "cobra_ffar_mp";
	if (index == 13)
		return "defaultweapon_mp";
	if (index == 14)
		return "destructible_car";
	if (index == 15)
		return "destructible_toy";
	if (index == 16)
		return "h1_ak47_mp";
	if (index == 17)
		return "h1_ak74u_mp";
	if (index == 18)
		return "h1_aprast_mp";
	if (index == 19)
		return "h1_aprpst_mp";
	if (index == 20)
		return "h1_aprsmg_mp";
	if (index == 21)
		return "h1_augast_mp";
	if (index == 22)
		return "h1_augpst_mp";
	if (index == 23)
		return "h1_augsmg_mp";
	if (index == 24)
		return "h1_barrett_mp";
	if (index == 25)
		return "h1_beretta_mp";
	if (index == 26)
		return "h1_c4_mp";
	if (index == 27)
		return "h1_claymore_mp";
	if (index == 28)
		return "h1_colt45_mp";
	if (index == 29)
		return "h1_coltanaconda_mp";
	if (index == 30)
		return "h1_concussiongrenade_mp";
	if (index == 31)
		return "h1_deserteagle55_mp";
	if (index == 32)
		return "h1_deserteagle_mp";
	if (index == 33)
		return "h1_dragunov_mp";
	if (index == 34)
		return "h1_fal_mp";
	if (index == 35)
		return "h1_feblmg_mp";
	if (index == 36)
		return "h1_febsmg_mp";
	if (index == 37)
		return "h1_febsnp_mp";
	if (index == 38)
		return "h1_flashgrenade_mp";
	if (index == 39)
		return "h1_fraggrenadeshort_mp";
	if (index == 40)
		return "h1_fraggrenade_mp";
	if (index == 41)
		return "h1_g36c_mp";
	if (index == 42)
		return "h1_g3_mp";
	if (index == 43)
		return "h1_galil_mp";
	if (index == 44)
		return "h1_janpst_mp";
	if (index == 45)
		return "h1_junlmg_mp";
	if (index == 46)
		return "h1_junsho_mp";
	if (index == 47)
		return "h1_junsnp_mp";
	if (index == 48)
		return "h1_kam12_mp";
	if (index == 49)
		return "h1_m1014_mp";
	if (index == 50)
		return "h1_m14_mp";
	if (index == 51)
		return "h1_m16_mp";
	if (index == 52)
		return "h1_m21_mp";
	if (index == 53)
		return "h1_m240_mp";
	if (index == 54)
		return "h1_m40a3_mp";
	if (index == 55)
		return "h1_m4_mp";
	if (index == 56)
		return "h1_m60e4_mp";
	if (index == 57)
		return "h1_mac10_mp";
	if (index == 58)
		return "h1_meleeapr1_mp";
	if (index == 59)
		return "h1_meleeapr2_mp";
	if (index == 60)
		return "h1_meleeapr3_mp";
	if (index == 61)
		return "h1_meleeapr4_mp";
	if (index == 62)
		return "h1_meleeaug1_mp";
	if (index == 63)
		return "h1_meleeaug2_mp";
	if (index == 64)
		return "h1_meleeaug3_mp";
	if (index == 65)
		return "h1_meleeaug4_mp";
	if (index == 66)
		return "h1_meleebayonet_mp";
	if (index == 67)
		return "h1_meleeblade_mp";
	if (index == 68)
		return "h1_meleebottle_mp";
	if (index == 69)
		return "h1_meleefeb1_mp";
	if (index == 70)
		return "h1_meleefeb2_mp";
	if (index == 71)
		return "h1_meleefeb3_mp";
	if (index == 72)
		return "h1_meleefeb4_mp";
	if (index == 73)
		return "h1_meleefeb5_mp";
	if (index == 74)
		return "h1_meleefuture1_mp";
	if (index == 75)
		return "h1_meleefuture2_mp";
	if (index == 76)
		return "h1_meleegladius_mp";
	if (index == 77)
		return "h1_meleehatchet_mp";
	if (index == 78)
		return "h1_meleeicepick_mp";
	if (index == 79)
		return "h1_meleejun1_mp";
	if (index == 80)
		return "h1_meleejun2_mp";
	if (index == 81)
		return "h1_meleejun3_mp";
	if (index == 82)
		return "h1_meleejun4_mp";
	if (index == 83)
		return "h1_meleejun5_mp";
	if (index == 84)
		return "h1_meleejun6_mp";
	if (index == 85)
		return "h1_meleepaddle_mp";
	if (index == 86)
		return "h1_meleeshovel_mp";
	if (index == 87)
		return "h1_meleesickle_mp";
	if (index == 88)
		return "h1_mp44_mp";
	if (index == 89)
		return "h1_mp5_mp";
	if (index == 90)
		return "h1_p90_mp";
	if (index == 91)
		return "h1_pp2000_mp";
	if (index == 92)
		return "h1_remington700_mp";
	if (index == 93)
		return "h1_rpd_mp";
	if (index == 94)
		return "h1_rpg_mp";
	if (index == 95)
		return "h1_saw_mp";
	if (index == 96)
		return "h1_skorpion_mp";
	if (index == 97)
		return "h1_smokegrenade_mp";
	if (index == 98)
		return "h1_striker_mp";
	if (index == 99)
		return "h1_usp_mp";
	if (index == 100)
		return "h1_uzi_mp";
	if (index == 101)
		return "h1_vssvintorez_mp";
	if (index == 102)
		return "h1_winchester1200_mp";
	if (index == 103)
		return "h1_xmlar_mp";
	if (index == 104)
		return "helicopter_mp";
	if (index == 105)
		return "hind_ffar_mp";
	if (index == 106)
		return "radar_mp";
	else
		return "defaultweapon_mp";
}

int MeansOfDeathForIndex(int index) {
	if (index == 0)
		return meansOfDeath_t::MOD_UNKNOWN;
	if (index == 1)
		return meansOfDeath_t::MOD_HEAD_SHOT;
	if (index == 2)
		return meansOfDeath_t::MOD_MELEE;
	if (index == 3)
		return meansOfDeath_t::MOD_FALLING;
	if (index == 4)
		return meansOfDeath_t::MOD_IMPACT;
	if (index == 5)
		return meansOfDeath_t::MOD_SUICIDE;
	else
		return meansOfDeath_t::MOD_UNKNOWN;
}

const char *MeansOfDeathDisplayNameForIndex(int index) {
	if (index == 0)
		return "Default";
	if (index == 1)
		return "Headshot";
	if (index == 2)
		return "Melee";
	if (index == 3)
		return "Falling";
	if (index == 4)
		return "Impact";
	if (index == 5)
		return "Suicide";
	else
		return "Default";
}

const char *GetRawWeaponNameForIndex(int id) {
	return (char *)(*(long long *)(*(long long *)(bg_weaponCompleteDefs + ((id * 8) & 0x3FC)) + 0x10));
}

const char *GetWeaponNameForIndex(int id) {
	return "";//UI_SafeTranslateString(GetRawWeaponNameForIndex(id));
}

uint64_t GetTTFForFont(uint64_t font) {
	return *(uint64_t *)(font + 0x08);
}

bool WorldToScreen(float *worldLocation, float *screen) {
	float local[3];
	float transform[3];

	local[0] = worldLocation[0] - cg.refdef.vieworg[0];
	local[1] = worldLocation[1] - cg.refdef.vieworg[1];
	local[2] = worldLocation[2] - cg.refdef.vieworg[2];

	transform[0] = DotProduct(local, cg.refdef.viewaxis[1]);
	transform[1] = DotProduct(local, cg.refdef.viewaxis[2]);
	transform[2] = DotProduct(local, cg.refdef.viewaxis[0]);

	if (transform[2] < 0.01f)
		return false;

	screen[0] = (cg.refdef.width / 2) * (1.0f - (transform[0] / cg.refdef.tanHalfFovX / transform[2]));
	screen[1] = (cg.refdef.height / 2) * (1.0f - (transform[1] / cg.refdef.tanHalfFovY / transform[2]));

	return (transform[2] > 0);
}

void OffHost_EndGame() {
	char temp[100];
	snprintf(temp, sizeof(temp), "cmd mrp %i 13 8 0", clientActive.serverId);
	Cbuf_AddText((LocalClientNum_t)0, temp);
}

void SendConsoleCommand() {
	OpenKeyboardDialog(100, "Console Command");
	Cbuf_AddText((LocalClientNum_t)0, sceImeKeyboardRetVal);
}

bool gameEnded = false;
void PreventCrash() {
	gameEnded = true;
	Sleep(5000);
	gameEnded = false;
}

bool InGame() {
	return *(bool *)(*(uint64_t *)cl_ingame + dvar_s_current);
}

const char *GetRawGametype() {
	return cgs.gametype;
}

const char *GetRawMapname() {
	return cgs.mapname;
}

void DrawText(const char *text, float x, float y, float fontSize, float *color, Font_s *font) {
	AddBaseDrawTextCmd(text, 0x7FFFFFFF, font, font->pixelHeight, x, y, fontSize, fontSize, 0.0f, color, 0, -1, 0, 0);
}

void DrawText(const char *text, float x, float y, float fontSize, float *color, const char *font) {
	Font_s *_font = R_RegisterFont(font, 0x1B, 0);
	AddBaseDrawTextCmd(text, 0x7FFFFFFF, _font, _font->pixelHeight, x, y, fontSize, fontSize, 0.0f, color, 0, -1, 0, 0);
}

void DrawText(const char *text, float x, float y, float fontSize, float *color) {
	Font_s *_font = R_RegisterFont(FontForIndex(-1), 0x1B, 0);
	AddBaseDrawTextCmd(text, 0x7FFFFFFF, _font, _font->pixelHeight, x, y, fontSize, fontSize, 0.0f, color, 0, -1, 0, 0);
}

void DrawShader(float x, float y, float width, float height, float *color, Material *material) {
	CG_DrawRotatedPicPhysical(ScrPlace, x, y, width, height, 0.0f, color, material);
}

void DrawShader(float x, float y, float width, float height, float *color, const char *material) {
	CG_DrawRotatedPicPhysical(ScrPlace, x, y, width, height, 0.0f, color, Material_RegisterHandle(material, 0));
}

void DrawShader(float x, float y, float width, float height, float *color) {
	CG_DrawRotatedPicPhysical(ScrPlace, x, y, width, height, 0.0f, color, Material_RegisterHandle("white", 0));
}

void DrawCenterTextWithBackground(const char *text, float x, float y, float fontSize, float *color, float *backgroundColor, Font_s *font) {
	float textWidth = R_TextWidth(text, 0x7FFFFFFF, font) * fontSize;
	float textHeight = R_TextHeight(font) * fontSize;

	DrawShader(x - textWidth / 2, y - textHeight / 2, textWidth, textHeight, backgroundColor);
	DrawText(text, x - textWidth / 2, y + textHeight / 2, fontSize, color, font);
}

void DrawCenterTextWithBackground(const char *text, float x, float y, float fontSize, float *color, float *backgroundColor, const char *font) {
	float textWidth = R_TextWidth(text, 0x7FFFFFFF, R_RegisterFont(font, 0, 0)) * fontSize;
	float textHeight = R_TextHeight(R_RegisterFont(font, 0, 0)) * fontSize;

	DrawShader(x - textWidth / 2, y - textHeight / 2, textWidth, textHeight, backgroundColor);
	DrawText(text, x - textWidth / 2, y + textHeight / 2, fontSize, color, font);
}

void DrawCenterTextWithBackground(const char *text, float x, float y, float fontSize, float *color, float *backgroundColor) {
	float textWidth = R_TextWidth(text, 0x7FFFFFFF, R_RegisterFont(FontForIndex(-1), 0, 0)) * fontSize;
	float textHeight = R_TextHeight(R_RegisterFont(FontForIndex(-1), 0, 0)) * fontSize;

	DrawShader(x - textWidth / 2, y - textHeight / 2, textWidth, textHeight, backgroundColor);
	DrawText(text, x - textWidth / 2, y + textHeight / 2, fontSize, color);
}

void DrawCenterTextWithBackgroundWithBorder(const char *text, float x, float y, float *color, float fontSize, float *backgroundColor, int borderSize, float *borderColor) {
	float textWidth = R_TextWidth(text, 0x7FFFFFFF, R_RegisterFont(FontForIndex(-1), 0, 0)) * fontSize;
	float textHeight = R_TextHeight(MENU_FONT) * fontSize;

	//UI_FillRectPhysical(x - 4 - textWidth / 2, y - (textHeight * 0.2f) - borderSize - textHeight / 2, textWidth + 8, textHeight + (textHeight * 0.2f), backgroundColor);
	//UI_FillRectPhysical(x - 4 - borderSize - textWidth / 2, y - (textHeight * 0.2f) - borderSize * 2 - textHeight / 2, borderSize, textHeight + (textHeight * 0.2f) + 2 * borderSize, borderColor); //left
	//UI_FillRectPhysical(x + 4 + textWidth / 2, y - (textHeight * 0.2f) - borderSize * 2 - textHeight / 2, borderSize, textHeight + (textHeight * 0.2f) + 2 * borderSize, borderColor); //right
	//UI_FillRectPhysical(x - 4 - textWidth / 2, y - (textHeight * 0.2f) - borderSize * 2 - textHeight / 2, textWidth + 8, borderSize, borderColor); //top
	//UI_FillRectPhysical(x - 4 - textWidth / 2, y - borderSize + textHeight / 2, textWidth + 8, borderSize, borderColor); //bottom
	//UI_DrawText(ScrPlace, text, 0x7FFFFFFF, MENU_FONT, x - textWidth / 2, y - borderSize + textHeight / 2, 0, 0, fontSize, color, 0, LocalClientNum_t::LOCAL_CLIENT_0);
}

void DrawLine(float x1, float y1, float x2, float y2, float width, float *color) {
	float x, y, angle, L1, L2, H1;
	H1 = y2 - y1;
	L1 = x2 - x1;
	L2 = sqrt(L1 * L1 + H1 * H1);
	x = x1 + ((L1 - L2) / 2);
	y = y1 + (H1 / 2);
	angle = (float)atan(H1 / L1) * (180.0f / MATH_PI);
	CG_DrawRotatedPicPhysical(ScrPlace, x, y, L2, width, angle, color, Material_RegisterHandle("white", 0));
}
