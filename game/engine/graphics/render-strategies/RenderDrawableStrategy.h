#pragma once
#include "IRenderStrategy.h"
#include <memory>
#include "data-providers/IDrawableRenderDataProvider.h"

class RenderDrawableStrategy : public IRenderStrategy
{
public:
	RenderDrawableStrategy(std::shared_ptr<IDrawableRenderDataProvider> dataProvider);
	virtual ~RenderDrawableStrategy() = default;
	void Render(Screen& screen) override;

private:
	std::shared_ptr<IDrawableRenderDataProvider> dataProvider;
};

