#include "Label.h"


Label::Label(int x, int y, int width, int height, std::string text, Color color, int gravity) : 
	x(x), y(y), width(width), height(height), text(text), color(color), gravity(gravity)
{
}


Label::~Label()
{
}

void Label::onCreate()
{
}

void Label::onRender(Screen* screen)
{
	//sprite, x, y, 0, 255, width, height
	//screen->render();
	screen->renderText(text, color, x, y, width, height, 0, false, gravity);
}

bool Label::onUpdate(Keyboard* keyboard, Mouse* mouse)
{
	return true;
}

void Label::onDestroy()
{
}

std::string Label::getText() const
{
	return text;
}
