#pragma once

#include "defines.h"
#include "sparse.h"

typedef unsigned short scr_entref_t;
typedef unsigned short scr_string_t;

//

enum GfxRenderCommand {
	//...
};

enum ConfigString {
	//...
};

enum he_type_t {
	HE_TYPE_FREE = 0x00,
	HE_TYPE_TEXT = 0x01,
	HE_TYPE_VALUE = 0x02,
	HE_TYPE_PLAYERNAME = 0x03,
	HE_TYPE_MATERIAL = 0x04,
	HE_TYPE_TIMER_DOWN = 0x05,
	HE_TYPE_TIMER_UP = 0x06,
	HE_TYPE_TIMER_STATIC = 0x07,
	HE_TYPE_TENTHS_TIMER_DOWN = 0x08,
	HE_TYPE_TENTHS_TIMER_UP = 0x09,
	HE_TYPE_TENTHS_TIMER_STATIC = 0x0A,
	HE_TYPE_CLOCK_DOWN = 0x0B,
	HE_TYPE_CLOCK_UP = 0x0C,
	HE_TYPE_WAYPOINT = 0x0D,
	HE_TYPE_COUNT = 0x0E
};


enum LocalClientNum_t : int {
	INVALID_LOCAL_CLIENT = -1,
	LOCAL_CLIENT_0 = 0,
	LOCAL_CLIENT_FIRST = 0,
	LOCAL_CLIENT_1 = 1,
	LOCAL_CLIENT_2 = 2,
	LOCAL_CLIENT_3 = 3,
	LOCAL_CLIENT_COUNT = 5
};

enum LUI_QuadRenderMode {
	//...
};

enum svscmd_type {
	SV_CMD_CAN_IGNORE = 0,
	SV_CMD_RELIABLE = 1
};

