#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include "Console.h"
#include "StateManager.h"
#include "AudioController.h"
#include "Window.h"
#include "IState.h"

enum class GameState { PLAY, EXIT };

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	void Add(IState* state);
	void Run();

private:
	IState* _currentState;

	void Update();
	void Render() const;
};

