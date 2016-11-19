#pragma once

#include "Box2D/Box2D.h"
#include "../graphics/Sprite.h"
#include <SDL/SDL_stdinc.h>

enum BodyType
{
	BOX,
	CIRCLE
};

class Body
{
public:
	Body(float x, float y, float width, float height, bool dynamic = false, float angularDamping = 0.0f, float linearDamping = 0.0f);
	Body(Sprite* s, float x, float y, float width, float height, bool dynamic = false, float angularDamping = 0.0f, float linearDamping = 0.0f);
	~Body();

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	float getAngle() const;
	Sprite* getSprite() const;
	b2BodyDef* getBodyDef();

	void create(b2Body *body);
	void setVelocity(float x, float y) const;
	void setFixedRotation(bool rotation) const;

private:
	float width, height;
	b2BodyDef bodyDef;
protected:
	BodyType type;
	b2Body *body;
	Sprite* sprite;
	float density, friction, restitution;
};
