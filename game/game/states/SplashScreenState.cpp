#include "SplashScreenState.h"

void SplashScreenState::onCreate(Event *event)
{
	Log::debug("OnCreate SplashScreenState");
	counter = 0;
	hasReached = false;
	sprite = new Sprite("splashscreen", 0, 0, 518, 116);
}

void SplashScreenState::onRender(Screen *screen)
{
	screen->render(sprite,
		(screen->getScreenWidth() / 2) - (sprite->getWidth() / 2),
		(screen->getScreenHeight() / 2) - (sprite->getHeight() / 2),
		0,
		1,
		counter);
}

void SplashScreenState::onUpdate(Event *event)
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
		event->transitionTo(new GameState());
	}
}

void SplashScreenState::onDestroy()
{
	Log::debug("OnDestroy SplashScreenState");
	delete sprite;
	sprite = nullptr;
}