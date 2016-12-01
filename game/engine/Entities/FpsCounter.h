#pragma once
#include <string>
#include "../graphics/Screen.h"
#include <SDL/SDL_hints.h>


// How many frames time values to keep
// The higher the value the smoother the result is...
// Don't make it 0 or less :)
#define FRAME_VALUES 100

class FpsCounter
{
public:
	/*
	 * The FpsCounter constructor.
	 */
	FpsCounter();

	/* 
	 * Outputs a visual fps counter.
	 * @param screen The screen to output the fps on.
	 */
	void outputFPS(Screen& screen);
private:
	/*
	 * Calculates the currnet fps.
	 * @return The amount of frames per second
	 */
	int getCurrentFps();

	// An array to store frame times:
	Uint32 frametimes[FRAME_VALUES];

	// Last calculated SDL_GetTicks.
	Uint32 frametimelast;

	// Total frames rendered.
	Uint32 framecount;

	// The current amount of frames per second.
	float framespersecond;
};
