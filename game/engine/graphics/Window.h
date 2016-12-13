#pragma once

#include <map>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../util/Color.h"
#include "../util/Log.h"
#include "../graphics/Sprite.h"
#include <SDL/SDL_mixer.h>
#include "Screen.h"
#include <SDL/SDL_ttf.h>
#include "../core/AudioController.h"

class Window : public Screen
{
public:
	Window(unsigned int width, unsigned int height, bool fullscreen = false, std::string title = "");

	virtual ~Window();
	void destroy();

	void resize(std::string title, unsigned int width, unsigned int height);
	void clear() const;
	void fill(Color color = Color(0, 0, 0)) const;
	void refresh() const;

	void minimize() const;
	void maximize() const;
	void restore() const;

	void setTitle(std::string title) const;
	void setBackgroundColor(Color color = Color(0, 0, 0));

	void addTexture(std::string key, std::string filename);
	void addMusic(std::string key, std::string filename);
	void playMusic(std::string key);
	void stopMusic() const;

	void render(Sprite* sprite, float x, float y, double angle = 0, int alpha = 255, float width = -1, float height = -1) const override;
	void renderRect(float x, float y, float width, float height) const override;

	void renderText(std::string message, Color color, int x, int y, int width, int height, double angle = 0, bool cropcrop = false) const override;
	
	unsigned int getWidth() const override;
	unsigned int getHeight() const override;

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	AudioController audio;
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, Mix_Music*> music;

	unsigned int width;
	unsigned int height;

	bool fullscreen;

	std::string title;
	Color background;
	TTF_Font* font;
};
