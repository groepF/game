#pragma once
#include "C:\Users\Diede\Documents\School\game\game\engine\world\Body.h"
class DrawableEntity : public Body
{
public:
	DrawableEntity(std::shared_ptr<Sprite> s, float x, float y, float width, float height, bool dynamic = false, float angularDamping = 0.0f, float linearDamping = 0.0f);
	~DrawableEntity();

	std::shared_ptr<Sprite> getSprite() const;

protected:
	std::shared_ptr<Sprite> sprite;
};

