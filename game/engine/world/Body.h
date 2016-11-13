#pragma once

#include "Box2D/Box2D.h"
#include "../graphics/Sprite.h"
#include "../graphics/Screen.h"

class Body
{
public:
	Body(b2World& world, float x, float y, float width, float height);
	~Body();

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	void render(Screen *screen);

private:
	float width, height;
	b2Body *body;
	Sprite* sprite;
};
