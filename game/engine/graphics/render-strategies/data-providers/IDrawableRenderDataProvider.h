#pragma once
#include "../../Sprite.h"

class IDrawableRenderDataProvider
{
public:
	virtual ~IDrawableRenderDataProvider() = 0;

	virtual float getX() const = 0;
	virtual float getY() const = 0;
	virtual float getHeight() const = 0;
	virtual float getWidth() const = 0;
	virtual double getAngle() const = 0;
	virtual Sprite* getSprite() const = 0;
	virtual int getPPM() const = 0;
};

