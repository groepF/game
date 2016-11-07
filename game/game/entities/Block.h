#pragma once

#include "../../engine/core/Entity.h"

enum GrassType
{
	LEFT,
	CENTER,
	RIGHT
};

class Block : public Entity
{
public:
	Block(float x, float y, GrassType);
	~Block();

	void onUpdate(float delta) final;
};