#include "RenderDrawableStrategy.h"


RenderDrawableStrategy::RenderDrawableStrategy(std::shared_ptr<ITextRenderDataPorvider> dataProvider)
{
	this->dataProvider = dataProvider;
}

void RenderDrawableStrategy::Render(Screen& screen)
{
	// take code out of World.cpp
}
