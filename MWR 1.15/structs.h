#pragma once

#include "defines.h"
#include "sparse.h"

typedef unsigned short scr_entref_t;
typedef unsigned short scr_string_t;

//

enum GfxRenderCommand {
	//...
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
	ASSET_TYPE_PHYSPRESET = 0x00,
	ASSET_TYPE_PHYSCOLLMAP = 0x01,
	ASSET_TYPE_PHYSWATERPRESET = 0x02,
	//...   //0000000000668EA0 -> 2 unknown types, even in the pdb
	ASSET_TYPE_XANIMPARTS = 0x05,
	ASSET_TYPE_XMODEL_SURFS = 0x06,
	ASSET_TYPE_XMODEL = 0x07,
	ASSET_TYPE_MATERIAL = 0x08,
	ASSET_TYPE_COMPUTESHADER = 0x09,
	ASSET_TYPE_VERTEXSHADER = 0x0A,
	ASSET_TYPE_HULLSHADER = 0x0B,
	ASSET_TYPE_DOMAINSHADER = 0x0C,
	ASSET_TYPE_PIXELSHADER = 0x0D,
	ASSET_TYPE_TECHNIQUE_SET = 0x0E,
	ASSET_TYPE_IMAGE = 0x0F,
	ASSET_TYPE_SOUND = 0x10, //Com_TryFindSoundAlias + 0x1B   mov edi, 10h
	//ASSET_TYPE_SOUND_CURVE = 0x11,
	//ASSET_TYPE_LPF_CURVE = 0x12,
	//ASSET_TYPE_REVERB_CURVE = 0x13,
	//ASSET_TYPE_LOADED_SOUND = 0x14,
	//ASSET_TYPE_CLIPMAP = 0x15,
	//ASSET_TYPE_COMWORLD = 0x16,
	ASSET_TYPE_GLASSWORLD = 0x19, //G_InitGlass + 0x42   mov edi, 19h
	ASSET_TYPE_PATHDATA = 0x1A,
	ASSET_TYPE_VEHICLE_TRACK = 0x1B,
	ASSET_TYPE_MAP_ENTS = 0x1C,
	ASSET_TYPE_FXWORLD = 0x1D, //FX_LoadWorld + 0x07   mov edi, 1Dh
	ASSET_TYPE_GFXWORLD = 0x1E,
	ASSET_TYPE_LIGHT_DEF = 0x1F, //R_InitLightDefs + 0x0B   mov edi, 1Fh
	//ASSET_TYPE_UI_MAP = 0x20,
	ASSET_TYPE_FONT = 0x21, //R_RegisterFont + 0x0C   mov edi, 21h
	ASSET_TYPE_MENULIST = 0x22,
	ASSET_TYPE_MENU = 0x23, //UI_DrawMapLevelshot + 0x16   mov edi, 23h
	//ASSET_TYPE_ANIMCLASS = 0x24,
	ASSET_TYPE_LOCALIZE_ENTRY = 0x25, //SEH_StringEd_GetString + 0x33   mov edi, 25h
	//ASSET_TYPE_ATTACHMENT = 0x22,
	//ASSET_TYPE_WEAPON = 0x23,
	ASSET_TYPE_SNDDRIVER_GLOBALS = 0x28, //SND_Init + 0xC4A   mov edi, 28h
	ASSET_TYPE_FX = 0x29, //FX_Register + 0x03   mov edi, 29h
	//ASSET_TYPE_IMPACT_FX = 0x26,
	//ASSET_TYPE_SURFACE_FX = 0x27,
	//ASSET_TYPE_AITYPE = 0x28,
	//ASSET_TYPE_MPTYPE = 0x29,
	//ASSET_TYPE_CHARACTER = 0x2A,
	//ASSET_TYPE_XMODELALIAS = 0x2B,
	ASSET_TYPE_RAWFILE = 0x30,
	ASSET_TYPE_SCRIPTFILE = 0x31,
	ASSET_TYPE_STRINGTABLE = 0x32,
	ASSET_TYPE_LEADERBOARD = 0x33,
	ASSET_TYPE_STRUCTURED_DATA_DEF = 0x34,
	ASSET_TYPE_TRACER = 0x35,
	ASSET_TYPE_VEHICLE = 0x36,
	//ASSET_TYPE_ADDON_MAP_ENTS = 0x33,
	//ASSET_TYPE_NET_CONST_STRINGS = 0x34,
	ASSET_TYPE_REVERB_PRESET = 0x39, //LoadReverbPreset + 0x13   mov edi, 39h
	//ASSET_TYPE_LUA_FILE = 0x35,
	//ASSET_TYPE_SCRIPTABLE = 0x37,
	//ASSET_TYPE_COLORIZATION = 0x38,
	//ASSET_TYPE_COLORIZATIONSET = 0x39,
	//ASSET_TYPE_TONEMAPPING = 0x3A,
	//ASSET_TYPE_EQUIPMENT_SND_TABLE = 0x3B,
	//ASSET_TYPE_VECTORFIELD = 0x3C,
	ASSET_TYPE_DOPPLER_PRESET = 0x3E, //LoadDopplerPreset + 0x13   mov edi, 3Eh
	//ASSET_TYPE_PARTICLE_SIM_ANIMATION = 0x3E,
	//ASSET_TYPE_COUNT = 0x3F,
	//ASSET_TYPE_STRING = 0x3F,
	//ASSET_TYPE_ASSETLIST = 0x40
};

