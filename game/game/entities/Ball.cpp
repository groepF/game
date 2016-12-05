#include "Ball.h"
#include "Player.h"

Ball::Ball(float x, float y) : Body(x, y, 0.3f, 0.3f, true, 0.1f, 0.5f)
{
	this->sprite = std::make_shared<Sprite>(Sprite("spritesheet", 0, 140, 70, 70));
	this->density = 2.0f;
	this->restitution = 0.8f;
	this->friction = 0.6f;
	this->type = CIRCLE;
}

/*
 * Drops the ball. Resets the heldby variable
 */
void Ball::drop()
{
	this->body->SetActive(true);
	this->heldBy = nullptr;
}

/*
 * Checks if the ball is held by the player given.
 */
bool Ball::isHeldBy(Player* p) const
{
	return this->heldBy == p;
}

/*
 * Sets the ball as picked up. Makes holder the current player.
 * Player* p - The player that performs the action
 */
void Ball::pickUp(Player* p)
{
	this->body->SetActive(false);
	this->body->SetTransform(b2Vec2(p->getX(), p->getY()), 0);
	this->heldBy = p;
}
