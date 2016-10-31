#pragma once
#include <SDL/SDL.h>
#include <string>
#include <SDL/SDL_image.h>
#include "Image.h"

class Texture : public Image
{
public:
	Texture(SDL_Renderer* renderer, std::string path);

	void Render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) final;
};