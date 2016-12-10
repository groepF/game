#include "DrawableEntity.h"
#include "../util/Log.h"
#include "../graphics/render-strategies/RenderDrawableStrategy.h"

DrawableEntity::DrawableEntity(std::shared_ptr<Sprite> s, float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping) : Body(x, y, width, height, dynamic, angularDamping, linearDamping)
{
	sprite = s;
}


void DrawableEntity::Render(Screen& screen) const
{
	if (renderStrategy == nullptr)
	{
		Log::error("Your drawable entity does not have a renderStrategy. Please set it. (You'll most likely want to use the RenderDrawableStrategy or RenderDrawableDebugStrategy)");
		return;
	}
	renderStrategy->Render(screen);
}

float DrawableEntity::getX() const
{
	return Body::getBodyX();
}

float DrawableEntity::getY() const
{
	return Body::getBodyY();
}

float DrawableEntity::getHeight() const
{
	return Body::getBodyHeight();
}

float DrawableEntity::getWidth() const
{
	return Body::getBodyWidth();
}

double DrawableEntity::getAngle() const
{
	return Body::getBodyAngle();
}

Sprite* DrawableEntity::getSprite() const
{
	return sprite.get();
}

int DrawableEntity::getPPM() const
{
	return 50;
}

void DrawableEntity::setDefaultRenderStrategy()
{
	auto dataProvider = std::make_shared<DrawableEntity>(*this);
	renderStrategy = std::make_shared<RenderDrawableStrategy>(RenderDrawableStrategy(dataProvider));
}
