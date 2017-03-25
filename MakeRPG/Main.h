#pragma once

#include"SDL_Setup.h"
#include "Sprite.h"

//if you increased it, the character will move slower!
#define TIME_DIFF 5

class CMain
{
public:
	CMain(int _screenWidth, int _screenHeight);
	~CMain();
	void GameLoop();

	//Time functions
	bool CheckTime();
	void ResetTime() { currentTime = SDL_GetTicks(); }

private:
	bool quit;
	int screenWidth, screenHeight;

	bool MoveRight;
	bool MoveLeft;
	bool MoveUp;
	bool MoveDown;

	int currentTime;

	CSDL_Setup* sdl_setup;
	CSprite* grass;
	CSprite* bob;
};

