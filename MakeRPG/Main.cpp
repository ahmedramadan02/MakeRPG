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
	bob = new CSprite("Bob", sdl_setup->GetRenderer(), "../Debug/assests/bob.png", 300, 250, 50, 100);

	MoveRight = false;
	MoveLeft = false;
	MoveUp = false;
	MoveDown = false;
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
				std::cout << "a keydown was pressed!" << std::endl;
				MoveLeft = true;
				break;

			case SDLK_s:
				std::cout << "s keydown was pressed!" << std::endl;
				MoveDown = true;
				break;

			case SDLK_d:
				std::cout << "d keydown was pressed!" << std::endl;
				MoveRight = true;
				break;

			case SDLK_w:
				std::cout << "w keydown was pressed!" << std::endl;
				MoveUp = true;
				break;

			default:
				break;
			}
			break;

		case SDL_KEYUP:
			switch (sdl_setup->GetEvent()->key.keysym.sym)
			{
			case SDLK_a:
				std::cout << "a keyup was pressed!" << std::endl;
				MoveLeft = false;
				break;

			case SDLK_s:
				std::cout << "s keyup was pressed!" << std::endl;
				MoveDown = false;
				break;

			case SDLK_d:
				std::cout << "d keyup was pressed!" << std::endl;
				MoveRight = false;
				break;

			case SDLK_w:
				std::cout << "w keyup was pressed!" << std::endl;
				MoveUp = false;
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}


		if (MoveRight){
			bob->SetX(bob->GetX() + 1);
		}

		if (MoveLeft){
			bob->SetX(bob->GetX() - 1);
		}

		if (MoveUp){
			bob->SetY(bob->GetY() - 1);
		}

		if (MoveDown){
			bob->SetY(bob->GetY() + 1);
		}

		sdl_setup->End();
	}
}