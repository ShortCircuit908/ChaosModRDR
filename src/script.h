#pragma once

#include <natives.h>
#include <types.h>
#include <enums.h>
#include <main.h>
#include <string>
#include <stdint.h>
#include <windows.h>



struct Vector2
{
	Vector2() {};
	Vector2(float _X, float _Y)
	{
		X = _X;
		Y = _Y;
	}
	float X = 0.0f;
	float Y = 0.0f;
};

struct LinearColor
{
	LinearColor() {};
	LinearColor(uint8_t _R, uint8_t _G, uint8_t _B, uint8_t _A)
	{
		R = _R;
		G = _G;
		B = _B;
		A = _A;
	};

	uint8_t R = 0;
	uint8_t G = 0;
	uint8_t B = 0;
	uint8_t A = 255;
};

struct KeyState
{
	uint32_t time = 0;
	bool bPressed = false;
};

class ChaosMod
{
public:
	ChaosMod();
	~ChaosMod();

	static void ScriptMain();

	static ChaosMod* Singleton;

	/** Returns singleton */
	static ChaosMod* Get();

	bool IsModEnabled();
	
	static void DrawText(char* text, Vector2 position, Vector2 scale, LinearColor color, bool bCenter = true, int shadowSize = 0, LinearColor shadowColor = LinearColor());

	static void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);

	/** Enabled and disbles the mod */
	void ToggleModStatus();
private:
	void Main();
	void Update();
	void InputTick();
	void DrawUI();

	bool bEnabled = false;

	std::string ModUITextString;
	uint32_t ModUITextEndTime = 0;

	KeyState keyStates[0xFF] = {};

	bool isKeyPressed(uint8_t key);

private:
	/** Timers and effects */

	/** In seconds */
	int effectsInterval = 90;
	int effectsVoteTime = 45;

	uint32_t timeoutStartTime = 0;
	uint32_t timeoutEndTime = 0;
	uint32_t timeoutVotingStartTime = 0;

	bool bVotingEnabled = false;
	
	void ResetEffectsTimeout();
};