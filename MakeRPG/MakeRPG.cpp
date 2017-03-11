// MakeRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	bool quit = false;
	std::cout << "Hello RPG" << std::endl;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window*  window = NULL;
	window = SDL_CreateWindow("My First GAME C++", 100, 100, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL){
		std::cout << "Error Window: Window couldn't be created" << std::endl;
		return 0;
	}

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_Event* mainEvent = new SDL_Event();

	SDL_Texture* grass_texture = NULL;
	grass_texture = IMG_LoadTexture(renderer, "../Debug/assests/grass.bmp");
	if (grass_texture == NULL){
		std::cout << "No Texture!" << std::endl;
	}

	SDL_Rect grass_rect;
	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 600;
	grass_rect.h = 600;

	SDL_Texture* bob_texture = NULL;
	bob_texture = IMG_LoadTexture(renderer, "../Debug/assests/bob.png");
	if (grass_texture == NULL){
		std::cout << "No Texture!" << std::endl;
	}

	SDL_Rect bob_rect;
	bob_rect.x = 300;
	bob_rect.y = 250;
	bob_rect.w = 80;
	bob_rect.h = 50;

	while (!quit && mainEvent->type != SDL_QUIT) {
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, grass_texture, NULL,&grass_rect);
		SDL_RenderCopy(renderer, bob_texture, NULL, &bob_rect);

		SDL_RenderPresent(renderer);
	}


	SDL_DestroyTexture(grass_texture);
	SDL_DestroyTexture(bob_texture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;

	return 0;
}

