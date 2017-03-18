#include "stdafx.h"
#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup(bool* quit, int _screenWidth, int _screenHeight)
{
	//SDL Components
	SDL_Init(SDL_INIT_VIDEO);
	window = NULL;

	window = SDL_CreateWindow("My First GAME C++", 100, 100, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL){
		std::cout << "Error Window: Window couldn't be created" << std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	mainEvent = new SDL_Event();
}


CSDL_Setup::~CSDL_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Window* CSDL_Setup::GetWindow(){
	return this->window;
}

SDL_Renderer* CSDL_Setup::GetRenderer(){
	return this->renderer;
}

SDL_Event* CSDL_Setup::GetEvent(){
	return this->mainEvent;
}

void CSDL_Setup::Begin(){
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void CSDL_Setup::End(){
	SDL_RenderPresent(renderer);
}