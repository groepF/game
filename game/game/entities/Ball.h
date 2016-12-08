#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"

class Ball : public Body {
public:
	Ball(float x, float y);
	void pickUp(Body* player);
	void drop();
	bool isHeldBy(Body*) const;

private:
	Body* heldBy;
};
