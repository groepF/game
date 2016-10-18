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

	OnInitialize();
	
	// Set the state to play.
	m_State = GameState::PLAY;
	// Start up the run method.
	Run();
}

Game::~Game() 
{
	Window::OnCleanUp();
	OnCleanUp();
	SDL_Quit();
}

void Game::Run()
{
	Console::Println("Starting the Run method");

	while (m_State != GameState::EXIT)
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
			m_State = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_State = GameState::EXIT;
				break;
			}
			break;
		}
		OnEvent(&event);
	}

	m_StateManager->Update();
	OnUpdate();
}

void Game::Render()
{
	SDL_RenderClear(Window::GetRenderer());

	m_StateManager->Render(Window::GetRenderer());
	OnRender();

	SDL_RenderPresent(Window::GetRenderer());
}