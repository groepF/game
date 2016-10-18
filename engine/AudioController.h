#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class AudioController
{
public:
	//The music that will be played
	Mix_Music *music = NULL;
	AudioController();
	bool initSound();
	bool loadFiles(const char* file);
	void cleanUp();

	void playSound(const char* file);
	void stopSound();

	~AudioController();


	

};
