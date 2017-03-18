#pragma once

#include"SDL_Setup.h"
#include "Sprite.h"

class CMain
{
public:
	CMain(int _screenWidth, int _screenHeight);
	~CMain();
	void GameLoop();

private:
	bool quit;
	int screenWidth, screenHeight;

	CSDL_Setup* sdl_setup;
	CSprite* grass;
	CSprite* bob;
};

