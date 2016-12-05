#include "../engine/core/Engine.h"
#include "states/SplashScreenState.h"

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Engine engine{ "config.ini" };

	engine.addSpritesheet("splashscreen", "res/images/splashscreen.png");
	engine.addSpritesheet("spritesheet", "res/images/spritesheet.png");
	engine.addSpritesheet("background", "res/images/back.png");
	engine.addSpritesheet("castle", "res/images/castle.png");
	engine.addSpritesheet("metal", "res/images/metal.png");
	engine.addSpritesheet("color_tiles3", "res/images/team_colors.png");
	engine.addSpritesheet("player", "res/images/Speler1.png");

	engine.addMusic("background", "res/sounds/music.wav");

	auto debug = Config::getBool("debug", false);

	if (debug)
	{
		engine.setState(new GameState(&engine));
	}
	else
	{
		engine.setState(new SplashScreenState(&engine));
	}

	engine.start();

	return 0;
}