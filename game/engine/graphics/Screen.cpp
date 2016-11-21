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

void Screen::render(Sprite* sprite, float x, float y, double angle, double size, int alpha, float width, float height) const
{
	if (window != nullptr)
	{
		window->render(sprite, x, y, angle, size, alpha, width, height);
	}
}

void Screen::renderText(std::string text, Color color, int x, int y, int width, int height) const
{
	if(window != nullptr)
	{
		window->renderText(text, color, x, y, width, height);
	}
}

void Screen::renderRect(float x, float y, float width, float height) const
{
	if (window != nullptr)
	{
		window->renderRect(x, y, width, height);
	}
}
