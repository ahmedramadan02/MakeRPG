#include "stdafx.h"
#include "Main.h"


CMain::CMain()
{
	//To quit the game loop
	quit = false;

	sdl_setup = new CSDL_Setup(&quit);

	grass_texture = NULL;
	grass_texture = IMG_LoadTexture(sdl_setup->GetRenderer(), "../Debug/assests/grass.bmp");
	if (grass_texture == NULL){
		std::cout << "No Texture!" << std::endl;
	}


	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 600;
	grass_rect.h = 600;

	bob_texture = NULL;
	bob_texture = IMG_LoadTexture(sdl_setup->GetRenderer(), "../Debug/assests/bob.png");
	if (grass_texture == NULL){
		std::cout << "No Texture!" << std::endl;
	}

	bob_rect.x = 300;
	bob_rect.y = 250;
	bob_rect.w = 80;
	bob_rect.h = 50;
}


CMain::~CMain()
{
	SDL_DestroyTexture(grass_texture);
	SDL_DestroyTexture(bob_texture);

}

void CMain::GameLoop(){
	while (!quit && sdl_setup->GetEvent()->type != SDL_QUIT) {
		sdl_setup->Begin();

		SDL_RenderCopy(sdl_setup->GetRenderer(), grass_texture, NULL, &grass_rect);
		SDL_RenderCopy(sdl_setup->GetRenderer(), bob_texture, NULL, &bob_rect);

		sdl_setup->End();
	}
}