#include "Player.h"

Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;
	this->sprite = new Sprite("spritesheet", 0, 70, 70, 70);
}

void Player::onUpdate(float delta)
{ }