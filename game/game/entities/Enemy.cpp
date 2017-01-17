#include "Enemy.h"
#include "Ball.h"

#include "../../engine/graphics/render-strategies/RenderDrawableStrategy.h"
#include "../states/AI/AIStateFactory.h"
#include "../../engine/location/Graph.h"

Enemy::Enemy(Sprite sprite, float x, float y, bool ai) : Player(sprite,x,y,ai)
{
	this->density = 0.4f;
	this->restitution = 0.0f;
	this->friction = 0.5f;
	this->type = CIRCLE;
}

void Enemy::action(StateContext* context, Keyboard *keyboard, Game *game)
{

	currentState = AIStateFactory::getInstance()->getState("BallState", context, game);

	currentState->onUpdate(keyboard);


}

bool Enemy::isMoving() const
{

	auto xVel = body->GetLinearVelocity().x;
	auto yVel = body->GetLinearVelocity().y;

	return (xVel > 0 || yVel > 0);

}