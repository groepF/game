#include "Game.h"

Game::Game(const char* title, int width, int height)
{
	
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// Create the window.
		m_Window = SDL_CreateWindow(title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_OPENGL);

		if (m_Window != 0)
			Console::Println("Initialized the SDL_Window");
		{
			m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

			if (m_Renderer != 0)
			{
				Console::Println("Initialized the SDL_Renderer");
				SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			}
		}
	}
	
	// Set the state to play.
	m_State = GameState::PLAY;
	// Start up the run method.
	Run();
}

Game::~Game() 
{
	Console::Println("Destroying the SDL_Window");
	SDL_DestroyWindow(m_Window);
	Console::Println("Destroying the SDL_Renderer");
	SDL_DestroyRenderer(m_Renderer);
	Console::Println("SDL_Quit");
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
	}

	m_StateManager->Update();
}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);

	m_StateManager->Render(m_Renderer);

	SDL_RenderPresent(m_Renderer);
}