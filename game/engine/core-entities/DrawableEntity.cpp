#include "DrawableEntity.h"
#include "../util/Log.h"
#include "../graphics/render-strategies/RenderDrawableStrategy.h"
#include "../graphics/render-strategies/RenderDrawableDebugStrategy.h"

DrawableEntity::DrawableEntity(std::shared_ptr<Sprite> s, float x, float y, float width, float height, bool dynamic, float angularDamping, float linearDamping, bool isPlayer) : Body(x, y, width, height, dynamic, angularDamping, linearDamping, isPlayer)
{
	sprite = s;
}


void DrawableEntity::Render(Screen& screen, bool debug) const
{

	if (debug && renderDebugStrategy != nullptr)
	{
		renderDebugStrategy->Render(screen);
	}
	else
	{
		if (renderStrategy == nullptr)
		{
			Log::error("Your drawable entity does not have a renderStrategy. Please set it. (You'll most likely want to use the RenderDrawableStrategy)");
			return;
		}
		renderStrategy->Render(screen);
	}
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

void DrawableEntity::setSprites(Sprite sprite, Sprite sprite2)
{
	this->sprite = std::make_shared<Sprite>(sprite);
	this->secondSprite = std::make_shared<Sprite>(sprite2);
	this->stillSprite = std::make_shared<Sprite>(sprite);
	this->walkSprite = std::make_shared<Sprite>(sprite2);
}

void DrawableEntity::setSpriteJump()
{
	this->sprite = this->stillSprite;
	this->secondSprite = this->walkSprite;
}

void DrawableEntity::toggleSprite()
{
	auto tempSprite = this->sprite;
	this->sprite = this->secondSprite;
	this->secondSprite = tempSprite;
}


int DrawableEntity::getPPM() const
{
	return 50;
}

void DrawableEntity::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderDrawableStrategy>(RenderDrawableStrategy(this));
	renderDebugStrategy = std::make_shared<RenderDrawableDebugStrategy>(RenderDrawableDebugStrategy(this));
}
