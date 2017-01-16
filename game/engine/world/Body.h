#pragma once

#include "Box2D/Box2D.h"
#include "../graphics/Sprite.h"
#include <SDL/SDL_stdinc.h>
#include "../graphics/render-strategies/IRenderStrategy.h"

enum BodyType
{
	BOX,
	CIRCLE
};

class Body
{
public:
	Body(float x, float y, float width, float height, bool dynamic = false, float angularDamping = 0.0f, float linearDamping = 0.0f, bool isPlayer = false);
	virtual ~Body();

	float getBodyX() const;
	float getBodyY() const;
	float getBodyWidth() const;
	float getBodyHeight() const;
	float getBodyAngle() const;

	virtual void create(b2Body *body);
	void setVelocity(float x, float y) const;
	void setFixedRotation(bool rotation) const;

	virtual void setDefaultRenderStrategy() = 0;

	b2BodyDef* getBodyDef();

	void setUserData(void* item) const
	{
		body->SetUserData(item);
	}

	virtual void Render(Screen& screen, bool debug = false) const = 0;

private:
	b2BodyDef bodyDef;
protected:
	float width, height;
	BodyType type;
	b2Body *body;
	bool isPlayer;
	float density, friction, restitution;
	std::shared_ptr<IRenderStrategy> renderStrategy;
	std::shared_ptr<IRenderStrategy> renderDebugStrategy;
};
