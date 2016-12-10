#pragma once

#include "../../engine/world/Body.h"
#include "../../engine/core-entities/DrawableEntity.h"

class Enemy : public DrawableEntity {
public:
	Enemy(float x, float y);
	void setDefaultRenderStrategy() override;
};
