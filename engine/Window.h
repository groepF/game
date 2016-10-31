#pragma once

#include <string>
#include <SDL/SDL.h>
#include "Log.h"
#include "Color.h"

class Window
{
public:
	Window(unsigned int width, unsigned int height, std::string title = "");

	virtual ~Window();

	void destroy();

	void resize(std::string title, unsigned int width, unsigned int height);

	void minimize() const;

	void maximize() const;

	void restore() const;

	void clear() const;

	void fill(Color color) const;

	void setTitle(std::string title) const;

	void refresh() const;

	void setBackgroundColor(Color color = Color(0, 0, 0));

private:
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	unsigned int width; 
	unsigned int height;

	unsigned int originalWidth;
	unsigned int originalHeight;

	std::string title;

	Color background;
};
