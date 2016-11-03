#pragma once

#include <SDL/SDL.h>

class IState
{
public:
	virtual ~IState() {}

	IState(IState const &) = delete;
	IState & operator=(IState const &) = delete;

	virtual void OnInitialize() = 0;
	virtual void OnRender() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnEvent(SDL_Event* event) = 0;
	virtual void OnCleanUp() = 0;

protected:
	IState() = default;
};
