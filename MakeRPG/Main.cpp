#include "stdafx.h"
#include "Main.h"


CMain::CMain(int _screenWidth, int _screenHeight)
{
	//To quit the game loop
	quit = false;
	this->screenWidth = _screenWidth;
	this->screenHeight = _screenHeight;

	sdl_setup = new CSDL_Setup(&quit, _screenWidth, _screenHeight);

	//sprites
	grass = new CSprite("Grass", sdl_setup->GetRenderer(), "../Debug/assests/grass.bmp", 0, 0, this->screenWidth, this->screenHeight);
	bob = new CSprite("Bob",sdl_setup->GetRenderer(), "../Debug/assests/bob.png",300,250,50,100);
}


CMain::~CMain()
{
	delete grass;
	delete bob;
	delete sdl_setup;
}

void CMain::GameLoop(){
	while (!quit && sdl_setup->GetEvent()->type != SDL_QUIT) {
		sdl_setup->Begin();

		grass->Draw();
		bob->Draw();

		sdl_setup->End();
	}
}