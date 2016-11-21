#pragma once
#include <string>
#include "../graphics/Screen.h"


// How many frames time values to keep
// The higher the value the smoother the result is...
// Don't make it 0 or less :)
#define FRAME_VALUES 100

class FpsCounter
{
public:
	FpsCounter();
	void outputFPS(Screen& screen);
private:
	int getCurrentFps();

	// An array to store frame times:
	Uint32 frametimes[FRAME_VALUES];

	// Last calculated SDL_GetTicks
	Uint32 frametimelast;

	// total frames rendered
	Uint32 framecount;

	// the value you want
	float framespersecond;
};
