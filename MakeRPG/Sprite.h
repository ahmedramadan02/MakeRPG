#pragma once
class CSprite
{
public:
	CSprite(std:: string name, SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h);
	~CSprite();

	void Draw();

private:
	std::string spriteName = "";

	SDL_Texture* sprite_texture;
	SDL_Rect sprite_rect;

	SDL_Renderer* renderer;
};

