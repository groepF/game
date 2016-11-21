#pragma once
#include <string>
#include "../graphics/Screen.h"

class FpsCounter
{
public:
	FpsCounter();
	void outputFPS(Screen& screen);
private:
	int getCurrentFps();
	Uint32 currentFPS;
	Uint32 deltaclock;
	Uint32 startclock;
};
