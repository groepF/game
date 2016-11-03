#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <vector>

class AudioController
{
public:
	AudioController();

	void playSound(const char* file, bool backgroundMusic);

	void stopBackgroundSound();
	void pauseBackgroundSound();
	void resumeBackgroundSound();
	~AudioController();

private:
	bool initSound();

	void playChunk(const char* file);
	void playBackgroundMusic(const char* file);

	Mix_Music* loadBackground(const char* file);
	Mix_Chunk* loadChunks(const char* file);
};
