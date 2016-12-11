#pragma once
#include "IRenderStrategy.h"
#include <memory>
#include "data-providers/IDrawableRenderDataProvider.h"

class RenderDrawableStrategy : public IRenderStrategy
{
public:
	RenderDrawableStrategy(IDrawableRenderDataProvider* dataProvider);
	virtual ~RenderDrawableStrategy() = default;
	void Render(Screen& screen) override;

private:
	IDrawableRenderDataProvider* dataProvider;
};

