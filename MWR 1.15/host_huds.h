#pragma once

#define Leveltime *(int *)(0x6395980 + 0x4EC)

union hudelem_color_t {
    struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };
    int rgba;
};

struct hudelem_s {
	short targetEnt1;
    short targetEnt2;
    int font;
    int alignOrg;
    int alignScreen;
    float x;
    float y;
    float z;
    int type;
    float fontScale;
    int fromFontScale;
    int fontScaleStartTime;
    int fontScaleTime;
    hudelem_color_t color;
    hudelem_color_t fromColor;
    int fadeStartTime;
    int fadeTime;
    int label;
    int width;
    int height;
    int materialIndex;
    int fromWidth;
    int fromHeight;
    int moveStartTime;
    int moveTime;
    float fromX;
    float fromY;
    int fromAlignOrg;
    int fromAlignScreen;
    int scaleStartTime;
    int scaleTime;
    int time;
    int duration;
    float value;
    int text;
    float sort;
    hudelem_color_t glowColor;
    int fxBirthTime;
    int fxLetterTime;
    int fxDecayStartTime;
    int fxDecayDuration;
    int soundID;
    int unknown;
    int flags;
};

struct game_hudelem_s {
    hudelem_s elem;
    int clientNum;
    int team;
    int archived;
    int showInKillcam;
};

struct Hud {
    Hud(game_hudelem_s *element);
    void SetShader(const char *shader, int width, int height, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void SetText(const char *text, int font, float fontScale, float x, float y, int alignOrg, int alignScreen, float sort, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned char glowR, unsigned char glowG, unsigned char glowB, unsigned char glowA);
    void MoveOverTime(float time, float x, float y);
    void SetY(float y);
    void ChangeText(const char *text);
    void ScaleOverTime(float time, float width, float height);
    void FadeOverTime(int time, float red, float green, float blue, float alpha);
    void SetColor(char r, char g, char b, char a, bool isGlow);
    void TypeWriterText(const char *text);
    game_hudelem_s *element;
};

extern game_hudelem_s *PrecacheElem(int clientId);

typedef struct hudelem_s *hudelem_t;
typedef struct game_hudelem_s *game_hudelem_t;
