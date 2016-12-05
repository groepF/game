#include "Enemy.h"

Enemy::Enemy(float x, float y) : Body(x, y, 0.25f, 0.5f, true)
{
	this->sprite = std::make_shared<Sprite>(Sprite("player", 19, 0, 19, 40));
	this->density = 0.4f;
	this->restitution = 0.0f;
	this->friction = 0.5f;
	this->type = CIRCLE;
}