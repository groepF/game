#pragma once

#include <string>
#include <iostream>

#include <SDL/SDL.h>


class Window
{
public:
	static SDL_Window* GetWindow();
	static SDL_Renderer* GetRenderer();
	static int GetWidth();
	static int GetHeight();

	static const std::string& GetTitle();

	static bool SetMode(int width, int height, bool fullScreen, std::string title = "Super Awesome Engine");
	static void SetWidth(const int& w);
	static void SetHeight(const int& h);

	static void SetInterpolation(const float& value);
	static float GetInterpolation();

	static void SetBackgroundColor(const SDL_Color& color);
	static SDL_Color GetBackgroundColor();

	static bool IsInitialised();
	static bool IsFullscreen();

	static void OnCleanUp();

private:
	Window();
	~Window();
	static SDL_Window* _window;
	static SDL_Renderer* _renderer;
	static std::string _title;
	static int _width, _height;
	static bool _fullScreen;
	static SDL_Color _backgroundColor;

	static bool Initialize();
};