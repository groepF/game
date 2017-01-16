#pragma once

#include <SDL/SDL.h>
#include <vector>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	
	bool isKeyPressed(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key) const;
	void keyPressed(SDL_Scancode scancode);
	void keyReleased(SDL_Scancode scancode);
private:
	std::vector<SDL_Scancode> singlePressKeys;
	std::vector<SDL_Scancode> heldKeys;
};