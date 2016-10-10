#pragma once

#include <SDL/SDL.h>

class StateManager
{
public:
	StateManager();
	~StateManager();

	void Render(SDL_Renderer *renderer);
	void Update();
};

