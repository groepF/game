#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <map>
#include "Texture.h"

class TextureManager
{
public:
	static TextureManager& GetInstance()
	{
		static TextureManager _instance;

		return _instance;
	}
	TextureManager(TextureManager const&) = delete;
	void operator=(TextureManager const&) = delete;

private:
	TextureManager() {}

	std::map<std::string, Texture> _textures;
};