#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include "Window.h"
#include "Console.h"
#include "StateManager.h"

enum class GameState { PLAY, EXIT };

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

private:
	StateManager *m_StateManager;
	GameState m_State;

	void Run();
	void Update();
	void Render();

	virtual void OnInitialize();
	virtual void OnEvent(SDL_Event* event);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanUp();
};

