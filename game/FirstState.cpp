#include "FirstState.h"
#include "Console.h"
#include <chrono>
#include <thread>
#include "TextureManager.h"

FirstState::FirstState() {}
FirstState::~FirstState()
{
}

void FirstState::OnInitialize()
{
	audioConstoller.playSound("../game/sound/game_music.wav", true);
	TheTextureManager::Instance()->load("speler.png", "player", Window::GetRenderer());
	TheTextureManager::Instance()->load("speler_small.png", "player_small", Window::GetRenderer());
}

void FirstState::OnRender() {
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
		case SDLK_0:
			Console::Println("You pressed the 0 key.");
		case SDLK_LEFT:
			goingLeft = true;
			if (x - 2 <= 0)
			{
				audioConstoller.playSound("../game/sound/slash.wav", false);
				x = 0;
				break;
			}
			x -= 2;
			break;
		case SDLK_RIGHT:
			goingLeft = false;
			if (x + 2 >= 600 - 60)
			{
				audioConstoller.playSound("../game/sound/slash.wav", false);
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
