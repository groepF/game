#include "Mouse.h"


Mouse::Mouse(): x(0), y(0), leftPressX(0), leftPressY(0), rightPressX(0), rightPressY(0), leftReleaseX(0), leftReleaseY(0), rightReleaseX(0), rightReleaseY(0), leftPressed(false), rightPressed(false)
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

void Mouse::setLeftPressPosition(int leftPressX, int leftPressY)
{
	this->leftPressX = leftPressX;
	this->leftPressY = leftPressY;
}

void Mouse::setRightPressPosition(int rightPressX, int rightPressY)
{
	this->rightPressX = rightPressX;
	this->rightPressY = rightPressY;
}

int Mouse::getLeftPressX() const
{
	return leftPressX;
}

int Mouse::getLeftPressY() const
{
	return leftPressY;
}

int Mouse::getRightPressX() const
{
	return rightPressX;
}

int Mouse::getRightPressY() const
{
	return rightPressY;
}

void Mouse::setLeftReleasePosition(int leftReleaseX, int leftReleaseY)
{
	this->leftReleaseX = leftReleaseX;
	this->leftReleaseY = leftReleaseY;
}

void Mouse::setRightReleasePosition(int rightReleaseX, int rightReleaseY)
{
	this->rightReleaseX = rightReleaseX;
	this->rightReleaseY = rightReleaseY;
}

int Mouse::getLeftReleaseX() const
{
	return leftReleaseX;
}

int Mouse::getLeftReleaseY() const
{
	return leftReleaseY;
}

int Mouse::getRightReleaseX() const
{
	return rightReleaseX;
}

int Mouse::getRightReleaseY() const
{
	return rightReleaseY;
}

bool Mouse::isLeftPressed() const
{
	return leftPressed;
}

bool Mouse::isRightPressed() const
{
	return rightPressed;
}

void Mouse::consumeEvent()
{
	leftReleaseX = 0;
	leftReleaseY = 0;
	rightReleaseX = 0;
	rightReleaseY = 0;
	leftPressX = 0;
	leftPressY = 0;
	rightPressX = 0;
	rightPressY = 0;
}
