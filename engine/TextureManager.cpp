#include "TextureManager.h"

TextureManager* TextureManager::_instance = nullptr;

bool TextureManager::load(std::string path, std::string identifier, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(path.c_str());

	if (surface == nullptr) {
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture != nullptr) {
		_textures[identifier] = texture;
		return true;
	}

	return false;
}

void TextureManager::render(std::string identifier, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;

	destinationRectangle.w = width;
	destinationRectangle.h = height;
	destinationRectangle.x = x;
	destinationRectangle.y = y;

	sourceRectangle.x = 0;
	sourceRectangle.y = 0;
	sourceRectangle.w = destinationRectangle.w;
	sourceRectangle.h = destinationRectangle.h;

	SDL_RenderCopyEx(renderer, _textures[identifier], &sourceRectangle, &destinationRectangle, 0, nullptr, flip);
}

void TextureManager::clear()
{
	_textures.clear();
}

void TextureManager::clearByIdentifier(std::string identifier)
{
	_textures.erase(identifier);
}
