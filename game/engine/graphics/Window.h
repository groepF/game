#pragma once

#include <map>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../util/Color.h"
#include "../util/Log.h"
#include "../graphics/Sprite.h"
#include <SDL/SDL_mixer.h>

class Window
{
public:
	Window(unsigned int width, unsigned int height, std::string title = "");

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
	void setViewport(float x, float y);

	void addTexture(std::string key, std::string filename);
	void addMusic(std::string key, std::string filename);
	void playMusic(std::string key);
	void stopMusic() const;

	void render(Sprite* sprite, float x, float y, double angle = 0, double size = 1, int alpha = 255, float width = -1, float height = -1);

	void renderRect(float x, float y, float width, float height) const;

	unsigned int getWidth() const;
	unsigned int getHeight() const;
private:
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, Mix_Music*> music;

	unsigned int width;
	unsigned int height;

	float viewportX, viewportY;

	std::string title;
	Color background;
};
