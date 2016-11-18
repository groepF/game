#include "Player.h"

Player::Player(float x, float y) : Body(x, y, 0.5f, 0.5f, true)
{
	this->sprite = new Sprite("spritesheet", 0, 70, 70, 70);
	this->density = 0.4f;
	this->restitution = 0.0f;
	this->friction = 0.5f;
	this->state = PLAYER_STOP;
	this->type = CIRCLE;
}

void Player::move() const
{
	auto vel = body->GetLinearVelocity();
	switch (state)
	{
	case PLAYER_LEFT:  vel.x = -1.8f; break;
	case PLAYER_STOP:  vel.x = 0.0f; break;
	case PLAYER_RIGHT: vel.x = 1.8f; break;
	default: break;
	}
	body->SetLinearVelocity(vel);
}

void Player::jump()
{
	if (body->GetLinearVelocity().y == 0)
	{
		auto vel = body->GetLinearVelocity();
		vel.y = -8.0f;
		body->SetLinearVelocity(vel);
	}
}

void Player::setPlayerState(PlayerState state)
{
	this->state = state;
}
