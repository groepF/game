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
	virtual void render(Sprite* sprite, float x, float y, double angle = 0, int alpha = 255, float width = -1, float height = -1) const = 0;
	virtual void renderRect(float x, float y, float width, float height, bool fill = false, Color color = Color("red")) const = 0;
	virtual void renderText(std::string text, Color color, int x, int y, int width, int height, double angle = 0, bool crop = false, int gravity = 1) const = 0;
protected:
	Screen() = default;
};