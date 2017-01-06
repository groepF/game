#include "../engine/core/Engine.h"
#include "states/SplashScreenState.h"
#include "states/MenuState.h"
#include "../engine/util/Highscore.h"

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
	engine.addSpritesheet("player", "res/images/players.png");
	engine.addSpritesheet("menu_background", "res/images/back_blurred.png");
	engine.addSpritesheet("foxtrot_menu", "res/images/foxtrot_menu.png");
	engine.addSpritesheet("button_hovered", "res/images/button_hovered.png");
	engine.addSpritesheet("button_pressed", "res/images/button_pressed.png");
	engine.addSpritesheet("button_normal", "res/images/button_default.png");
	engine.addSpritesheet("credits", "res/images/credits.png");
	engine.addSpritesheet("achievements", "res/images/achievements.png");
	engine.addSpritesheet("help", "res/images/help.png");

	// Ads
	engine.addSpritesheet("ad_1", "res/images/ads/mcdonalds.png");
	engine.addSpritesheet("ad_2", "res/images/ads/subway.png");
	engine.addSpritesheet("ad_3", "res/images/ads/ah.png");

	engine.addMusic("background", "res/sounds/music.wav");
	engine.addMusic("menu", "res/sounds/menu.mp3");

	auto debug = Config::getBool("debug", false);

	if (debug)
	{
		engine.setState(new MenuState(&engine));
	}
	else
	{
		engine.setState(new SplashScreenState(&engine));
	}

	engine.start();

	return 0;
}
