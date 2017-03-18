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

		// handling the keypress
		switch (sdl_setup->GetEvent()->type)
		{
		case SDL_KEYDOWN:
			switch (sdl_setup->GetEvent()->key.keysym.sym)
			{
			case SDLK_a:
				std::cout << "a key was pressed!" << std::endl;
				break;

			case SDLK_s:
				std::cout << "s key was pressed!" << std::endl;
				break;

			case SDLK_d:
				std::cout << "d key was pressed!" << std::endl;
				break;

			case SDLK_w:
				std::cout << "w key was pressed!" << std::endl;
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		sdl_setup->End();
	}
}