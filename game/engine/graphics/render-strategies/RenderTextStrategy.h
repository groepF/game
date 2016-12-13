#pragma once
#include "IRenderStrategy.h"
#include <SDL/SDL_ttf.h>
#include <string>
#include <map>
#include <memory>
#include "data-providers/ITextRenderDataProvider.h"

class RenderTextStrategy : public IRenderStrategy
{
public:
	RenderTextStrategy(ITextRenderDataProvider* dataProvider);
	void Render(Screen& screen) override;

private:
	TTF_Font* font;
	ITextRenderDataProvider* dataProvider;
};

