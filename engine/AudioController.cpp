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

Mix_Music* AudioController::loadBackground(const char* file)
{
	//Load the music
	Mix_Music* music = Mix_LoadMUS(file);

	//If there was a problem loading the music
	if (music == NULL)
	{
		Console::Println("Music not loaded");
		return NULL;
	}
	Console::Println("Music loaded");
	//If everything loaded fine
	return music;
}

Mix_Chunk* AudioController::loadChunks(const char * file)
{
	//Load the sound effects
	Mix_Chunk* chunk = Mix_LoadWAV(file);

	//If there was a problem loading the sound effects
	if (chunk == NULL)
	{
		return NULL;
	}

	//If everything loaded fine
	return chunk;
}

void AudioController::cleanUp()
{
	//Free the music
	//Mix_FreeMusic(music);
}

void AudioController::playSound(const char* file, int loop)
{
	if (loop < 0)
	{
		Mix_Music* music = loadBackground(file);
		Console::Println("Play backgroundmusic");
		Mix_PlayMusic(music, loop); //second parameter defines amount of loops. -1 is infinite.
	}
	else
	{
		Mix_Chunk* chunk = loadChunks(file);
		Console::Println("Play chunk");
		Mix_PlayChannel(-1, chunk, loop);
	}
}

void AudioController::stopBackgroundSound()
{
	if (Mix_PlayingMusic() != 0)
		Mix_HaltMusic();
}

void AudioController::pauseBackgroundSound()
{
	if (Mix_PausedMusic() != 1)
		Mix_PauseMusic();
}

void AudioController::resumeBackgroundSound()
{
	if (Mix_PausedMusic() == 1)
		Mix_ResumeMusic();
}

AudioController::~AudioController()
{
	//Quit SDL_mixer
	Mix_CloseAudio();
}
