#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class AudioController
{
public:
	AudioController();
	bool initSound();

	void playSound(const char* file, bool backgroundMusic);

	void stopBackgroundSound();
	void pauseBackgroundSound();
	void resumeBackgroundSound();

	~AudioController();

private:
	void playChunk(const char* file);
	void playBackgroundMusic(const char* file);

	Mix_Music* loadBackground(const char* file);
	Mix_Chunk* loadChunks(const char* file);
};
