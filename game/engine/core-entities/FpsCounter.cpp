#include "FpsCounter.h"
#include <SDL/SDL.h>
#include <sstream>
#include "../util/Log.h"
#include "../graphics/render-strategies/RenderTextStrategy.h"
#include "DrawableEntity.h"

FpsCounter::FpsCounter(bool showFps, int x, int y, int width, int height, Color color) : TextualEntity("fps", x, y, width, height, color)
{
	// Set all frame times to 0ms.
	memset(frametimes, 0, sizeof(frametimes));
	framecount = 0;
	framespersecond = 0;
	frametimelast = SDL_GetTicks();
	this->isShown = showFps;
}

void FpsCounter::CalculateCurrentFps()
{
	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;

	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = framecount % FRAME_VALUES;

	// store the current time
	getticks = SDL_GetTicks();

	// save the frame time value
	frametimes[frametimesindex] = getticks - frametimelast;

	// save the last frame time for the next fpsthink
	frametimelast = getticks;

	// increment the frame count
	framecount++;

	// Work out the current framerate

	// The code below could be moved into another function if you don't need the value every frame.

	// I've included a test to see if the whole array has been written to or not. This will stop
	// strange values on the first few (FRAME_VALUES) frames.
	if (framecount < FRAME_VALUES) {

		count = framecount;

	}
	else {

		count = FRAME_VALUES;

	}

	// add up all the values and divide to get the average frame time.
	framespersecond = 0;
	for (i = 0; i < count; i++) {

		framespersecond += frametimes[i];

	}

	framespersecond /= count;

	// now to make it an actual frames per second value...
	framespersecond = 1000.f / framespersecond;
}

void FpsCounter::Render(Screen& screen, bool debug) const
{
	if (isShown)
	{
		TextualEntity::Render(screen, debug);
	}
}

std::string FpsCounter::getText()
{
	return std::to_string(static_cast<int>(std::round(framespersecond)));
}

void FpsCounter::setDefaultRenderStrategy()
{
	renderStrategy = std::make_shared<RenderTextStrategy>(RenderTextStrategy(this));
}

void FpsCounter::toggle()
{
	isShown = !isShown;
}
