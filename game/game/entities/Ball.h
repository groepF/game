#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"

class Ball : public Body {
public:
	Ball(float x, float y);
	void pickUp(Player* player);
	void drop();
	bool isHeldBy(Player*) const;
	void shoot(Body* from, bool left);

private:
	Player* heldBy;
};
