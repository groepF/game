#include "Window.h"

Window::Window(unsigned width, unsigned height, std::string title) :
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	originalWidth(width),
	originalHeight(height),
	title(title)
{
	this->resize(title, width, height);

	if (!(this->window) || !(this->renderer) || !(this->surface))
	{
		Log::error("Window(): Couldn't create Window");
		throw "Window() Fail";
	}

	this->clear();

	this->refresh();
}

Window::~Window()
{
	this->destroy();
}

void Window::resize(std::string title, unsigned int width, unsigned int height)
{
	this->destroy();

	SDL_CreateWindowAndRenderer(width, height, 0, &(this->window), &(this->renderer));

	if (!(this->window) || !(this->renderer))
	{
		Log::error("Window::resize: Couldn't create SDL_Window or SDL_Renderer");
		return;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(this->renderer, width, height);

	this->setTitle(title);

	this->surface = SDL_GetWindowSurface(this->window);
	if (!(this->surface))
	{
		return;
	}

	this->width = width;
	this->height = height;
}

void Window::destroy()
{
	if (this->renderer)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}

	if (this->window)
	{
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
}

void Window::minimize() const
{
	SDL_MinimizeWindow(this->window);
}

void Window::maximize() const
{
	SDL_MaximizeWindow(this->window);
}

void Window::restore() const
{
	SDL_RestoreWindow(this->window);
}

void Window::fill(Color color) const
{
	SDL_SetRenderDrawColor(this->renderer,
		color.r(),
		color.g(),
		color.b(),
		color.a());

	SDL_RenderClear(this->renderer);
}

void Window::setTitle(std::string title) const
{
	if (this->window)
	{
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}

void Window::clear() const
{
	this->fill(this->background);
}

void Window::refresh() const
{
	SDL_RenderPresent(this->renderer);
}

void Window::setBackgroundColor(Color color)
{
	background = color;
}
