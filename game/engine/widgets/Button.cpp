#include "Button.h"
#include "../util/Log.h"
#include "../input/OnClickListener.h"


Button::Button(int x, int y, int width, int height, std::string text, OnClickListener* listener) : hovering(false), x(x), y(y), width(width), height(height), text(text), hovered(nullptr), normal(nullptr), listener(listener)
{
}

Button::~Button()
{
	if (hovered != nullptr)
	{
		delete hovered;
		hovered = nullptr;
	}
	if (normal != nullptr)
	{
		delete normal;
		normal = nullptr;
	}
}

void Button::onCreate()
{
	this->hovered = new Sprite("button", 0, 50, 600, 50);
	this->normal = new Sprite("button", 0, 0, 600, 50);
}

void Button::onRender(Screen* screen)
{
	screen->render(!hovering ? normal : hovered, x, y, 0, 255, width, height);
	screen->renderText(text, Color{"white"}, x, y, width, height);
}

bool Button::onUpdate(Keyboard* keyboard, Mouse* mouse)
{
	int mouseX = mouse->getX();
	int mouseY = mouse->getY();
	hovering = inBounds(mouseX, mouseY);

	if (hovering && mouse->isLeftPressed() && inBounds(mouse->getLeftPressX(), mouse->getLeftPressY()))
	{
		listener->onClick(this);
		return false;
	}
	return true;
}

void Button::onDestroy()
{
}

bool Button::inBounds(int posX, int posY) const
{
	return (posX > this->x && posX < this->x + width && posY > this->y && posY < this->y + height);
}

std::string Button::getText() const
{
	return text;
}
