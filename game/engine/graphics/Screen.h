#pragma once

#include "Window.h"

class Screen
{
public:
	Screen(Window *window);
	~Screen();

	int getScreenWidth() const;
	int getScreenHeight() const;
	void render(Sprite* sprite, float x, float y, double angle = 0, double size = 1, int alpha = 255) const;

private:
	Window *window;
};