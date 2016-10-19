#include "Game.h"

Game::Game(const char* title, int width, int height)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_SetRenderDrawBlendMode(Window::GetRenderer(), SDL_BLENDMODE_BLEND);

	if (!Window::IsInitialised()) {
		Window::SetMode(width, height, false, title);
	}

	if (_currentState != nullptr)
	{
		_currentState->OnInitialize();
	}
}

Game::~Game() 
{
	Window::OnCleanUp();
	SDL_Quit();
}

void Game::Run()
{
	while (_currentState != nullptr)
	{
		Update();
		Render();
	}
	SDL_Quit();
}

void Game::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_currentState = nullptr;
			break;
		default: 
			break;
		}
		if (_currentState != nullptr)
		{
			_currentState->OnEvent(&event);
		}
	}
	if (_currentState != nullptr)
	{
		_currentState->OnUpdate();
	}
}

void Game::Render()
{
	SDL_RenderClear(Window::GetRenderer());
	if (_currentState != nullptr)
	{
		_currentState->OnRender();
	}
	SDL_RenderPresent(Window::GetRenderer());
}

void Game::Add(IState* state)
{
	_currentState = state;
}