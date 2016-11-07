#include "Window.h"

Window::Window(unsigned width, unsigned height, std::string title) :
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	viewportX(0.0f),
	viewportY(0.0f),
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
	for (const auto &texture : textures)
	{
		SDL_DestroyTexture(texture.second);
	}
	textures.clear();

	for (const auto &fragment: music)
	{
		Mix_FreeMusic(fragment.second);
	}
	music.clear();

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

void Window::setViewport(float x, float y)
{
	viewportX = x;
	viewportY = y;
}

void Window::addTexture(std::string key, std::string filename)
{
	auto surface = IMG_Load(filename.c_str());
	if (surface == nullptr)
	{
		Log::error("Failed to load image: " + filename);
		return;
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

	auto texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == nullptr)
	{
		Log::error("Failed to create texture from image: " + filename);
		return;
	}
	SDL_FreeSurface(surface);

	if (textures[key] != nullptr)
	{
		SDL_DestroyTexture(textures[key]);
	}
	Log::log("Loaded texture into memory : " + filename);
	textures[key] = texture;
}

void Window::addMusic(std::string key, std::string filename)
{
	auto item = Mix_LoadMUS(filename.c_str());
	if (item == nullptr)
	{
		Log::error("Failed to load music: " + filename);
		return;
	}
	Log::log("Loaded music into memory : " + filename);
	music[key] = item;
}

void Window::playMusic(std::string key)
{
	auto position = music.find(key);
	if (position == music.end()) {
		Log::error("Failed to play music: " + key);
	}
	else {
		auto value = position->second;
		Mix_PlayMusic(value, -1);
	}
}

void Window::stopMusic() const
{
	if (Mix_PlayingMusic() != 0)
	{
		Mix_HaltMusic();
	}
}

void Window::render(Sprite* sprite, float x, float y, double angle, double size, int alpha)
{
	if (sprite == nullptr)
	{
		return;
	}

	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;

	destinationRectangle.w = sprite->getWidth() * size;
	destinationRectangle.h = sprite->getHeight() * size;
	destinationRectangle.x = x - viewportX;
	destinationRectangle.y = y - viewportY;

	sourceRectangle.x = sprite->getX();
	sourceRectangle.y = sprite->getY();
	sourceRectangle.w = sprite->getWidth();
	sourceRectangle.h = sprite->getHeight();

	SDL_SetTextureAlphaMod(textures[sprite->getIdentifier()], alpha);
	SDL_RenderCopyEx(renderer, textures[sprite->getIdentifier()], &sourceRectangle, &destinationRectangle, angle, nullptr, SDL_FLIP_NONE);
}

unsigned Window::getWidth() const { return width; }
unsigned Window::getHeight() const { return height; }