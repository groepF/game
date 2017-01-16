#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"

class Ball : public DrawableEntity {
public:
	Ball(float x, float y);
	void pickUp(Body* player);
	void drop();
	bool isHeldBy(Body*) const;
	void shoot(Body* from, double sideForce, double downForce, bool action);

private:
	Body* heldBy;
};
