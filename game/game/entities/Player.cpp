#include "Player.h"

Player::Player(float x, float y) : Body(x, y, 0.5f, 0.5f, true)
{
	this->sprite = new Sprite("spritesheet", 0, 70, 70, 70);
	this->density = 0.5f;
	this->restitution = 0.0f;
	this->friction = 0.5f;
	this->state = PLAYER_STOP;
}

void Player::move() const
{
	auto vel = body->GetLinearVelocity();
	switch (state)
	{
	case PLAYER_LEFT:  vel.x = -1.0f; break;
	case PLAYER_STOP:  vel.x = 0.0f; break;
	case PLAYER_RIGHT: vel.x = 1.0f; break;
	default: break;
	}
	body->SetLinearVelocity(vel);
}

void Player::jump()
{
	auto vel = body->GetLinearVelocity();
	vel.y = -2.0f;
	body->SetLinearVelocity(vel);
}

void Player::setPlayerState(PlayerState state)
{
	this->state = state;
}
