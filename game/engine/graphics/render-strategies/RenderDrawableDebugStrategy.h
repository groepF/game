#pragma once
#include "data-providers/IDrawableRenderDataProvider.h"
#include <memory>
#include "IRenderStrategy.h"

class RenderDrawableDebugStrategy : public IRenderStrategy
{
public:
	RenderDrawableDebugStrategy(IDrawableRenderDataProvider* dataProvider);
	virtual ~RenderDrawableDebugStrategy() = default;
	void Render(Screen& screen) override;

private:
	IDrawableRenderDataProvider* dataProvider;
};

