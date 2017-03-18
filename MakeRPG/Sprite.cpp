#include "stdafx.h"
#include "Sprite.h"


CSprite::CSprite(std::string name, SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
	this->renderer = passed_renderer;
	this->spriteName = name;

	sprite_texture = NULL;
	sprite_texture = IMG_LoadTexture(this->renderer, FilePath.c_str());
	if (sprite_texture == NULL){
		std::cout << "can't open Texture: " << FilePath.c_str() 
			<< "!" << std::endl;
	}

	sprite_rect.x = x;
	sprite_rect.y = y;
	sprite_rect.w = w;
	sprite_rect.h = h;
}


CSprite::~CSprite()
{
	SDL_DestroyTexture(sprite_texture);
}

void CSprite::Draw(){
	SDL_RenderCopy(renderer, sprite_texture, NULL, &sprite_rect);
}