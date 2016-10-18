#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include "Console.h"
#include "StateManager.h"
#include "AudioController.h"

enum class GameState { PLAY, EXIT };

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	AudioController getAudioController();

private:
	SDL_Window *m_Window;
	SDL_Renderer *m_Renderer;

	StateManager *m_StateManager;
	GameState m_State;

	AudioController audio;

	void Run();
	void Update();
	void Render();
};

