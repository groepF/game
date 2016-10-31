#include "Text.h"

Text::Text(SDL_Renderer* renderer, TTF_Font* font, std::string text, SDL_Color color) : Image()
{
	auto surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (surface == nullptr)
	{
		// Console::Error("Failed to render text surface.");
		return;
	}

	_texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (_texture == nullptr)
	{
		// Console::Error("Failed to create texture from renderer text.");
		return;
	}
	_width = surface->w;
	_height = surface->h;

	SDL_FreeSurface(surface);
}

void Text::Render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, _width, _height };
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, _texture, clip, &renderQuad, angle, center, flip);
}
