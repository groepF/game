#include "Engine.h"
#include "../input/Keyboard.h"

Engine::Engine(const std::string config) : running(true)
{
	try
	{
		Config::load(config);

		SDL::start();

		auto width = Config::getInt("width", 640);
		auto height = Config::getInt("height", 480);
		auto title = Config::getString("title", "Default window title");
		auto fullscreen = Config::getBool("fullscreen", false);

		mouse = new Mouse();

		window = new Window(width, height, fullscreen, title);
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
	
	if (mouse != nullptr)
	{
		delete mouse;
		mouse = nullptr;
	}
}

void Engine::start()
{
	auto delta = 0.0f;
	auto thisTime = 0;
	auto lastTime = 0;

	SDL_Event sdlEvent;

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
			case SDL_KEYDOWN:
				switch (sdlEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				default:
					break;
				}
				break;
			case SDL_MOUSEMOTION:
				mouse->setPosition(sdlEvent.motion.x, sdlEvent.motion.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(sdlEvent.button.button == SDL_BUTTON_LEFT)
				{
					mouse->setLeftPressed(true);
					mouse->setLeftPressPosition(sdlEvent.button.x, sdlEvent.button.y);
				}
				else if(sdlEvent.button.button == SDL_BUTTON_RIGHT)
				{
					mouse->setRightPressed(true);
					mouse->setRightPressPosition(sdlEvent.button.x, sdlEvent.button.y);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (sdlEvent.button.button == SDL_BUTTON_LEFT)
				{
					mouse->setLeftPressed(false);
					mouse->setLeftReleasePosition(sdlEvent.button.x, sdlEvent.button.y);
				}
				else if (sdlEvent.button.button == SDL_BUTTON_RIGHT)
				{
					mouse->setRightPressed(false);
					mouse->setRightReleasePosition(sdlEvent.button.x, sdlEvent.button.y);
				}
				break;
			default:
				break;
			}
		}
		update(delta);
		render(window);

		SDL_Delay(1);
	}

	SDL::stop();
}

void Engine::render(Screen *screen) const
{
	window->clear();
	Keyboard keyboard;

	if (currentState != nullptr)
	{
		currentState->onRender(screen);
		currentState->renderWidgets(screen, mouse, &keyboard);
	}

	window->refresh();
}

void Engine::update(float delta)
{
	Keyboard keyboard;
	if (currentState != nullptr)
	{
		currentState->onUpdate(&keyboard);
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
	currentState->onCreate();
}
