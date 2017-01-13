#include "AIStateFactory.h"
#include "AIBallState.h"


AIStateFactory::AIStateFactory()
{

	states.emplace("BallState", [](StateContext* context)->State* { return new AIBallState(context); });


}


AIStateFactory::~AIStateFactory()
{
}

State* AIStateFactory::getState(std::string state, StateContext* context)
{

	auto s = states.find(state);
	if(s != states.end())
	{
		auto func = s->second(context);
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
