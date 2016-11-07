#include "../engine/core/Engine.h"
#include "states/SplashScreenState.h"

int main(int argc, char* argv[])
{
	Engine engine{ "config.ini" };

	engine.addSpritesheet("splashscreen", "res/images/splashscreen.png");
	engine.addSpritesheet("spritesheet", "res/images/spritesheet.png");

	engine.addMusic("background", "res/sounds/music.wav");

	engine.setState(new SplashScreenState());

	engine.start();

	return 0;
}