#include "global.h"

#include "imports.h"
#include "utility.h"

float white01[4] = { 1.0f, 1.0f, 1.0f, 0.1f };
float white02[4] = { 1.0f, 1.0f, 1.0f, 0.2f };
float white03[4] = { 1.0f, 1.0f, 1.0f, 0.3f };
float white04[4] = { 1.0f, 1.0f, 1.0f, 0.4f };
float white05[4] = { 1.0f, 1.0f, 1.0f, 0.5f };
float white06[4] = { 1.0f, 1.0f, 1.0f, 0.6f };
float white07[4] = { 1.0f, 1.0f, 1.0f, 0.7f };
float white08[4] = { 1.0f, 1.0f, 1.0f, 0.8f };
float white09[4] = { 1.0f, 1.0f, 1.0f, 0.9f };
float white10[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

float black01[4] = { 0.0f, 0.0f, 0.0f, 0.1f };
float black02[4] = { 0.0f, 0.0f, 0.0f, 0.2f };
float black03[4] = { 0.0f, 0.0f, 0.0f, 0.3f };
float black04[4] = { 0.0f, 0.0f, 0.0f, 0.4f };
float black05[4] = { 0.0f, 0.0f, 0.0f, 0.5f };
float black06[4] = { 0.0f, 0.0f, 0.0f, 0.6f };
float black07[4] = { 0.0f, 0.0f, 0.0f, 0.7f };
float black08[4] = { 0.0f, 0.0f, 0.0f, 0.8f };
float black09[4] = { 0.0f, 0.0f, 0.0f, 0.9f };
float black10[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

float red01[4] = { 1.0f, 0.0f, 0.0f, 0.1f };
float red02[4] = { 1.0f, 0.0f, 0.0f, 0.2f };
float red03[4] = { 1.0f, 0.0f, 0.0f, 0.3f };
float red04[4] = { 1.0f, 0.0f, 0.0f, 0.4f };
float red05[4] = { 1.0f, 0.0f, 0.0f, 0.5f };
float red06[4] = { 1.0f, 0.0f, 0.0f, 0.6f };
float red07[4] = { 1.0f, 0.0f, 0.0f, 0.7f };
float red08[4] = { 1.0f, 0.0f, 0.0f, 0.8f };
float red09[4] = { 1.0f, 0.0f, 0.0f, 0.9f };
float red10[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

float green01[4] = { 0.0f, 1.0f, 0.0f, 0.1f };
float green02[4] = { 0.0f, 1.0f, 0.0f, 0.2f };
float green03[4] = { 0.0f, 1.0f, 0.0f, 0.3f };
float green04[4] = { 0.0f, 1.0f, 0.0f, 0.4f };
float green05[4] = { 0.0f, 1.0f, 0.0f, 0.5f };
float green06[4] = { 0.0f, 1.0f, 0.0f, 0.6f };
float green07[4] = { 0.0f, 1.0f, 0.0f, 0.7f };
float green08[4] = { 0.0f, 1.0f, 0.0f, 0.8f };
float green09[4] = { 0.0f, 1.0f, 0.0f, 0.9f };
float green10[4] = { 0.0f, 1.0f, 0.0f, 1.0f };

float blue01[4] = { 0.0f, 0.0f, 1.0f, 0.1f };
float blue02[4] = { 0.0f, 0.0f, 1.0f, 0.2f };
float blue03[4] = { 0.0f, 0.0f, 1.0f, 0.3f };
float blue04[4] = { 0.0f, 0.0f, 1.0f, 0.4f };
float blue05[4] = { 0.0f, 0.0f, 1.0f, 0.5f };
float blue06[4] = { 0.0f, 0.0f, 1.0f, 0.6f };
float blue07[4] = { 0.0f, 0.0f, 1.0f, 0.7f };
float blue08[4] = { 0.0f, 0.0f, 1.0f, 0.8f };
float blue09[4] = { 0.0f, 0.0f, 1.0f, 0.9f };
float blue10[4] = { 0.0f, 0.0f, 1.0f, 1.0f };

float cyan01[4] = { 0.0f, 1.0f, 1.0f, 0.1f };
float cyan02[4] = { 0.0f, 1.0f, 1.0f, 0.2f };
float cyan03[4] = { 0.0f, 1.0f, 1.0f, 0.3f };
float cyan04[4] = { 0.0f, 1.0f, 1.0f, 0.4f };
float cyan05[4] = { 0.0f, 1.0f, 1.0f, 0.5f };
float cyan06[4] = { 0.0f, 1.0f, 1.0f, 0.6f };
float cyan07[4] = { 0.0f, 1.0f, 1.0f, 0.7f };
float cyan08[4] = { 0.0f, 1.0f, 1.0f, 0.8f };
float cyan09[4] = { 0.0f, 1.0f, 1.0f, 0.9f };
float cyan10[4] = { 0.0f, 1.0f, 1.0f, 1.0f };

float pink01[4] = { 1.0f, 0.0f, 1.0f, 0.1f };
float pink02[4] = { 1.0f, 0.0f, 1.0f, 0.2f };
float pink03[4] = { 1.0f, 0.0f, 1.0f, 0.3f };
float pink04[4] = { 1.0f, 0.0f, 1.0f, 0.4f };
float pink05[4] = { 1.0f, 0.0f, 1.0f, 0.5f };
float pink06[4] = { 1.0f, 0.0f, 1.0f, 0.6f };
float pink07[4] = { 1.0f, 0.0f, 1.0f, 0.7f };
float pink08[4] = { 1.0f, 0.0f, 1.0f, 0.8f };
float pink09[4] = { 1.0f, 0.0f, 1.0f, 0.9f };
float pink10[4] = { 1.0f, 0.0f, 1.0f, 1.0f };

float yellow01[4] = { 1.0f, 1.0f, 0.0f, 0.1f };
float yellow02[4] = { 1.0f, 1.0f, 0.0f, 0.2f };
float yellow03[4] = { 1.0f, 1.0f, 0.0f, 0.3f };
float yellow04[4] = { 1.0f, 1.0f, 0.0f, 0.4f };
float yellow05[4] = { 1.0f, 1.0f, 0.0f, 0.5f };
float yellow06[4] = { 1.0f, 1.0f, 0.0f, 0.6f };
float yellow07[4] = { 1.0f, 1.0f, 0.0f, 0.7f };
float yellow08[4] = { 1.0f, 1.0f, 0.0f, 0.8f };
float yellow09[4] = { 1.0f, 1.0f, 0.0f, 0.9f };
float yellow10[4] = { 1.0f, 1.0f, 0.0f, 1.0f };

float orange01[4] = { 1.0f, 0.5f, 0.0f, 0.1f };
float orange02[4] = { 1.0f, 0.5f, 0.0f, 0.2f };
float orange03[4] = { 1.0f, 0.5f, 0.0f, 0.3f };
float orange04[4] = { 1.0f, 0.5f, 0.0f, 0.4f };
float orange05[4] = { 1.0f, 0.5f, 0.0f, 0.5f };
float orange06[4] = { 1.0f, 0.5f, 0.0f, 0.6f };
float orange07[4] = { 1.0f, 0.5f, 0.0f, 0.7f };
float orange08[4] = { 1.0f, 0.5f, 0.0f, 0.8f };
float orange09[4] = { 1.0f, 0.5f, 0.0f, 0.9f };
float orange10[4] = { 1.0f, 0.5f, 0.0f, 1.0f };

float color_buildNum[4] = {0.4f, 0.7f, 1.0f, 0.7f};

int executionID = 0;
uint64_t executionAddress = 0;

int userId = -1;
int userPadHandle = -1;

bool ShouldRun() {
	if (executionAddress == 0)
		return false;

	return executionID == *(int *)executionAddress;
}

void NewRunID() {
	executionID = *(int *)(executionAddress) + 1;
	*(int *)executionAddress = executionID;
}

float rgbColor01[4] = {1.0f, 0.5f, 0.0f, 0.1f};
float rgbColor02[4] = {1.0f, 0.5f, 0.0f, 0.2f};
float rgbColor03[4] = {1.0f, 0.5f, 0.0f, 0.3f};
float rgbColor04[4] = {1.0f, 0.5f, 0.0f, 0.4f};
float rgbColor05[4] = {1.0f, 0.5f, 0.0f, 0.5f};
float rgbColor06[4] = {1.0f, 0.5f, 0.0f, 0.6f};
float rgbColor07[4] = {1.0f, 0.5f, 0.0f, 0.7f};
float rgbColor08[4] = {1.0f, 0.5f, 0.0f, 0.8f};
float rgbColor09[4] = {1.0f, 0.5f, 0.0f, 0.9f};
float rgbColor10[4] = {1.0f, 0.5f, 0.0f, 1.0f};

void UpdateRGB() {
	for (int i = 0; i < 3; i++) {
		rgbColor01[i] = rgbColor10[i];
		rgbColor02[i] = rgbColor10[i];
		rgbColor03[i] = rgbColor10[i];
		rgbColor04[i] = rgbColor10[i];
		rgbColor05[i] = rgbColor10[i];
		rgbColor06[i] = rgbColor10[i];
		rgbColor07[i] = rgbColor10[i];
		rgbColor08[i] = rgbColor10[i];
		rgbColor09[i] = rgbColor10[i];
	}
}

float fpsHistory[100] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
float SmoothFPS(float currentFrameFps, int smoothAmmount) {
	int smoothValue = 2;

	if (smoothAmmount <= 100 && smoothAmmount >= 2)
		smoothValue = smoothAmmount;

	for (int i = smoothValue - 1; i > 0; i--)
		fpsHistory[i] = fpsHistory[i - 1];

	fpsHistory[0] = currentFrameFps + 1.0f;

	float roundedFps = 0.0f;

	for (int i = 0; i < smoothValue; i++)
		roundedFps += fpsHistory[i];

	return roundedFps / smoothValue;
}

signed char ClampChar(int i) {
	if (i < -128)
		return -128;

	if (i > 127)
		return 127;

	return i;
}

double deg2rad(float degrees) {
	return degrees * (MATH_PI / 180.0f);
}

float Distance(float *one, float *two) {
	double temp = sqrt(
		pow((double)(one[0] - two[0]), 2) +
		pow((double)(one[1] - two[1]), 2) +
		pow((double)(one[2] - two[2]), 2));

	return (float)temp;
}

float DotProduct(float *view, float *axis) {
	return (view[0] * axis[0]) + (view[1] * axis[1]) + (view[2] * axis[2]);
}

void VectorToAngles(float forward[], float angles[]) {
	float tmp, yaw, pitch;

	if (forward[0] == 0 && forward[1] == 0) {
		yaw = 0;

		if (forward[2] > 0)
			pitch = 90;
		else
			pitch = 270;
	}
	else {
		if (forward[0])
			yaw = (atan2(forward[1], forward[0]) * 180 / MATH_PI);
		else if (forward[1] > 0)
			yaw = 90;
		else
			yaw = 270;

		if (yaw < 0)
			yaw += 360;

		tmp = sqrt((forward[0] * forward[0]) + (forward[1] * forward[1]));
		pitch = atan2(forward[2], tmp) * 180 / MATH_PI;

		if (pitch < 0)
			pitch += 360;
	}

	angles[0] = -pitch;
	angles[1] = yaw;
	angles[2] = 0;
}
