#pragma once
class CSDL_Setup
{
public:
	CSDL_Setup();
	CSDL_Setup(bool*, int, int);
	~CSDL_Setup();

	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
	SDL_Event* GetEvent();

	void Begin();
	void End();

private:
	SDL_Window*  window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
};

