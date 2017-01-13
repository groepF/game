#include "Player.h"
#include "../../engine/graphics/render-strategies/RenderDrawableStrategy.h"
#include "Ball.h"

Player::Player(float x, float y) : DrawableEntity(std::make_shared<Sprite>(Sprite("player", 0, 0, 19, 40)), x, y, 0.25f, 0.5f, true, 0, 0, true)
{

	this->density = 0.4f;
	this->density = 5.0f;
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

PlayerState Player::getPlayerState() const
{
	return this->state;
}

/*
 * Checks if the player is close enough to the ball to pick it up
 * Body* b - The entity that should be picked up
 */
bool Player::canPickup(Body* b) const
{

	int xPlayer_1 = this->body->GetPosition().x;
	int xPlayer_2 = this->body->GetPosition().x + this->getWidth();
	int yPlayer_1 = this->body->GetPosition().y;
	int yPlayer_2 = this->body->GetPosition().y + this->getHeight();

	int xEntity_1 = b->getBodyX();
	int xEntity_2 = b->getBodyX() + b->getBodyWidth();
	int yEntity_1 = b->getBodyY();
	int yEntity_2 = b->getBodyY() + b->getBodyHeight();

	if (xPlayer_1 >= xEntity_2 && xPlayer_1 <= xEntity_2 + 1
		&& ((yPlayer_2 >= yEntity_1 && yPlayer_2 <= yEntity_2) || (yPlayer_1 >= yEntity_1 && yPlayer_1 <= yEntity_2)))
		return true;
	if (xPlayer_2 <= xEntity_1 && xPlayer_2 >= xEntity_1 - 1
		&& ((yPlayer_2 >= yEntity_1 && yPlayer_2 <= yEntity_2) || (yPlayer_1 >= yEntity_1 && yPlayer_1 <= yEntity_2)))
		return true;

	return false;
}

/**
* Makes the player drop the ball
* @param b the ball to drop
*/
void Player::hitByEnemy(Ball* b) const
{
	b->drop();
}
