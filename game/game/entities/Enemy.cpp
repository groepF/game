#include "Enemy.h"
#include "Ball.h"

#include "../../engine/graphics/render-strategies/RenderDrawableStrategy.h"
#include "../states/AI/AIStateFactory.h"
#include "../../engine/location/Graph.h"

Enemy::Enemy(float x, float y, bool ai) : Player(x,y,ai)
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