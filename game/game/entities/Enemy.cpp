#include "Enemy.h"
#include "Ball.h"

#include "../../engine/graphics/render-strategies/RenderDrawableStrategy.h"
#include "../states/AI/AIStateFactory.h"

Enemy::Enemy(float x, float y) : DrawableEntity(std::make_shared<Sprite>(Sprite("player", 19, 0, 19, 40)), x, y, 0.25f, 0.5f, true)
{
	this->density = 0.4f;
	this->restitution = 0.0f;
	this->friction = 0.5f;
	this->type = CIRCLE;

	
}

void Enemy::action(StateContext* context, Keyboard *keyboard)
{

	currentState = AIStateFactory::getInstance()->getState("BallState", context);

	currentState->onUpdate(keyboard);


}

/**
* Makes the enemy drop the ball
* @param b the ball to drop
*/
void Enemy::hitByPlayer(Ball* b) const
{
	b->drop();
}
