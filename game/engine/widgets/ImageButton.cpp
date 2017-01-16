#include "ImageButton.h"
#include "../input/OnClickListener.h"


ImageButton::ImageButton(std::string id, std::string image, int x, int y, int width, int height, bool locked, OnClickListener* listener) : selected(false), hovering(false), x(x), y(y), width(width), height(height), normal(nullptr), listener(listener), image(image), locked(locked)
{
	this->setId(id);
}

ImageButton::~ImageButton()
{
	if (normal != nullptr)
	{
		delete normal;
		normal = nullptr;
	}
	if (lock != nullptr)
	{
		delete lock;
		lock = nullptr;
	}
	if (check != nullptr)
	{
		delete check;
		check = nullptr;
	}
}

void ImageButton::onCreate()
{
	normal = new Sprite(image, 0, 0, width, height);
	lock = new Sprite("level_lock", 0, 0, 30, 42);
	check = new Sprite("check", 0, 0, 35, 27);
}

void ImageButton::onRender(Screen* screen)
{
	screen->renderRect(x - 2, y - 2, width + 4, height + 4, true, Color(13, 101, 217));
	screen->render(normal, x, y, 0, 255, width, height);
	if (locked)
	{
		screen->renderRect(x, y, width, height, true, Color(0, 0, 0, 200));
		screen->render(lock, x + width / 2 - 15, y + height / 2 - 21, 0, 255, 30, 42);
		return;
	}
	if (pressing)
	{
		screen->renderRect(x, y, width, height, true, Color(13, 101, 217, 150));
	}
	else if (selected)
	{
		screen->renderRect(x, y, width, height, true, Color(13, 101, 217, 90));
		screen->render(check, x + width / 2 - 35 / 2, y + height / 2 - 27 / 2, 0, 255, 35, 27);
	}
	if (hovering)
	{
		screen->renderRect(x, y, width, height, true, Color(255, 255, 255, 50));
	}
}

bool ImageButton::onUpdate(Keyboard* keyboard, Mouse* mouse)
{
	if (locked) return true;
	int mouseX = mouse->getX();
	int mouseY = mouse->getY();
	hovering = inBounds(mouseX, mouseY);
	if (pressing && inBounds(mouse->getLeftReleaseX(), mouse->getLeftReleaseY()))
	{
		mouse->setLeftPressed(false);
		mouse->consumeEvent();
		return listener->onClick(this);
	}

	if (hovering && mouse->isLeftPressed() && inBounds(mouse->getLeftPressX(), mouse->getLeftPressY()))
	{
		pressing = true;
	}
	else
	{
		pressing = false;
	}
	return true;
}

void ImageButton::onDestroy()
{
}

void ImageButton::setLocked(bool locked)
{
	this->locked = locked;
}

bool ImageButton::isLocked() const
{
	return locked;
}

bool ImageButton::inBounds(int posX, int posY) const
{
	return (posX > this->x && posX < this->x + width && posY > this->y && posY < this->y + height);
}

void ImageButton::select()
{
	selected = true;
}

void ImageButton::deselect()
{
	selected = false;
}
