#pragma once

#include "../../engine/world/Body.h"

class Ball;
class Player;

class Enemy : public Body {
public:
	Enemy(float x, float y);
	void hitByPlayer(Ball* b) const;
	
private:
};
