#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"

class Ball : public DrawableEntity {
public:
	Ball(float x, float y);
	void pickUp(Player* player);
	void drop();
	bool isHeldBy(Player*) const;

private:
	Player* heldBy;
};
