#include "Keyboard.h"

Keyboard::Keyboard()
{
	keyboardState = SDL_GetKeyboardState(nullptr);
}

Keyboard::~Keyboard()
{ }

bool Keyboard::isKeydown(Keycode key) const
{
	return keyboardState[key];
}