enum XAssetType
{
	//ASSET_TYPE_PHYSPRESET = 0x00,
	//ASSET_TYPE_PHYSCOLLMAP = 0x01,
	//ASSET_TYPE_PHYSWATERPRESET = 0x02,
	//...   //0000000000668EA0 -> 2 unknown types, even in the pdb
	ASSET_TYPE_XANIMPARTS = 0x05,
	//ASSET_TYPE_XMODEL_SURFS = 0x06,
	ASSET_TYPE_XMODEL = 0x07, //PlayerCmd_SetViewmodel + 0x119   mov edi, 7
	ASSET_TYPE_MATERIAL = 0x08,
	ASSET_TYPE_COMPUTESHADER = 0x09,
	//ASSET_TYPE_VERTEXSHADER = 0x0A,
	//ASSET_TYPE_HULLSHADER = 0x0B,
	//ASSET_TYPE_DOMAINSHADER = 0x0C,
	//ASSET_TYPE_PIXELSHADER = 0x0D,
	//ASSET_TYPE_TECHNIQUE_SET = 0x0E,
	//ASSET_TYPE_IMAGE = 0x0F,
	ASSET_TYPE_SOUND = 0x10, //ParseConfigStringToStruct + 0x7C9   mov edi, 10h
	//ASSET_TYPE_SOUND_CURVE = 0x11,
	//ASSET_TYPE_LPF_CURVE = 0x12,
	//ASSET_TYPE_REVERB_CURVE = 0x13,
	//ASSET_TYPE_LOADED_SOUND = 0x14,
	//ASSET_TYPE_CLIPMAP = 0x15,
	//ASSET_TYPE_COMWORLD = 0x16,
	//ASSET_TYPE_GLASSWORLD = 0x19, ///G_InitGlass + 0x42   mov edi, 19h
	//ASSET_TYPE_PATHDATA = 0x1A,
	//ASSET_TYPE_VEHICLE_TRACK = 0x1B,
	ASSET_TYPE_MAP_ENTS = 0x1C,
	//ASSET_TYPE_FXWORLD = 0x1D, ///FX_LoadWorld + 0x07   mov edi, 1Dh
	//ASSET_TYPE_GFXWORLD = 0x1E,
	//ASSET_TYPE_LIGHT_DEF = 0x1F, ///R_InitLightDefs + 0x0B   mov edi, 1Fh
	//ASSET_TYPE_UI_MAP = 0x20,
	//ASSET_TYPE_FONT = 0x21, ///R_RegisterFont + 0x0C   mov edi, 21h
	//ASSET_TYPE_MENULIST = 0x22,
	//ASSET_TYPE_MENU = 0x23, ///UI_DrawMapLevelshot + 0x16   mov edi, 23h
	//ASSET_TYPE_ANIMCLASS = 0x24,
	ASSET_TYPE_LOCALIZE_ENTRY = 0x24,
	//ASSET_TYPE_ATTACHMENT = 0x22,
	//ASSET_TYPE_WEAPON = 0x23,
	//ASSET_TYPE_SNDDRIVER_GLOBALS = 0x28, ///SND_Init + 0xC4A   mov edi, 28h
	ASSET_TYPE_FX = 0x28, //ParseConfigStringToStruct + 0x738   mov edi, 28h
	//ASSET_TYPE_IMPACT_FX = 0x26,
	//ASSET_TYPE_SURFACE_FX = 0x27,
	//ASSET_TYPE_AITYPE = 0x28,
	//ASSET_TYPE_MPTYPE = 0x29,
	//ASSET_TYPE_CHARACTER = 0x2A,
	//ASSET_TYPE_XMODELALIAS = 0x2B,
	//ASSET_TYPE_RAWFILE = 0x30,
	//ASSET_TYPE_SCRIPTFILE = 0x31,
	ASSET_TYPE_STRINGTABLE = 0x31, //SV_BotPathsInit + 0xAA   mov edi, 31h
	ASSET_TYPE_LEADERBOARD = 0x32, //LB_OpenLeaderboardExt + 0x10   mov edi, 32h
	//ASSET_TYPE_STRUCTURED_DATA_DEF = 0x34,
	ASSET_TYPE_TRACER = 0x37, //ParseConfigStringToStruct + 0x8D4   mov edi, 37h
	ASSET_TYPE_VEHICLE = 0x38, //Vehicle_LoadServerDefAssets + 0x21   mov edi, 38h
	//ASSET_TYPE_ADDON_MAP_ENTS = 0x33,
	//ASSET_TYPE_NET_CONST_STRINGS = 0x34,
	//ASSET_TYPE_REVERB_PRESET = 0x39, ///LoadReverbPreset + 0x13   mov edi, 39h
	//ASSET_TYPE_LUA_FILE = 0x35,
	//ASSET_TYPE_SCRIPTABLE = 0x37,
	//ASSET_TYPE_COLORIZATION = 0x38,
	//ASSET_TYPE_COLORIZATIONSET = 0x39,
	//ASSET_TYPE_TONEMAPPING = 0x3A,
	//ASSET_TYPE_EQUIPMENT_SND_TABLE = 0x3B,
	//ASSET_TYPE_VECTORFIELD = 0x3C,
	//ASSET_TYPE_DOPPLER_PRESET = 0x3E, ///LoadDopplerPreset + 0x13   mov edi, 3Eh
	//ASSET_TYPE_PARTICLE_SIM_ANIMATION = 0x3E,
	//ASSET_TYPE_COUNT = 0x3F,
	//ASSET_TYPE_STRING = 0x3F,
	//ASSET_TYPE_ASSETLIST = 0x40,
	ASSET_TYPE_LASER = 0x42, //ParseConfigStringToStruct + 0x876   mov edi, 42h
	//...
	ASSET_TYPE_TTF = 0x45 //R_RegisterFont + 0xB0   mov edi, 45h
};

//

struct client_t {
	//...
};

struct CmdArgs {
	//...
};

struct CmdArgsPrivate {
	//...
};

struct Font_s { // 0x18
	const char *name;	//0x00
	int pixelHeight;	//0x08
	char _pad0[0x01];	//0x0C
	uintptr_t glow;		//0x10
};

struct FontGlowStyle {
	//...
};

struct usercmd_s { // 0x44 AW
	int time;		//0x00 //NOT UPDATED
	int buttons;	//0x04 //NOT UPDATED
	//...
};

