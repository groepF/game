#include "FpsCounter.h"
#include <SDL/SDL.h>
#include <sstream>
#include "../util/Log.h"
#include "../graphics/Screen.h"

FpsCounter::FpsCounter()
{
	this->deltaclock = 0;
	this->currentFPS = 0;
	this->startclock = SDL_GetTicks();
}


void FpsCounter::outputFPS(Screen& screen)
{
	screen.renderText(std::to_string(getCurrentFps()).c_str(), Color("white"), 0,0,50,50);
}

int FpsCounter::getCurrentFps()
{
	this->deltaclock = SDL_GetTicks() - this->startclock;
	this->startclock = SDL_GetTicks();

	if (deltaclock != 0)
	{
		this->currentFPS = 1000 / deltaclock;
	}

	return currentFPS;
}
