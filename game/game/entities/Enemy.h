#pragma once

#include "../../engine/world/Body.h"
#include "../../engine/core-entities/DrawableEntity.h"
#include "../../engine/core/State.h"
#include "Player.h"

class Game;
class Ball;
class Keyboard;

class Enemy : public Player {
public:
	Enemy(float x, float y, bool ai);
	void action(StateContext*, Keyboard*, Game*);
	void hitByPlayer(Ball* b) const;

private:
	State* currentState;
};
