#pragma once
#include <string>
#include "../graphics/Screen.h"
#include <SDL/SDL_hints.h>
#include "TextualEntity.h"


// How many frames time values to keep
// The higher the value the smoother the result is...
// Don't make it 0 or less :)
#define FRAME_VALUES 100

class FpsCounter : public TextualEntity
{
public:
	/*
	 * The FpsCounter constructor.
	 * 
	 * @param x The x pos of the text on the screen.
	 * @param y The y pos of the text on the screen.
	 * @param width The width of the text on the screen.
	 * @param height The height of the text on the screen.
	 */
	FpsCounter(int x = 10, int y = 0, int width = 50, int height = 40);

	const char* GetText() override;

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
