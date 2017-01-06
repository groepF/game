#include "Window.h"
#include <SDL/SDL_ttf.h>

#define GRAVITY_LEFT 0
#define GRAVITY_CENTER 1
#define GRAVITY_RIGHT 2

Window::Window(unsigned int width, unsigned int height, bool fullscreen, std::string title) :
	window(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	fullscreen(fullscreen),
	title(title),
	font(TTF_OpenFont("engine/res/fonts/comic.ttf", 24))
{
	this->resize(title, width, height);

	if (!(this->window) || !(this->renderer))
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

	if (this->fullscreen)
	{
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	else
	{
		SDL_CreateWindowAndRenderer(width, height, 0, &(this->window), &(this->renderer));
	}


	if (!(this->window) || !(this->renderer))
	{
		Log::error("Window::resize: Couldn't create SDL_Window or SDL_Renderer");
		return;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(this->renderer, width, height);

	this->setTitle(title);

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

	for (const auto &fragment : music)
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

void Window::render(Sprite* sprite, float x, float y, double angle, int alpha, float width, float height) const
{
	if (sprite == nullptr)
	{
		return;
	}

	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;

	if (width == -1 || height == -1)
	{
		destinationRectangle.w = sprite->getWidth();
		destinationRectangle.h = sprite->getHeight();
	}
	else
	{
		destinationRectangle.w = width;
		destinationRectangle.h = height;
	}
	destinationRectangle.x = x;
	destinationRectangle.y = y;

	sourceRectangle.x = sprite->getX();
	sourceRectangle.y = sprite->getY();
	sourceRectangle.w = sprite->getWidth();
	sourceRectangle.h = sprite->getHeight();

	SDL_SetTextureAlphaMod(textures.at(sprite->getIdentifier()), alpha);
	SDL_RenderCopyEx(renderer, textures.at(sprite->getIdentifier()), &sourceRectangle, &destinationRectangle, angle, nullptr, SDL_FLIP_NONE);
}

void Window::renderText(std::string message, Color color, int x, int y, int width, int height, double angle, bool crop, int gravity) const
  
{
	if (font)
	{
		auto surfaceMessage{ TTF_RenderText_Solid(font, message.c_str() , SDL_Color{ color.r(), color.g(), color.b() }) };
		auto Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

		int w = width, h = height;
		if (!crop) {
			SDL_QueryTexture(Message, nullptr, nullptr, &w, &h);
		}

		SDL_Rect Message_rect; //create a rect		
		if (gravity == GRAVITY_CENTER)
		{
			Message_rect.x = x + (width / 2) - (w / 2);  //controls the rect's x coordinate 		
			Message_rect.y = y + (height / 2) - (h / 2); // controls the rect's y coordinte		
		} else if (gravity == GRAVITY_LEFT)
		{
			Message_rect.x = x;  //controls the rect's x coordinate 		
			Message_rect.y = y; // controls the rect's y coordinte		
		} else if (gravity == GRAVITY_RIGHT)
		{
			Message_rect.x = x + width - w;  //controls the rect's x coordinate 		
			Message_rect.y = y; // controls the rect's y 
		}
		Message_rect.w = w; // controls the width of the rect		
		Message_rect.h = h; // controls the height of the rect	

		SDL_RenderCopyEx(renderer, Message, nullptr, &Message_rect, angle, nullptr, SDL_FLIP_NONE); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
		SDL_DestroyTexture(Message);
	}
	else
	{
		Log::error("Font was not correctly loaded. Can't output text on screen.");
	}
}

void Window::renderRect(float x, float y, float width, float height) const
{
	SDL_Rect outlineRect = { x, y, width, height };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &outlineRect);
}

unsigned Window::getWidth() const { return width; }
unsigned Window::getHeight() const { return height; }
