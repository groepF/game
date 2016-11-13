#include "Ball.h"

Ball::Ball(b2World& world, float x, float y, float width, float height) : width(width), height(height), body(nullptr)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	auto bbody = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(width, height);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.5f;
	fixtureDef.restitution = 0.8f;

	bbody->CreateFixture(&fixtureDef);

	body = bbody;
	sprite = new Sprite("spritesheet", 0, 70, 70, 70);
}

Ball::~Ball()
{
	delete sprite;
}

float Ball::getX() const
{
	return body->GetPosition().x;
}

float Ball::getY() const
{
	return body->GetPosition().y;
}

float Ball::getWidth() const
{
	return width * 2;
}

float Ball::getHeight() const
{
	return height * 2;
}

b2Body* Ball::getBody() const
{
	return body;
}

void Ball::render(Screen *screen)
{
	auto temp = 50;
	screen->render(sprite,
		(getX() * temp) - ((getWidth() * temp) / 2),
		(getY() * temp) - ((getHeight() * temp) / 2),
		0,
		1,
		255, getWidth() * temp, getHeight() * temp);
}
