#pragma once

#include <map>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "Console.h"

class TextureManager
{
public:
	static TextureManager* Instance()
	{		  
		if (_instance == nullptr) {
			_instance = new TextureManager();
			return _instance;
		}

		return _instance;
	}

	bool load(std::string path, std::string identifier, SDL_Renderer* renderer);

	void render(std::string identifier, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clear();
	void clearByIdentifier(std::string identifier);

private:
	TextureManager() {}
	~TextureManager() {}

	std::map<std::string, SDL_Texture*> _textures;
	static TextureManager* _instance;
};

typedef TextureManager TheTextureManager;