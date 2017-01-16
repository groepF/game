#include "AIStateFactory.h"
#include "AIBallState.h"
#include "../../../engine/location/Graph.h"


AIStateFactory::AIStateFactory()
{

	states.emplace("BallState", [](StateContext* context, Game* game)->State* { return new AIBallState(context, game); });


}


AIStateFactory::~AIStateFactory()
{
}

State* AIStateFactory::getState(std::string state, StateContext* context, Game* game)
{

	auto s = states.find(state);
	if(s != states.end())
	{
		auto func = s->second(context, game);
		return func;
	}

	return nullptr;


}


AIStateFactory* AIStateFactory::getInstance()
{
	static AIStateFactory* factory;
	if(factory == nullptr)
	{
		factory = new AIStateFactory();
	}
	return factory;
}
