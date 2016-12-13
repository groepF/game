#include "RenderDrawableDebugStrategy.h"
#include "../../graphics/Screen.h"

RenderDrawableDebugStrategy::RenderDrawableDebugStrategy(IDrawableRenderDataProvider* dataProvider)
{
	this->dataProvider = dataProvider;
}

void RenderDrawableDebugStrategy::Render(Screen& screen)
{
	auto ppm = dataProvider->getPPM();
	screen.renderRect((dataProvider->getX() * ppm) - ((dataProvider->getWidth() * ppm) / 2),
		(dataProvider->getY() * ppm) - ((dataProvider->getHeight() * ppm) / 2),
		dataProvider->getWidth() * ppm,
		dataProvider->getHeight() * ppm);
}
