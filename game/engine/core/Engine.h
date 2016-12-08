#pragma once

#include <string>
#include "State.h"
#include "StateContext.h"
#include "../util/Log.h"
#include "../util/Config.h"
#include "../util/SDL.h"
#include "../util/Color.h"
#include "../graphics/Window.h"
#include "../graphics/Screen.h"
#include "../input/Mouse.h"

class Engine : public StateContext
{
public:
	Engine(const std::string config);
	~Engine();

	void start();
	void addSpritesheet(std::string key, std::string filename) const;
	void addMusic(std::string key, std::string filename) const;
protected:
	void stateUpdated() override;
private:
	bool running;
	Window *window;
	Mouse *mouse;
	void update(float delta);
	void render(Screen *screen) const;
};
