#include "Screen.h"

Screen::Screen(Window *window) : window(window)
{ }

Screen::~Screen()
{ }

int Screen::getScreenWidth() const
{
	return window == nullptr ? 0 : window->getWidth();
}

int Screen::getScreenHeight() const
{
	return window == nullptr ? 0 : window->getHeight();
}

void Screen::render(Sprite* sprite, float x, float y, double angle, double size, int alpha) const
{
	if (window != nullptr)
	{
		window->render(sprite, x, y, angle, size, alpha);
	}
}