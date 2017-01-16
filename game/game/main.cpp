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
	engine.addSpritesheet("players", "res/images/player.png");
	engine.addSpritesheet("menu_background", "res/images/back_blurred.png");
	engine.addSpritesheet("foxtrot_menu", "res/images/foxtrot_menu.png");
	engine.addSpritesheet("button_hovered", "res/images/button_hovered.png");
	engine.addSpritesheet("button_pressed", "res/images/button_pressed.png");
	engine.addSpritesheet("button_normal", "res/images/button_default.png");
	engine.addSpritesheet("credits", "res/images/credits.png");
	engine.addSpritesheet("achievements", "res/images/achievements.png");
	engine.addSpritesheet("help", "res/images/help.png");
	engine.addSpritesheet("pause_background", "res/images/pauseback.png");
	engine.addSpritesheet("explosion_ball", "res/images/explosion.png");
	engine.addSpritesheet("toilet", "res/images/wc_pot.png");

	// Advertisements.
	auto files = engine.getFilesIn("../game/res/images/ads");

	for (auto index = 0; index < files.size(); index++)
	{
		engine.addSpritesheet("ad_" + std::to_string(index + 1), files[index]);
	}

	engine.addMusic("background", "res/sounds/music.wav");
	engine.addMusic("menu", "res/sounds/menu.mp3");

	auto debug = Config::getBool("debug", false);

	Highscore::load();

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
