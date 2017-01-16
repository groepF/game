#pragma once

#include "../../engine/world/Body.h"
#include "Player.h"
#include <vector>

class Ball : public DrawableEntity {
public:
	Ball(float x, float y);
	void setExplosionSprites();
	~Ball();
	void pickUp(Body* player);
	void drop();
	bool isHeldBy(Body*) const;
	void shoot(Body* from, double sideForce, double downForce, bool action);

	void set(float x, float y);

	void setQueueTaskRespawn(bool value);
	bool isQueueTaskRespawn() const;
	bool scoreAnimation();

private:
	Body* heldBy;

	std::vector<Sprite> explosionSprites;

	int frames = 0;
	int explosionFrame = 0;
	bool queueTaskRespawn;
};
