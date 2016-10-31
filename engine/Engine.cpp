#include "Engine.h"

Engine::Engine(const std::string config)
{
	this->config = config;
}

Engine::~Engine() {}

void Engine::run() const
{
	try
	{
		Config::load(config);

		SDL::initialize();

		auto width = Config::getInt("width", 640);
		auto height = Config::getInt("height", 480);
		auto title = Config::getString("title", "Default window title");

		Window window(width, height, title);
		window.setBackgroundColor(Color("white"));

		// Todo: Add the state manager with rendering into the game.
		// Todo: Add user input to the beautiful window.
		// Todo: Remove the lines below.
		// Todo: Good luck.
		std::string input = "";
		getline(std::cin, input);

		SDL::exit();
	}
	catch (...)
	{
		Log::error("Exception caught! Quitting...");
		return;
	}
}
