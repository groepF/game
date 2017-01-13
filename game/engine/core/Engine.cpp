#include "Engine.h"
#include "../input/Keyboard.h"
#include <Windows.h>

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

	const auto FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;

	Uint32 frameStart, frameTime;

	SDL_Event sdlEvent;

	while (running)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			/*case SDL_KEYDOWN:
				switch (sdlEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				default:
					break;
				}
				break;*/

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

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(static_cast<int>(DELAY_TIME - frameTime));
		}
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

void Engine::playMusic(std::string key)
{
	window->playMusic(key);
}

void Engine::stopMusic()
{
	window->stopMusic();
}

std::vector<std::string> Engine::getFilesIn(const std::string path) const
{
	auto location = SDL_GetBasePath() + path;

	std::vector<std::string> names;
	auto search_path = location + "/*.*";
	WIN32_FIND_DATA fd;
	auto hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(location + "/" + fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}

	return names;
}

void Engine::stateUpdated()
{
	currentState->onCreate();
}
