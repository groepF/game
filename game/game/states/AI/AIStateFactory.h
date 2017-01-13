#pragma once
#include <map>
#include <functional>
#include "../../../engine/core/State.h"

class AIStateFactory
{
public:
	AIStateFactory();
	~AIStateFactory();
	State* getState(std::string, StateContext*);
	static AIStateFactory* getInstance();

private:
	std::map<std::string, std::function<State*(StateContext*)>> states;

};

