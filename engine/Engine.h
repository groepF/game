#pragma once

#include <string>
#include "Log.h"
#include "SDL.h"
#include "Config.h"
#include "Window.h"

class Engine
{
public:
	Engine(const std::string config);
	~Engine();

	void run() const;

private:
	std::string config;
};
