#include "AudioController.h"
#include <SDL/SDL_mixer.h>
#include "Console.h"

AudioController::AudioController()
{
	initSound();
}

bool AudioController::initSound()
{
	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}

bool AudioController::loadFiles(const char* file)
{
	//Load the music
	music = Mix_LoadMUS(file);

	//If there was a problem loading the music
	if (music == NULL)
	{
		Console::Println("Music not loaded");
		return false;
	}
	Console::Println("Music loaded");
	//If everything loaded fine
	return true;
}

void AudioController::cleanUp()
{
	//Free the music
	Mix_FreeMusic(music);
}

void AudioController::playSound(const char* file)
{
	loadFiles(file);

	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music, 1); //second parameter defines amount of loops. -1 is infinite.
	}
	//If music is being played
	else
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}
}

void AudioController::stopSound()
{
	if (Mix_PlayingMusic() != 0)
		Mix_PauseMusic();
}

AudioController::~AudioController()
{
	//Quit SDL_mixer
	Mix_CloseAudio();
}
