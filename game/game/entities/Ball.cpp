#include "Ball.h"
#include "Player.h"

Ball::Ball(float x, float y) : Body(x, y, 0.3f, 0.3f, true, 0.1f, 0.5f)
{
	this->sprite = std::make_shared<Sprite>(Sprite("spritesheet", 0, 140, 70, 70));
	this->density = 0.3f;
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
bool Ball::isHeldBy(Body* p) const
{
	return this->heldBy == p;
}

void Ball::shoot(Body* from, bool left)
{
	
	auto sideForce = (left ? -50.0 : 50.0);
	this->body->ApplyForce(b2Vec2(sideForce, -10.0), b2Vec2(from->getX(), from->getY()), false);

}

/*
 * Sets the ball as picked up. Makes holder the current player.
 * Player* p - The player that performs the action
 */
void Ball::pickUp(Body* p)
{
	this->body->SetActive(false);
	this->body->SetTransform(b2Vec2(p->getX(), p->getY()), 0);
	this->heldBy = p;
}
