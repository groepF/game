#pragma once

#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_mixer.h"
#include "Log.h"

/// Wrapper for SDL2.
///
/// This initializes and exits SDL2.

namespace SDL
{

	bool initialize();

	void exit();
	
}