//

struct CmdArgs {
	//...
};

struct CmdArgsPrivate {
	//...
};


struct Font_s { // 0x28
	const char *name;
	int height;
	int u1;
	uintptr_t u2;
	uintptr_t glow;
	uintptr_t u3;
};

struct usercmd_s { // 0x44
	int time;		//0x00
	int buttons;	//0x04
	//...
};

struct gclient_s {
	//...
	int serverTime;		//0x4C
	//...
	usercmd_s *ucmd;	//0x4F9C
	usercmd_s *olducmd;	//0x4FE0
	//...
};

struct gentity_s { // 0x2E0
	short number;			//0x00   //Scr_Notify + 0x04   movsx edi, word ptr [rdi]
	short type;				//0x02
	char _pad0[0x88];		//0x04
	float angles[3];		//0x8C
	char _pad1[0xA0];		//0x98
	float origin[3];		//0x138
	char _pad2[0x14];		//0x144
	gclient_s *client;		//0x158   //G_SetModel + 0x23   mov rbx, [r15+158h]
	char _pad3[0x28];		//0x160
	short modelIndex;		//0x188   //G_SetModel + 0x82   mov [r15+188h], ax
	char _pad4[0x0A];		//0x18A
	int classname;			//0x194   //ScriptEntCmd_Solid + 0x5F   mov eax, [rbx+194h]
	int script_classname;	//0x198
	int script_linkName;	//0x19C
	int target;				//0x1A0
	int targetname;			//0x1A4
	int u1;					//0x1A8
	int spawnflags;			//0x1AC
	//...
	int health;				//0x1D0
	int maxHealth;			//0x1D4
	//...
};

struct lua_State {
	//...
};

struct Material { // 0x338
	const char *name;
	//...
};

struct LUIElement {
	uintptr_t u1;
	uintptr_t u2;
	uintptr_t u3;
	uintptr_t u4;
	int u5;
	float width;		//0x24
	float height;		//0x28
	float u6;
	float x1;			//0x30
	float y1;			//0x34
	float x2;			//0x38
	float y2;			//0x3C
	char _pad0[0x40];	//0x40
	Material *material;	//0x80
	Font_s *font;		//0x88
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

struct UiContext {
	//...
};

union VariableUnion { //PDB, not tested
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

struct VariableValue { //PDB, not tested
	VariableUnion u;
	int type;
};










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

struct ScreenPlacement //size = 0x74
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
