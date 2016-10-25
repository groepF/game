#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class AudioController
{
public:
	AudioController();
	bool initSound();
	Mix_Music* loadBackground(const char* file);
	Mix_Chunk* loadChunks(const char* file);
	void cleanUp();

	void playSound(const char* file, int loop);

	void stopBackgroundSound();
	void pauseBackgroundSound();
	void resumeBackgroundSound();

	~AudioController();
};
