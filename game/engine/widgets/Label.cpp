#include "Label.h"


Label::Label(int x, int y, int width, int height, std::string text) : x(x), y(y), width(width), height(height), text(text)
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
	screen->renderText(text, Color{ "white" }, x, y, width, height);
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
