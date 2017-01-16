#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"
#include <vector>

class Ball : public DrawableEntity {
public:
	Ball(float x, float y);
	void setExplosionSprites();
	void pickUp(Body* player);
	void drop();
	bool isHeldBy(Body*) const;
	void shoot(Body* from, double sideForce, double downForce);

	bool scoreAnimation();

private:
	Body* heldBy;

	std::vector<Sprite> explosionSprites;

	int frames = 0;
	int explosionFrame = 0;
};
