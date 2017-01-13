#include "Body.h"

Body::Body(float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping, bool isPlayer) : width(width), height(height), type(BOX), body(nullptr), isPlayer(isPlayer), density(0.0f), friction(0.0f), restitution(0.0f)
{
	bodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.angularDamping = angularDamping;
	bodyDef.linearDamping = linearDamping;
}

Body::~Body()
{
}

float Body::getBodyX() const
{
	return body->GetPosition().x;
}

float Body::getBodyY() const
{
	return body->GetPosition().y;
}

float Body::getBodyWidth() const
{
	return width * 2;
}

float Body::getBodyHeight() const
{
	return height * 2;
}

float Body::getBodyAngle() const
{
	return body->GetAngle() * (180 / M_PI);
}

void Body::create(b2Body *body)
{
	if (!isPlayer)
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
	else
	{
		b2CircleShape circle;
		circle.m_p.Set(0, 0);
		circle.m_radius = width;

		b2FixtureDef fixtureDef;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		fixtureDef.restitution = restitution;

		fixtureDef.shape = &circle;
		body->CreateFixture(&fixtureDef);

		circle.m_p.Set(0, height);
		circle.m_radius = width;

		body->CreateFixture(&fixtureDef);

		this->body = body;
	}
}

void Body::setVelocity(float x, float y) const
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
