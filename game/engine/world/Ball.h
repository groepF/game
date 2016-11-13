#pragma once

#include "Box2D/Box2D.h"
#include "../graphics/Sprite.h"
#include "../graphics/Screen.h"

class Ball
{
public:
	Ball(b2World& world, float x, float y, float width, float height);
	~Ball();

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	b2Body* getBody() const;

	void render(Screen *screen);

private:
	float width, height;
	b2Body *body;
	Sprite* sprite;
};
