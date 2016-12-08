#pragma once
#include "IRenderStrategy.h"
#include <SDL/SDL_ttf.h>
#include <string>
#include <map>
#include <memory>
#include "data-providers/ITextRenderDataPorvider.h"

class RenderTextStrategy : public IRenderStrategy
{
public:
	RenderTextStrategy(std::shared_ptr<ITextRenderDataPorvider> dataProvider);
	virtual ~RenderTextStrategy() = default;
	void Render(Screen& screen) override;

private:
	TTF_Font* font;
	std::shared_ptr<ITextRenderDataPorvider> dataProvider;
};

