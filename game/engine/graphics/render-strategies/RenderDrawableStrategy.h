#pragma once
#include "IRenderStrategy.h"
#include "data-providers/ITextRenderDataPorvider.h"
#include <memory>

class RenderDrawableStrategy : public IRenderStrategy
{
public:
	RenderDrawableStrategy(std::shared_ptr<ITextRenderDataPorvider> dataProvider) {}

	virtual ~RenderDrawableStrategy() = default;

	void Render(Screen& screen) override;

private:
	std::shared_ptr<ITextRenderDataPorvider> dataProvider;
};

