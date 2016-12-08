#include "DrawableEntity.h"

DrawableEntity::DrawableEntity(std::shared_ptr<Sprite> s, float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping) : Body(x, y, width, height, dynamic, angularDamping, linearDamping)
{
	sprite = s;
}

DrawableEntity::~DrawableEntity()
{
}

float DrawableEntity::getX() const
{
	return Body::getX();
}

float DrawableEntity::getY() const
{
	return Body::getY();
}

float DrawableEntity::getHeight() const
{
	return Body::getHeight();
}

float DrawableEntity::getWidth() const
{
	return Body::getWidth();
}

double DrawableEntity::getAngle() const
{
	return Body::getAngle();
}

Sprite* DrawableEntity::getSprite() const
{
	return sprite.get();
}

int DrawableEntity::getPPM() const
{
	return 50;
}
