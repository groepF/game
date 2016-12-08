#include "DrawableEntity.h"

DrawableEntity::DrawableEntity(std::shared_ptr<Sprite> s, float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping) : Body(x, y, width, height, dynamic, angularDamping, linearDamping)
{
	sprite = s;
}

DrawableEntity::~DrawableEntity()
{
}

std::shared_ptr<Sprite> DrawableEntity::getSprite() const
{
	return sprite;
}