struct gclient_s {
	//mwr:
	//0x5C fof flag
	//...
	char _pad0[0x02];	//0x00
	char mFlag[4];		//0x02
	//...
	int serverTime;		//0x4C //NOT UPDATED
	//...
	usercmd_s *ucmd;	//0x4F9C //NOT UPDATED
	usercmd_s *olducmd;	//0x4FE0 //NOT UPDATED
	//...
};

struct gentity_s { // 0x2E0
	//mwr:
	//0x3C viewmodel
	short number;			//0x00 //NOT UPDATED
	short type;				//0x02 //NOT UPDATED
	char _pad0[0x88];		//0x04
	float angles[3];		//0x8C //NOT UPDATED //0x144 ???
	char _pad1[0xA0];		//0x98
	float origin[3];		//0x138
	char _pad2[0x14];		//0x144
	gclient_s *client;		//0x158
	char _pad3[0x28];		//0x160
	short modelIndex;		//0x188
	char _pad4[0x0A];		//0x18A
	int classname;			//0x194   //ScriptEntCmd_Solid + 0x5F   mov eax, [rbx+194h]  //NOT UPDATED
	int script_classname;	//0x198 //NOT UPDATED
	int script_linkName;	//0x19C //NOT UPDATED
	int target;				//0x1A0 //NOT UPDATED
	int targetname;			//0x1A4 //NOT UPDATED
	int u1;					//0x1A8 //NOT UPDATED
	int spawnflags;			//0x1AC //NOT UPDATED
	//...
	int health;				//0x1D0 //NOT UPDATED
	int maxHealth;			//0x1D4 //NOT UPDATED
	//...
};

struct GfxCmdDrawText2D {
	//...
};

struct HksObject {
	//...
};

struct lua_State {
	//...
};

struct Material { // 0x338 AW
	const char *name;	//0x00 //NOT UPDATED
	//...
};

struct LUIElement {
	uintptr_t u1;
	uintptr_t u2;
	uintptr_t u3;
	uintptr_t u4;
	int u5;
	float width;		//0x24 //NOT UPDATED
	float height;		//0x28 //NOT UPDATED
	float u6;
	float x1;			//0x30 //NOT UPDATED
	float y1;			//0x34 //NOT UPDATED
	float x2;			//0x38 //NOT UPDATED
	float y2;			//0x3C //NOT UPDATED
	char _pad0[0x40];	//0x40 //NOT UPDATED
	Material *material;	//0x80 //NOT UPDATED
	Font_s *font;		//0x88 //NOT UPDATED
	//...
};

struct playerState_s {
	gclient_s client;
};

struct RootUserData {
	//...
};

struct trace_t {
	char _pad0[0x200];
	//...
};

struct UiContext { //0x44F0
	char _pad0[0x08];	//0x00
	int time;			//0x08
	char _pad1[0x14];	//0x0C
	int screenWidth;	//0x20
	int screenHeight;	//0x24
	float aspectRatio;	//0x28
	float fps;			//0x2C
	//...
};

union VariableUnion {
	int intValue;
	int uintValue;
	float floatValue;
	int stringValue;
	void *vectorValue;
	void *codePosValue;
	int pointerValue;
	void *stackValue;
	int entityOffset;
};

struct VariableValue {
	VariableUnion u;
	int type;
};









//OLD STUFF BELOW

enum eFlag_t {
	ENTITY_FLAG_CROUCHED = 0x04,
	ENTITY_FLAG_PRONE = 0x08,
	ENTITY_FLAG_SPRINTING = 0x20000,
	ENTITY_FLAG_MANTLEING = 0x28000,
	ENTITY_FLAG_ADS = 0x80000
};

enum eModes : int {
	MODE_ZOMBIES = 0x0,
	MODE_MULTIPLAYER = 0x1,
	MODE_CAMPAIGN = 0x2,
	MODE_WARZONE = 0x3,
	MODE_COUNT = 0x4,
	MODE_INVALID = 0x4,
	MODE_FIRST = 0x0,
};


