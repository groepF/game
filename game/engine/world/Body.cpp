#include "Body.h"

Body::Body(float x, float y, float width, float height, bool dynamic) : width(width), height(height), body(nullptr), density(0.0f), friction(0.0f), restitution(0.0f)
{
	bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(x, y);

	sprite = new Sprite("spritesheet", 70, 0, 70, 70);
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

Sprite* Body::getSprite() const
{
	return sprite;
}

void Body::create(b2Body *body)
{
	b2PolygonShape box;
	box.SetAsBox(width, height);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
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

b2BodyDef* Body::getBodyDef()
{
	return &bodyDef;
}
