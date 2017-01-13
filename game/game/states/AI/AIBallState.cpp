#include "AIBallState.h"
#include <iostream>


AIBallState::AIBallState(StateContext* context) : State(context)
{

}


AIBallState::~AIBallState()
{
}

void AIBallState::onCreate()
{
}

void AIBallState::onRender(Screen* screen)
{
}

void AIBallState::onUpdate(Keyboard* keyboard)
{

	std::cout << "weh" << std::endl;

}

void AIBallState::onDestroy()
{
}
