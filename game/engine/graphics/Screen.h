#pragma once

#include "Sprite.h"
#include "../util/Color.h"

class Screen
{
public:
	virtual ~Screen() {}
	Screen(Screen const &) = delete;
	Screen & operator=(Screen const &) = delete;

	virtual unsigned int getWidth() const = 0;
	virtual unsigned int getHeight() const = 0;
	virtual void render(Sprite* sprite, int x, int y, double angle = 0, int alpha = 255, int width = -1, int height = -1) const = 0;
	virtual void renderRect(float x, float y, float width, float height) const = 0;
	virtual void renderText(const char* text, Color color, int x, int y, int width, int height) const = 0;
protected:
	Screen() = default;
};