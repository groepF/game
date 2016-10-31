#pragma once
#include <SDL/SDL.h>
#include <string>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Image.h"

class Text : public Image
{
public:
	Text(SDL_Renderer* renderer, TTF_Font* font, std::string text, SDL_Color color);

	void Render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) final;
};