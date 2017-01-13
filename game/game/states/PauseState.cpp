#include "PauseState.h"
#include "../../engine/util/Config.h"
#include "../../engine/widgets/Button.h"
#include "MenuState.h"
#include "GameSelectionState.h"

PauseState::PauseState(StateContext* context, Game* game) : State(context)
{
	this->game = game;
	this->game->begin();
}


PauseState::~PauseState()
{
}

void PauseState::onCreate()
{
	Log::debug("OnCreate PauseState");

	game->pauseGame();
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);

	int buttonWidth = 300;
	int buttonHeight = 50;

	int width = Config::getInt("width", 800);
	int height = Config::getInt("height", 600);

	int centerX = (width / 2) - (buttonWidth / 2);
	int centerY = (height / 2) - (buttonHeight / 2);
	int y = centerY - 120;

	this->addWidget(new Button("continue", centerX, y, buttonWidth, buttonHeight, "Continue", this));
	y += 60;
	this->addWidget(new Button("newgame", centerX, y, buttonWidth, buttonHeight, "New Game", this));
	y += 60;
	this->addWidget(new Button("quitgame", centerX, y, buttonWidth, buttonHeight, "Quit Game", this));


	this->logo = new Sprite("foxtrot_menu", 0, 0, 427, 93);

	this->context->playMusic("menu");
}

void PauseState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	screen->render(logo,
		(screen->getWidth() / 2) - (logo->getWidth() / 2),
		40);
}

void PauseState::onUpdate(Keyboard* keyboard)
{
}

bool PauseState::onClick(Button* button)
{
	std::string text = button->getText();

	if (text == "Continue")
	{
		//context->setState(new GameSelectionState(context));
		game->restartGame();
		context->setState(new GameState(context, game));
	}
	else if (text == "New Game")
	{
		context->setState(new GameSelectionState(context));
	}
	else if(text == "Quit Game")
	{
		context->setState(new MenuState(context));
	}
	return false;
}

void PauseState::onDestroy()
{
	this->context->stopMusic();
}
