#pragma once

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Log.h"

namespace SDL
{
	/// Starts SDL2 and initializes subsystems like audio, video, image and ttf support.
	bool start();
	/// Stops SDL2 and all the initialized subsystems.
	void stop();
}