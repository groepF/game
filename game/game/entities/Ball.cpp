#include "Ball.h"
#include "Player.h"
#include "../../engine/graphics/render-strategies/RenderDrawableStrategy.h"

Ball::Ball(float x, float y) : DrawableEntity(std::make_shared<Sprite>(Sprite("spritesheet", 0, 140, 70, 70)), x, y, 0.3f, 0.3f, true, 1.0f, 1.0f)
{
	this->density = 0.3f;
	this->restitution = 0.8f;
	this->friction = 0.6f;
	this->type = CIRCLE;
}

Ball::~Ball()
{
	this->getBody()->GetWorld()->DestroyBody(this->getBody());
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

/*
 * Shoots ball
 * Body* body - Entity that shoots
 * bool left - if is shot left
 */
void Ball::shoot(Body* from, double sideForce, double downForce)
{
	this->body->ApplyForce(b2Vec2(sideForce, downForce), b2Vec2(from->getBodyX(), from->getBodyY()), false);

}

/*
 * Sets the ball as picked up. Makes holder the current player.
 * Player* p - The player that performs the action
 */
void Ball::pickUp(Body* p)
{
	this->body->SetActive(false);
	this->body->SetTransform(b2Vec2(p->getBodyX(), p->getBodyY()), 0);
	this->heldBy = p;
}
