#pragma once

#define Leveltime *(int *)(0x000000000B0FE8B0 + 0x524) //level_locals_t + 0x524

union hudelem_color_t {
	struct {
		char r;
		char g;
		char b;
		char a;
	};
	int rgba;
};

struct hudelem_s {
	short targetEnt1;			//0x00
	short targetEnt2;			//0x02
	int font;					//0x04
	int alignOrg;				//0x08
	int alignScreen;			//0x0C
	float x;					//0x10
	float y;					//0x14
	float z;					//0x18
	int type;					//0x1C
	float fontScale;			//0x20
	int fromFontScale;			//0x24
	int fontScaleStartTime;		//0x28
	int fontScaleTime;			//0x2C
	hudelem_color_t color;		//0x30
	hudelem_color_t fromColor;	//0x34
	int fadeStartTime;			//0x38
	int fadeTime;				//0x3C
	int label;					//0x40
	int width;					//0x44
	int height;					//0x48
	int materialIndex;			//0x4C
	int fromWidth;				//0x50
	int fromHeight;				//0x54
	int moveStartTime;			//0x58
	int moveTime;				//0x5C
	float fromX;				//0x60
	float fromY;				//0x64
	int fromAlignOrg;			//0x68
	int fromAlignScreen;		//0x6C
	int scaleStartTime;			//0x70
	int scaleTime;				//0x74
	int time;					//0x78
	int duration;				//0x7C
	float value;				//0x80
	int text;					//0x84
	float sort;					//0x88
	hudelem_color_t glowColor;	//0x8C
	int fxBirthTime;			//0x90
	int fxLetterTime;			//0x94
	int fxDecayStartTime;		//0x98
	int fxDecayDuration;		//0x9C
	int soundID;				//0xA0
	int u1;						//0xA4
	int flags;					//0xA8
	int u2;						//0xAC
	int u3;						//0xB0
	int u4;						//0xB4
	int index;					//0xB8
	int u6;						//0xBC
};

struct game_hudelem_s { //0xD0
	hudelem_s elem;		//0x00
	int clientNum;		//0xC0
	int team;			//0xC4
	int archived;		//0xC8
	int showInKillcam;	//0xCC
};

struct Hud {  //NOT CHECKED
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
