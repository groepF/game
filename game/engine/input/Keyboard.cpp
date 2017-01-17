#include "Keyboard.h"
#include "algorithm"

Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

bool Keyboard::isKeyPressed(SDL_Scancode key)
{
	if (std::find(singlePressKeys.begin(), singlePressKeys.end(), key) != singlePressKeys.end())
	{
		singlePressKeys.erase(std::remove(singlePressKeys.begin(), singlePressKeys.end(), key), singlePressKeys.end());

		return true;
	}
	return false;
}

bool Keyboard::isKeyHeld(SDL_Scancode key) const
{
	return std::find(singlePressKeys.begin(), singlePressKeys.end(), key) != singlePressKeys.end();
}

void Keyboard::keyPressed(SDL_Scancode key)
{
	if (!isKeyHeld(key))
	{
		heldKeys.push_back(key);
		singlePressKeys.push_back(key);
	}
}

void Keyboard::keyReleased(SDL_Scancode key)
{
	singlePressKeys.erase(std::remove(singlePressKeys.begin(), singlePressKeys.end(), key), singlePressKeys.end());
	heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), key), heldKeys.end());
}
