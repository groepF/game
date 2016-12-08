#pragma once
#include "data-providers/IDrawableRenderDataProvider.h"
#include <memory>
#include "IRenderStrategy.h"

class RenderDrawableDebugStrategy : IRenderStrategy
{
public:
	RenderDrawableDebugStrategy(std::shared_ptr<IDrawableRenderDataProvider> dataProvider);

	virtual ~RenderDrawableDebugStrategy() = default;

	void Render(Screen& screen) override;
private:
	std::shared_ptr<IDrawableRenderDataProvider> dataProvider;
};

