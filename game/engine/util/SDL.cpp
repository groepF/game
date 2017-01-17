#include "SDL.h"

bool SDL::start()
{
	// Initialize subsystems separatedly.

	if (SDL_Init(0) < 0)
	{
		Log::error("SDL_Init: Couldn't start SDL");
		Log::error(std::string(SDL_GetError()));
		throw "SDL Init Fail";
	}

	// Initializing everything related to AUDIO

	if (SDL_WasInit(SDL_INIT_AUDIO) != 0)
	{
		Log::error("SDL_WasInit: Tried to reinitailize audio");
		Log::error(SDL_GetError());
		throw "SDL_WasInit Fail";
	}

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		Log::error("SDL_Init: Couldn't start audio");
		Log::error(std::string(SDL_GetError()));
		throw "SDL_Init Fail";
	}

	auto flags = MIX_INIT_OGG | MIX_INIT_MP3;
	if ((Mix_Init(flags) & flags) != flags)
	{
		Log::warning("Mix_Init: Couldn't start audio");
		Log::warning(Mix_GetError());
	}

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		Log::warning("Mix_OpenAudio: Couldn't start audio");
		Log::warning(Mix_GetError());
	}

	// Reserving 16 channels (meaning 16 simultaneous SFXs playing).
	Mix_AllocateChannels(16);

	// Initializing everything related to VIDEO

	flags = (SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if (SDL_WasInit(flags) != 0)
	{
		Log::error("SDL_WasInit: Tried to reinitailize video");
		Log::error(std::string(SDL_GetError()));
		throw "SDL_WasInit Fail";
	}

	if (SDL_InitSubSystem(flags) < 0)
	{
		Log::error("SDL_Init: Couldn't start video");
		Log::error(std::string(SDL_GetError()));
		throw "SDL_Init Fail";
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		Log::error("IMG_Init: Couldn't start PNG support");
		Log::error(std::string(IMG_GetError()));
		throw "IMG_Init Fail";
	}

	if (TTF_Init() == -1)
	{
		Log::error("TTF_Init: Couldn't start TTF support");
		Log::error(std::string(TTF_GetError()));
		throw "TTF_Init Fail";
	}

	return true;
}

void SDL::stop()
{
	// Free all allocated channels.
	Mix_AllocateChannels(0);

	// Close the audio.
	Mix_CloseAudio();

	// Unload all the fonts.
	if (TTF_WasInit())
	{
		TTF_Quit();
	}

	// Unload image libraries.
	IMG_Quit();
		
	// Quit SDL2 entirely.
	SDL_Quit();
}
