#include "FirstState.h"
#include "Console.h"
#include "TextureManager.h"

FirstState::FirstState() {}
FirstState::~FirstState() {}

void FirstState::OnInitialize()
{
	TheTextureManager::Instance()->load("speler.png", "player", Window::GetRenderer());
	TheTextureManager::Instance()->load("speler_small.png", "player_small", Window::GetRenderer());
}

void FirstState::OnRender()
{
	TheTextureManager::Instance()->render("player_small", x, 280, 60, 122, Window::GetRenderer(), goingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void FirstState::OnUpdate() {}
void FirstState::OnCleanUp() {}

void FirstState::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_LEFT:
			goingLeft = true;
			if(x - 2 <= 0)
			{
				x = 0;
				break;
			}
			x -= 2;
			break;
		case SDLK_RIGHT:
			goingLeft = false;
			if(x + 2 >= 600 - 60)
			{
				x = 600 - 60;
				break;
			}
			x += 2;
			break;
		default: 
			break;
		}
	}
}