#pragma once

#include <SDL/SDL.h>
<<<<<<< HEAD
#include <iostream>
#include "Console.h"
#include "StateManager.h"
#include "AudioController.h"

enum class GameState { PLAY, EXIT };
=======
#include "Window.h"
#include "IState.h"
>>>>>>> develop

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

