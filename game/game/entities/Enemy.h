#pragma once

#include "../../engine/world/Body.h"

class Player;

class Enemy : public Body {
public:
	Enemy(float x, float y);
	void hitByPlayer(Player* player) const;
	
private:
};
