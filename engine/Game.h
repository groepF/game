#pragma once

#include <SDL/SDL.h>
#include "Window.h"
#include "IState.h"

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
	void Render();
};

