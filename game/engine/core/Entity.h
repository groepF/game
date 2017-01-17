#pragma once

#include <string>
#include "../graphics/Sprite.h"
#include "../graphics/Screen.h"

class Entity
{
public:
	virtual ~Entity()
	{
		delete sprite;
		sprite = nullptr;
	}

	Entity(Entity const &) = delete;
	Entity & operator=(Entity const &) = delete;

	float getX() const { return x; }
	float getY() const { return y; }
	Sprite* getSprite() const { return sprite; }

	virtual void onUpdate(float delta) = 0;

	void setPosition(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

protected:
	Entity() = default;
	float x, y;
	Sprite* sprite;
};
