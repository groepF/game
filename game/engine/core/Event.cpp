#include "Event.h"
#include "../graphics/Window.h"

Event::Event(float delta, Window* window) : delta(delta), window(window), nextState(nullptr), keyboardState(nullptr)
{
	keyboardState = SDL_GetKeyboardState(nullptr);
}

Event::~Event()
{ }

float Event::getDelta() const
{
	return delta;
}

bool Event::isKeydown(Keycode key) const
{
	return keyboardState[key];
}

State* Event::getNextState() const
{
	return nextState;
}

void Event::playMusic(std::string music) const
{
	if (window != nullptr)
	{
		window->playMusic(music);
	}
}

void Event::stopMusic() const
{
	if (window != nullptr)
	{
		window->stopMusic();
	}
}