#pragma once

#include "Window.h"

class Screen
{
public:
	Screen(Window *window);
	~Screen();

	int getScreenWidth() const;
	int getScreenHeight() const;
	void render(Sprite* sprite, float x, float y, double angle = 0, double size = 1, int alpha = 255, float width = -1, float height = -1) const;
	void renderText(std::string text, Color color, int x, int y, int width, int height) const;
	void renderRect(float x, float y, float width, float height) const;

private:
	Window *window;
};