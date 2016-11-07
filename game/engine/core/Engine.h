#pragma once

#include <string>
#include "State.h"
#include "../core/Event.h"
#include "../util/Log.h"
#include "../util/Config.h"
#include "../util/SDL.h"
#include "../util/Color.h"
#include "../graphics/Window.h"
#include "../graphics/Screen.h"

class Engine
{
public:
	Engine(const std::string config);
	~Engine();

	void start();
	void addSpritesheet(std::string key, std::string filename) const;
	void addMusic(std::string key, std::string filename) const;
	void setState(State* state);
private:
	bool running;
	State* currentState;
	Window* window;
	void update(float delta);
	void render(Screen *screen) const;
};