enum ucmdButtonFlag_t {
	UCMD_BTN_R2 = 0x80000000,
};

enum entityType_t {
	ET_GENERAL = 0x00,
	ET_PLAYER = 0x01,
	ET_PLAYER_CORPSE = 0x02, //
	ET_ITEM = 0x03, //
	ET_MISSILE = 0x04,
	ET_PLAYER_INVISIBLE = 0x05, //
	ET_SCRIPTMOVER = 0x06,
	//ET_SOUND_BLEND = 0x07, //
	//ET_FX = 0x08, //
	//ET_LOOP_FX = 0x09, //
	//ET_PRIMARY_LIGHT = 0x0A, //
	//ET_LENSFLARE = 0x0B, //
	//ET_REFLECTION_PROBE = 0x0C, //
	//ET_HELICOPTER = 0x0D, //
	//ET_PLANE = 0x0E, //
	ET_VEHICLE = 0x0C,
	//ET_VEHICLE_SPAWNER = 0x10, //
	//ET_VEHICLE_CORPSE = 0x11, //
	ET_ACTOR = 0x0F,
	ET_ACTOR_SPAWNER = 0x10,
	ET_ACTOR_CORPSE = 0x11,
	ET_STREAMER_HINT = 0x12, //
	ET_ZBARRIER = 0x13,
	ET_TRIGGER = 0x14, //
	ET_EVENTS = 0x18 //
};

struct ScreenPlacement //size = 0x74 //mwr size = 0x6C ?
{
	float scaleVirtualToReal[2];	//0x00
	float scaleVirtualToFull[2];	//0x08
	float scaleRealToVirtual[2];	//0x10
	float virtualViewableMin[2];	//0x18
	float virtualViewableMax[2];	//0x20
	float virtualTweakableMin[2];	//0x28
	float virtualTweakableMax[2];	//0x30
	float realViewportBase[2];		//0x38
	float realViewportSize[2];		//0x40
	float realViewportMid[2];		//0x48
	float realViewableMin[2];		//0x50
	float realViewableMax[2];		//0x58
	float realTweakableMin[2];		//0x60
	float realTweakableMax[2];		//0x68
	float hudSplitscreenScale;		//0x70
};


//


struct clientInfo_t {
	int clientNum;
	int team;
	const char *name;
	short health;
	short maxHealth;
};

struct refdef_t {
	int width;
	int height;
	int sceneResolutionIndex;
	int sceneResolutionIndexHistory[4];
	float tanHalfFovX;
	float tanHalfFovY;
	float vieworg[3];
	float lastvieworg[3];
	float viewaxis[3][3];
	int frametime;
	int time;
};

struct cg_t {
	int clientNum;
	int localClientNum;
	int ping;
	float origin[3];
	clientInfo_t clientInfo[18];
	refdef_t refdef;
};


//


struct cgs_t {
	int screenWidth;
	int screenHeight;
	float aspectRatio;
	const char *gametype;
	const char *hostname;
	int maxClients;
	const char *mapname_d3dbsp;
	const char *mapname;
};


//


struct LerpEntityState_t {
	int eFlags;
	int eFlags2;
	float origin[3];
	float viewAngles[3];
};

struct entityState_t {
	int number;
	LerpEntityState_t lerp;
	short eType;
};

struct centity_t {
	float origin[3];
	float viewAngles[3];
	int state;
	int stateFlag;
	int weapon;
	entityState_t nextState;
	int alive;
	uint64_t __address;
};


//


struct game_button_bits_t {
	int array[3];
};

struct usercmd_t {
	int serverTime;
	game_button_bits_t button_bits;
	int angles[3];
	char forwardmove;
	char rightmove;
	int weapon;
	uint64_t __index;
};

struct clientActive_t {
	float deltaAngles[3];
	int serverId;
	const char *mapname;
	float viewangles[3];
	usercmd_t cmds[128];
	int cmdNumber;
};


//

extern cg_t cg;
extern cgs_t cgs;
extern centity_t centity[2048];
extern clientActive_t clientActive;

void ReadStructs();

bool IsAlive(int i);
