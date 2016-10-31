#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

class Image
{
public:
	Image();
	virtual ~Image();

	Image(Image const &) = delete;
	Image & operator=(Image const &) = delete;

	virtual void Render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) = 0;

	int GetWidth() const;
	int GetHeight() const;

	void SetBlendMode(SDL_BlendMode blending) const;
	void SetAlpha(Uint8 alpha) const;

protected:
	SDL_Texture* _texture;
	int _width, _height;
};
