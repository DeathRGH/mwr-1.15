#include "host_huds.h"
#include "functions.h"

Hud::Hud(game_hudelem_s *elem) {
    element = elem;
}

game_hudelem_s *PrecacheElem(int clientId) {
    game_hudelem_s *elem = HudElem_Alloc(clientId, 0);
    elem->clientNum = clientId;
    return elem;
}

void Hud::SetShader(const char *shader, int width, int height, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    element->elem.type = 0x04;
    element->elem.alignOrg = alignOrg;
    element->elem.alignScreen = alignScreen;
    element->elem.x = x;
    element->elem.y = y;
    element->elem.color.r = r;
    element->elem.color.g = g;
    element->elem.color.b = b;
    element->elem.color.a = a;
    element->elem.width = width;
    element->elem.height = height;
    element->elem.sort = sort;
    element->elem.materialIndex = G_MaterialIndex(shader);
}

void Hud::SetText(const char *text, int font, float fontScale, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned char glowR, unsigned char glowG, unsigned char glowB, unsigned char glowA) {
    element->elem.type = 0x01;
    element->elem.font = font;
    element->elem.fontScale = fontScale;
    element->elem.alignOrg = alignOrg;
    element->elem.alignScreen = alignScreen;
    element->elem.x = x;
    element->elem.y = y;
    element->elem.color.r = r;
    element->elem.color.g = g;
    element->elem.color.b = b;
    element->elem.color.a = a;
    element->elem.glowColor.r = glowR;
    element->elem.glowColor.g = glowG;
    element->elem.glowColor.b = glowB;
    element->elem.glowColor.a = glowA;
    element->elem.sort = sort;
    element->elem.text = G_LocalizedStringIndex(text);
    element->elem.targetEnt1 = 0x01;
    element->elem.targetEnt2 = 0x01;
}

void Hud::MoveOverTime(float time, float x, float y) {
    element->elem.fromX = element->elem.x;
    element->elem.fromY = element->elem.y;
    element->elem.moveStartTime = Leveltime;
    element->elem.moveTime = time;
    element->elem.x = x;
    element->elem.y = y;
}

void Hud::SetY(float y) {
    element->elem.y = y;
}

void Hud::ChangeText(const char *text) {
    element->elem.text = G_LocalizedStringIndex(text);
}

void Hud::ScaleOverTime(float time, float width, float height) {
    element->elem.fromWidth = element->elem.width;
    element->elem.fromHeight = element->elem.height;
    element->elem.scaleStartTime = Leveltime;
    element->elem.scaleTime = time;
    element->elem.width = width;
    element->elem.height = height;
}

void Hud::FadeOverTime(int time, float red, float green, float blue, float alpha) {
    element->elem.fromColor = element->elem.color;
    element->elem.fadeStartTime = Leveltime;
    element->elem.fadeTime = time;
    element->elem.color.r = red;
    element->elem.color.g = green;
    element->elem.color.b = blue;
    element->elem.color.a = alpha;
}

void Hud::SetColor(char r, char g, char b, char a, bool isGlow) {
    if (isGlow) {
        element->elem.glowColor.r = r;
        element->elem.glowColor.g = g;
        element->elem.glowColor.b = b;
        element->elem.glowColor.a = a;
    }
    else {
        element->elem.color.r = r;
        element->elem.color.g = g;
        element->elem.color.b = b;
        element->elem.color.a = a;
    }
}

void Hud::TypeWriterText(const char *text) {
    ChangeText(text);
    element->elem.fxBirthTime = Leveltime;
    element->elem.fxLetterTime = 100;
    element->elem.fxDecayStartTime = 7000;
    element->elem.fxDecayDuration = 1000;
    element->elem.flags |= 0x04;
}
