#pragma once

#include "../../engine/core/Entity.h"

class Player : public Entity {
public:
	Player(float x, float y);

	void onUpdate(float delta) final;
};
