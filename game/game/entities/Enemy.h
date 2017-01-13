#pragma once

#include "../../engine/world/Body.h"
#include "../../engine/core-entities/DrawableEntity.h"
#include "../../engine/core/State.h"

class Ball;
class Player;

class Enemy : public DrawableEntity {
public:
	Enemy(float x, float y);
	void action(StateContext*, Keyboard*);
	void hitByPlayer(Ball* b) const;

private:
	State* currentState;
};
