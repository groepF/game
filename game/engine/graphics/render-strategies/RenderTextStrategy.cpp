#include "RenderTextStrategy.h"
#include "../../util/Log.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "../../util/Color.h"
#include "../../graphics/Screen.h"

RenderTextStrategy::RenderTextStrategy(ITextRenderDataProvider* dataProvider) : font(TTF_OpenFont("engine/res/fonts/comic.ttf", 24))
{
	this->dataProvider = dataProvider;
}

void RenderTextStrategy::Render(Screen& screen)
{
	screen.renderText(dataProvider->getText(), dataProvider->getColor(), dataProvider->getX(), dataProvider->getY(), dataProvider->getWidth(), dataProvider->getHeight());
}
