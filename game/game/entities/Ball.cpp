#include "Ball.h"

Ball::Ball(float x, float y) : Body(x, y, 0.3f, 0.3f, true, 0.1f, 0.5f)
{
	this->sprite = new Sprite("spritesheet", 0, 140, 70, 70);
	this->density = 2.0f;
	this->restitution = 0.8f;
	this->friction = 0.6f;
	this->type = CIRCLE;
}