#include "Mouse.h"


Mouse::Mouse(): x(0), y(0), leftPressed(false), rightPressed(false)
{
}


Mouse::~Mouse()
{
}

void Mouse::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Mouse::getX() const
{
	return this->x;
}

int Mouse::getY() const
{
	return this->y;
}

void Mouse::setLeftPressed(bool pressed)
{
	leftPressed = pressed;
}

void Mouse::setRightPressed(bool pressed)
{
	rightPressed = pressed;
}

void Mouse::setLeftPressX(int leftPressX)
{
	this->leftPressX = leftPressX;
}

void Mouse::setLeftPressY(int leftPressY)
{
	this->leftPressY = leftPressY;
}

int Mouse::getLeftPressX() const
{
	return leftPressX;
}

int Mouse::getLeftPressY() const
{
	return leftPressY;
}

bool Mouse::isLeftPressed() const
{
	return leftPressed;
}

bool Mouse::isRightPressed() const
{
	return rightPressed;
}