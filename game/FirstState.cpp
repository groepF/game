#include "FirstState.h"
#include "Console.h"
#include "TextureManager.h"

FirstState::FirstState() {}
FirstState::~FirstState() {}

void FirstState::OnInitialize()
{
	TheTextureManager::Instance()->load("speler.png", "player", Window::GetRenderer());
}

void FirstState::OnRender()
{
	TheTextureManager::Instance()->render("player", 50, 50, 200, 200, Window::GetRenderer());
}

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