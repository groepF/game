#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer, std::string path) : Image()
{
	auto surface = IMG_Load(path.c_str());
	if (surface == nullptr)
	{
		// Console::Error("Failed to load image: " + path);
		return;
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

	_texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (_texture == nullptr)
	{
		// Console::Error("Failed to create texture from image: " + path);
		return;
	}
	_width = surface->w;
	_height = surface->h;

	SDL_FreeSurface(surface);
}

void Texture::Render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, _width, _height };
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, _texture, clip, &renderQuad, angle, center, flip);
}