#pragma once

#include "IState.h"
#include "Game.h"

class FirstState : public IState
{
public:
	FirstState();
	virtual ~FirstState();

	void OnInitialize() final;
	void OnRender() final;
	void OnUpdate() final;
	void OnEvent(SDL_Event* event) final;
	void playAudioDemo() const;
	void OnCleanUp() final;

private:
	AudioController audioConstoller;
};