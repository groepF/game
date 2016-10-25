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

	void playSound(const char* file, bool backgroundMusic);
	void playChunk(const char* file);
	void playBackgroundMusic(const char* file);

	void stopBackgroundSound();
	void pauseBackgroundSound();
	void resumeBackgroundSound();

	~AudioController();
};