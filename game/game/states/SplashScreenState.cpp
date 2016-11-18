#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(StateContext* context) : State(context), counter(0), hasReached(false), sprite(nullptr)
{ }

void SplashScreenState::onCreate()
{
	Log::debug("OnCreate SplashScreenState");
	sprite = new Sprite("splashscreen", 0, 0, 518, 116);
}

void SplashScreenState::onRender(Screen *screen)
{
	screen->render(sprite,
		(screen->getWidth() / 2) - (sprite->getWidth() / 2),
		(screen->getHeight() / 2) - (sprite->getHeight() / 2),
		0,
		counter);
}

void SplashScreenState::onUpdate(Keyboard *keyboard)
{
	if (counter >= 255)
	{
		hasReached = true;
	}
	if (hasReached)
	{
		counter -= 1;
	}
	else
	{
		counter += 1;
	}
	if (counter <= 0)
	{
		context->setState(new GameState(context));
	}
}

void SplashScreenState::onDestroy()
{
	Log::debug("OnDestroy SplashScreenState");
	delete sprite;
	sprite = nullptr;
}