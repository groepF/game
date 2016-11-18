#include "Body.h"

Body::Body(Sprite* s, float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping) : width(width), height(height), type(BOX), body(nullptr), density(0.0f), friction(0.0f), restitution(0.0f)
{
	bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.angularDamping = angularDamping;
	bodyDef.linearDamping = linearDamping;

	sprite = s; // new Sprite("metal", 0, 40, 20, 20);
}

Body::Body(float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping) : width(width), height(height), type(BOX), body(nullptr), density(0.0f), friction(0.0f), restitution(0.0f)
{
	bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.angularDamping = angularDamping;
	bodyDef.linearDamping = linearDamping;

	sprite = new Sprite("metal", 0, 40, 20, 20);
}

Body::~Body()
{
	delete sprite;
}

float Body::getX() const
{
	return body->GetPosition().x;
}

float Body::getY() const
{
	return body->GetPosition().y;
}

float Body::getWidth() const
{
	return width * 2;
}

float Body::getHeight() const
{
	return height * 2;
}

float Body::getAngle() const
{
	return body->GetAngle() * (180 / M_PI);
}

Sprite* Body::getSprite() const
{
	return sprite;
}

void Body::create(b2Body *body)
{
	b2PolygonShape box;
	box.SetAsBox(width, height);

	b2CircleShape circle;
	circle.m_p.Set(0, 0);
	circle.m_radius = width;

	b2FixtureDef fixtureDef;
	if (type == BOX)
	{
		fixtureDef.shape = &box;
	}
	if (type == CIRCLE)
	{
		fixtureDef.shape = &circle;
	}
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	body->CreateFixture(&fixtureDef);

	this->body = body;
}

void Body::setVelocity(float x, float y)
{
	auto impulse = body->GetMass() * 10;
	body->ApplyLinearImpulse(b2Vec2(0, impulse), body->GetWorldCenter(), true);
}

void Body::setFixedRotation(bool rotation) const
{
	body->SetFixedRotation(rotation);
}

b2BodyDef* Body::getBodyDef()
{
	return &bodyDef;
}
