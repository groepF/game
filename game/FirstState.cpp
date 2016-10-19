#include "FirstState.h"
#include "Console.h"

FirstState::FirstState() {}
FirstState::~FirstState() {}

void FirstState::OnInitialize() {}
void FirstState::OnRender() {}
void FirstState::OnUpdate() {}
void FirstState::OnCleanUp() {}

void FirstState::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_0:
			Console::Println("You pressed the 0 key.");
			break;
		default: 
			break;
		}
	}
}