#include "Image.h"

Image::Image(): _texture(nullptr), _width(0), _height(0) {}

Image::~Image()
{
	SDL_DestroyTexture(_texture);
	_texture = nullptr;
}

void Image::SetBlendMode(SDL_BlendMode blending) const
{
	SDL_SetTextureBlendMode(_texture, blending);
}

void Image::SetAlpha(Uint8 alpha) const
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}

int Image::GetWidth() const
{
	return _width;
}

int Image::GetHeight() const
{
	return _height;
}