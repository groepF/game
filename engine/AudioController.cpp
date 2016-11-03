#include "AudioController.h"
#include <SDL/SDL_mixer.h>
#include "Console.h"
#include <thread>

/*
* Constructor
*/
AudioController::AudioController()
{
	initSound();
}

/*
 * Initializes the SDL Audio library.
 * Chooses a frequency, channel and reserves a chunk for music
 */
bool AudioController::initSound()
{
	//Initialize SDL_mixer
	int frequency = 22050;
	int channels = 2;
	int chunkSize = 4096;

	return !(Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channels, chunkSize) == -1);
}

/*
 * Loads the background music file
 * @param file The path of the background music file
 * @return The actual music
 */
Mix_Music* AudioController::loadBackground(const char* file)
{
	//Load the music
	Mix_Music* music = Mix_LoadMUS(file);

	return music;
}

/*
* Loads the chunk music file
* @param file The path of the chunk music file
* @return The actual chunk
*/
Mix_Chunk* AudioController::loadChunks(const char * file)
{
	//Load the sound effects
	Mix_Chunk* chunk = Mix_LoadWAV(file);

	return chunk;
}

/*
* General method to play a sound file
* @param file The path of the music file
* @param backgroundMusic check if file is background music or a chunk
*/
void AudioController::playSound(const char* file, bool backgroundMusic)
{
	if(backgroundMusic)
	{
		std::thread t(playBackgroundMusic, file);
		//playBackgroundMusic(file);
	}
	else
	{
		playChunk(file);
	}
}

/*
* Plays a chunk music file
* @param file The path of the chunk music file
*/
void AudioController::playChunk(const char* file)
{
	Mix_Chunk* chunk = loadChunks(file);
	int playTime = 1; //once
	Mix_PlayChannel(-1, chunk, playTime);
}

/*
* Plays a background music file
* @param file The path of the background music file
*/
void AudioController::playBackgroundMusic(const char* file)
{
	Mix_Music* music = loadBackground(file);
	int playTime = -1; //infinite
	Mix_PlayMusic(music, playTime);
}

/*
* Stops the background music entirely
*/
void AudioController::stopBackgroundSound()
{
	if (Mix_PlayingMusic() != 0)
		Mix_HaltMusic();
}

/*
* Pauses a background music file
*/
void AudioController::pauseBackgroundSound()
{
	if (Mix_PausedMusic() != 1)
		Mix_PauseMusic();
}

/*
* Resumes a paused background music file
*/
void AudioController::resumeBackgroundSound()
{
	if (Mix_PausedMusic() == 1)
		Mix_ResumeMusic();
}

/*
* Destructor
*/
AudioController::~AudioController()
{
	//Quit SDL_mixer
	Mix_CloseAudio();
}
