#pragma once

#include "types.h"

#define NAMESPACE(x) namespace x {
#define END }

#define MATH_PI 3.14159265358979323846

#define AngleToShort(X) ((int)((X)*65536 / 360) & 65535)

extern float white01[4];
extern float white02[4];
extern float white03[4];
extern float white04[4];
extern float white05[4];
extern float white06[4];
extern float white07[4];
extern float white08[4];
extern float white09[4];
extern float white10[4];

extern float black01[4];
extern float black02[4];
extern float black03[4];
extern float black04[4];
extern float black05[4];
extern float black06[4];
extern float black07[4];
extern float black08[4];
extern float black09[4];
extern float black10[4];

extern float red01[4];
extern float red02[4];
extern float red03[4];
extern float red04[4];
extern float red05[4];
extern float red06[4];
extern float red07[4];
extern float red08[4];
extern float red09[4];
extern float red10[4];

extern float green01[4];
extern float green02[4];
extern float green03[4];
extern float green04[4];
extern float green05[4];
extern float green06[4];
extern float green07[4];
extern float green08[4];
extern float green09[4];
extern float green10[4];

extern float blue01[4];
extern float blue02[4];
extern float blue03[4];
extern float blue04[4];
extern float blue05[4];
extern float blue06[4];
extern float blue07[4];
extern float blue08[4];
extern float blue09[4];
extern float blue10[4];

extern float cyan01[4];
extern float cyan02[4];
extern float cyan03[4];
extern float cyan04[4];
extern float cyan05[4];
extern float cyan06[4];
extern float cyan07[4];
extern float cyan08[4];
extern float cyan09[4];
extern float cyan10[4];

extern float pink01[4];
extern float pink02[4];
extern float pink03[4];
extern float pink04[4];
extern float pink05[4];
extern float pink06[4];
extern float pink07[4];
extern float pink08[4];
extern float pink09[4];
extern float pink10[4];

extern float yellow01[4];
extern float yellow02[4];
extern float yellow03[4];
extern float yellow04[4];
extern float yellow05[4];
extern float yellow06[4];
extern float yellow07[4];
extern float yellow08[4];
extern float yellow09[4];
extern float yellow10[4];

extern float orange01[4];
extern float orange02[4];
extern float orange03[4];
extern float orange04[4];
extern float orange05[4];
extern float orange06[4];
extern float orange07[4];
extern float orange08[4];
extern float orange09[4];
extern float orange10[4];

extern float color_buildNum[4];

extern int executionID;
extern uint64_t executionAddress;

extern int userId;
extern int userPadHandle;

bool ShouldRun();
void NewRunID();

extern float rgbColor01[4];
extern float rgbColor02[4];
extern float rgbColor03[4];
extern float rgbColor04[4];
extern float rgbColor05[4];
extern float rgbColor06[4];
extern float rgbColor07[4];
extern float rgbColor08[4];
extern float rgbColor09[4];
extern float rgbColor10[4];

void UpdateRGB();

extern float fpsHistory[100];
float SmoothFPS(float currentFrameFps, int smoothAmmount);

signed char ClampChar(int i);
double deg2rad(float degrees);
float Distance(float *one, float *two);
float DotProduct(float *View, float *Axis);
void VectorToAngles(float forward[], float angles[]);
