#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"

class Ball : public DrawableEntity {
public:
	Ball(float x, float y);
	~Ball();
	void pickUp(Body* player);
	void drop();
	bool isHeldBy(Body*) const;
	void shoot(Body* from, double sideForce, double downForce);

private:
	Body* heldBy;
};
