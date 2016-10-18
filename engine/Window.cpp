#include "Window.h"

SDL_Window* Window::_window = nullptr;
SDL_Renderer* Window::_renderer = nullptr;
std::string Window::_title = "No Title";
int Window::_width = 1280;
int Window::_height = 720;
bool Window::_fullScreen = false;
SDL_Color Window::_backgroundColor = { 128, 128, 128, 255 };

Window::Window() {}
Window::~Window() {}

bool Window::Initialize() {
	if (_window) {
		SDL_DestroyWindow(_window);
	}

	_window = SDL_CreateWindow(_title.c_str(), 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 
		_width, 
		_height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP * _fullScreen);

	if (_window == nullptr) {
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (_renderer) {
		SDL_DestroyRenderer(_renderer);
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (_renderer == nullptr) {
		std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_SetRenderDrawColor(Window::GetRenderer(), _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, 0);

	return true;
}

void ShowError(bool& error) {
	error = true;
	std::cerr << SDL_GetError() << std::endl;
}

const std::string& Window::GetTitle() {
	return _title;
}

bool Window::SetMode(int width, int height, bool fullScreen, std::string title) {
	_width = width;
	_height = height;
	_fullScreen = fullScreen;
	_title = title;

	if (IsInitialised()) {
		bool error = false;

		SDL_SetWindowTitle(_window, _title.c_str());
		SDL_SetWindowSize(_window, _width, _height);

		if (SDL_SetWindowFullscreen(_window, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN * _fullScreen) < 0) {
			ShowError(error);
		}

		//SDL_RenderSetLogicalSize(Window::GetRenderer(), _w, _h);
		return !error;
	}
	else {
		return Initialize();
	}
}

SDL_Window* Window::GetWindow() {
	return _window;
}

SDL_Renderer* Window::GetRenderer() {
	return _renderer;
}

void Window::SetWidth(const int &w) {
	SetMode(w, _height, _fullScreen, _title);
}

void Window::SetHeight(const int &h) {
	SetMode(_width, h, _fullScreen, _title);
}

int Window::GetWidth() {
	return _width;
}

int Window::GetHeight() {
	return _height;
}

bool Window::IsInitialised() {
	return _window != nullptr && _renderer != nullptr;
}

bool Window::IsFullscreen() {
	return _fullScreen;
}

void Window::OnCleanUp() {
	if (_window) {
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
	if (_renderer) {
		SDL_DestroyRenderer(_renderer);
		_renderer = nullptr;
	}
}

void Window::SetBackgroundColor(const SDL_Color& color) {
	_backgroundColor = color;
	SDL_SetRenderDrawColor(Window::GetRenderer(), _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
}

SDL_Color Window::GetBackgroundColor() {
	return _backgroundColor;
}