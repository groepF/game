#include "Ball.h"

Ball::Ball(float x, float y) : Body(x, y, 0.3f, 0.3f, true)
{
	this->sprite = new Sprite("spritesheet", 0, 140, 70, 70);
	this->density = 3.0f;
	this->restitution = 0.2f;
	this->friction = 0.2f;
}