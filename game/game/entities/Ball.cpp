#include "Ball.h"
#include "Player.h"
#include "../../engine/graphics/render-strategies/RenderDrawableStrategy.h"

Ball::Ball(float x, float y) : DrawableEntity(std::make_shared<Sprite>(Sprite("spritesheet", 0, 140, 70, 70)), x, y, 0.3f, 0.3f, true, 1.0f, 1.0f)
{
	this->density = 0.3f;
	this->restitution = 0.8f;
	this->friction = 0.6f;
	this->type = CIRCLE;
	this->queueTaskRespawn = false;

	setExplosionSprites();
}

void Ball::setExplosionSprites()
{
	for(int i = 0; i < 12; i++)
	{
		this->explosionSprites.push_back(Sprite("explosion_ball", i*70, 0, 70, 70));
	}
	
}

Ball::~Ball()
{
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

bool Ball::scoreAnimation()
{
	this->body->SetActive(false);
	if(frames > 5 && explosionFrame < this->explosionSprites.size())
	{
		this->sprite = std::make_shared<Sprite>(this->explosionSprites.at(explosionFrame));
		explosionFrame++;
		frames = 0;
	}
	else if(explosionFrame >= this->explosionSprites.size())
	{
		this->body->SetActive(true);
		return true;
	}
	frames++;
	return false;
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

void Ball::set(float x, float y)
{
	this->body->SetActive(false);
	this->body->SetTransform(b2Vec2(x, y), 0);
	this->body->SetActive(true);
}

void Ball::setQueueTaskRespawn(bool value)
{
	queueTaskRespawn = value;
}

bool Ball::isQueueTaskRespawn() const
{
	return queueTaskRespawn;
}
