#include "Engine.h"

Engine::Engine(const std::string config) : running(true)
{
	try
	{
		Config::load(config);

		SDL::start();

		auto width = Config::getInt("width", 640);
		auto height = Config::getInt("height", 480);
		auto title = Config::getString("title", "Default window title");

		window = new Window(width, height, title);
		window->setBackgroundColor(Color("white"));
	}
	catch (...)
	{
		Log::error("Exception caught! Quitting...");
		return;
	}
}

Engine::~Engine()
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
}

void Engine::start()
{
	auto delta = 0.0f;
	auto thisTime = 0;
	auto lastTime = 0;

	SDL_Event sdlEvent;
	Screen screen{ window };

	while (running)
	{
		thisTime = SDL_GetTicks();
		delta = static_cast<float>(thisTime - lastTime) / 1000;
		lastTime = thisTime;

		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}
		}
		//Game update, render loop	
		update(delta);
		render(&screen);

		SDL_Delay(1);
	}

	SDL::stop();
}

void Engine::render(Screen *screen) const
{
	window->clear();

	if (currentState != nullptr)
	{
		currentState->onRender(screen);
	}

	window->refresh();
}

void Engine::update(float delta)
{
	Event event{ delta, window };
	if (currentState != nullptr)
	{
		currentState->onUpdate(&event);
	}
}

void Engine::addSpritesheet(std::string key, std::string filename) const
{
	window->addTexture(key, filename);
}

void Engine::addMusic(std::string key, std::string filename) const
{
	window->addMusic(key, filename);
}

void Engine::stateUpdated()
{
	Event event{ 0, window };
	currentState->onCreate(&event);
}
