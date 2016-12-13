#pragma once
#include <SDL/SDL.h>
class Screen;

class IRenderStrategy
{
public:
	virtual ~IRenderStrategy() {}

	virtual void Render(Screen& screen) = 0;
};
