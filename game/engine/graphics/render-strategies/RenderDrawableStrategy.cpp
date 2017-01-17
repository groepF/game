#include "RenderDrawableStrategy.h"
#include "../../graphics/Screen.h"


RenderDrawableStrategy::RenderDrawableStrategy(IDrawableRenderDataProvider* dataProvider)
{
	this->dataProvider = dataProvider;
}

void RenderDrawableStrategy::Render(Screen& screen)
{
	auto ppm = dataProvider->getPPM();
	screen.render(dataProvider->getSprite(),
		(dataProvider->getX() - (dataProvider->getWidth() / 2)) * ppm,
		(dataProvider->getY() - (dataProvider->getHeight() / 2)) * ppm,
		dataProvider->getAngle(),
		255, dataProvider->getWidth() * ppm, dataProvider->getHeight() * ppm);
}
