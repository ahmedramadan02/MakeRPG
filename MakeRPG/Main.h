#pragma once

#include"SDL_Setup.h"

class CMain
{
public:
	CMain();
	~CMain();
	void GameLoop();

private:
	bool quit;
	SDL_Texture* grass_texture;
	SDL_Rect grass_rect;

	SDL_Texture* bob_texture;
	SDL_Rect bob_rect;

	CSDL_Setup* sdl_setup;
};

