#include "Window.h"

Window::Window(char* title)
{
	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	// Create the window.
	_window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_OPENGL);
	// Set the state to play.
	_state = WindowState::PLAY;
	// Start up the run method.
	run();
}

Window::~Window() {}

void Window::run()
{
	while (_state != WindowState::EXIT)
	{
		tick();
		render();
	}
	SDL_Quit();
}

void Window::tick() 
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_state = WindowState::EXIT;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				_state = WindowState::EXIT;
				break;
			}
			break;
		}
	}
}

void Window::render()
{
}