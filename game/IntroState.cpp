#include "IntroState.h"
#include "StateManager.h"

void IntroState::OnStart()
{
	StateManager::GetInstance().TransitionTo("game");
}

void IntroState::OnRender()
{
	
}

void IntroState::OnUpdate()
{
	
}

void IntroState::OnExit()
{
	
}