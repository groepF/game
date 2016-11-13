#include "Body.h"

Body::Body(b2World& world, float x, float y, float width, float height) : width(width), height(height), body(nullptr)
{
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(x, y);

	auto groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(width, height);

	groundBody->CreateFixture(&groundBox, 0.0f);

	body = groundBody;
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

void Body::render(Screen *screen)
{
	auto temp = 50;
	screen->render(sprite,
		(getX() * temp) - ((getWidth() * temp) / 2),
		(getY() * temp) - ((getHeight() * temp) / 2),
		0,
		1,
		255, getWidth() * temp, getHeight() * temp);
}
