#pragma once

#include "Box2D/Box2D.h"
#include "../graphics/Sprite.h"
#include "../graphics/Screen.h"

class Body
{
public:
	Body(float x, float y, float width, float height, bool dynamic = false);
	~Body();

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	Sprite* getSprite() const;
	b2BodyDef* getBodyDef();

	void create(b2Body *body);
	void setVelocity(float x, float y);

private:
	float width, height;
	b2BodyDef bodyDef;
protected:
	b2Body *body;
	Sprite* sprite;
	float density, friction, restitution;
};
