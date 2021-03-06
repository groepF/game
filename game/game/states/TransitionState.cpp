#include "TransitionState.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"
#include "GameState.h"
#include "../../LevelUnlocker.h"


TransitionState::TransitionState(StateContext* context, Game* game): State(context)
{
	this->previousGame = game;
	LevelUnlocker unlocker;
	//1x winnen: level2 unlocken
	if(game->hasWinner())
	{
		if(game->getTeamAGoals() > game->getTeamBGoals()) // Team A Heeft gewonnen
		{
			//Unlock level 2
			unlocker.unlockLevel2();
		}
	}

	//60% balbezit behaald: level3 unlocken
	if(game->getPlayer()->ballpossession >= 60)
	{
		// Unlock level 3
		unlocker.unlockLevel3();
	}
}


TransitionState::~TransitionState()
{
	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}
	if(previousGame != nullptr)
	{
		delete previousGame;
		previousGame = nullptr;
	}
}

void TransitionState::onCreate()
{
	Log::debug("OnCreate TransitionState");

	//Set the background
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);

	//Determine default widget width and height
	int widgetWidth = 300;
	int widgetHeight = 50;

	//Creating buttons
	Button* btn_rematch		= new Button("rematch", 500, 200, widgetWidth, widgetHeight, "Rematch", this);
	Button* btn_nextmatch	= new Button("nextmatch", 500, 260, widgetWidth, widgetHeight, "Next Match", this);
	Button* btn_menu		= new Button("menu", 500, 320, widgetWidth, widgetHeight, "Menu", this);

	//Add the buttons
	this->addWidget(btn_rematch);
	this->addWidget(btn_nextmatch);
	this->addWidget(btn_menu);
}

void TransitionState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
}

void TransitionState::onUpdate(Keyboard* keyboard)
{
}

void TransitionState::onDestroy()
{
	Log::debug("OnDestroy TransitionState");
}

bool TransitionState::onClick(Widget* button)
{
	//Start and Back button
	if (button->getId() == "rematch")
	{
		Game* game = new Game();
		game->setTime(previousGame->getGameTime());
		game->setGoals(previousGame->getMaxGoals());
		game->setMap(previousGame->getMapId());

		context->setState(new GameState(context, game));
	}
	else if (button->getId() == "nextmatch")
	{
		context->setState(new GameSelectionState(context));
	}
	else if (button->getId() == "menu")
	{
		context->setState(new MenuState(context));
	}

	return false;
}
