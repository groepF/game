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
	void shoot(Body* from, double sideForce, double downForce, bool action);

	void set(float x, float y);

	void setQueueTaskRespawn(bool value);
	bool isQueueTaskRespawn() const;

private:
	Body* heldBy;
	bool queueTaskRespawn;
};
