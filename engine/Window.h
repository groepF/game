#pragma once

#include <SDL/SDL.h>

enum class WindowState { PLAY, EXIT };

class Window
{
public:
	Window(char* title);
	~Window();

private:
	SDL_Window *_window;
	WindowState _state;
	void run();
	void tick();
	void render();
};

