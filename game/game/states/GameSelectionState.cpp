#include "GameSelectionState.h"
#include "../../engine/widgets/Button.h"
#include "../../engine/widgets/Label.h"
#include "GameState.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"


class StateContext;

GameSelectionState::GameSelectionState(StateContext* context) : State(context)
{
}


GameSelectionState::~GameSelectionState()
{
	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}
}

/**
* Function gets called when state changes
*/
void GameSelectionState::onCreate()
{
	Log::debug("OnCreate GameSelectionState");

	//Create a new game
	game = new Game();

	//Set the background
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);

	//Width and height from screen
	int width = Config::getInt("width", 800);
	int height = Config::getInt("height", 600);

	//Determine default widget width and height
	int widgetWidth = 300;
	int widgetHeight = 50;
	int smallButtonWidth = 90;
	int smallButtonHeight = 50;

	//Determine center x position
	int centerX = (width / 2) - (widgetWidth / 2);


	//Add game setting labels
	this->addWidget(new Label(300, 200, widgetWidth, widgetHeight, "Time:"));
	this->addWidget(new Label(300, 260, widgetWidth, widgetHeight, "Goals:"));
	this->addWidget(new Label(300, 320, widgetWidth, widgetHeight, "Map:"));
	this->addWidget(new Label(300, 380, widgetWidth, widgetHeight, "Mode:"));

	//Creating buttons and add them to a vector

	//Time
	Button* btn_time1 = new Button("time1", 500, 200, smallButtonWidth, smallButtonHeight, "1:00", this);
	Button* btn_time3 = new Button("time3", 600, 200, smallButtonWidth, smallButtonHeight, "3:00", this);
	Button* btn_time5 = new Button("time5", 700, 200, smallButtonWidth, smallButtonHeight, "5:00", this);
	timeButtons.push_back(btn_time1);
	timeButtons.push_back(btn_time3);
	timeButtons.push_back(btn_time5);

	//Goals
	Button* btn_goals3 = new Button("goals3", 500, 260, smallButtonWidth, smallButtonHeight, "3", this);
	Button* btn_goals5 = new Button("goals5", 600, 260, smallButtonWidth, smallButtonHeight, "5", this);
	Button* btn_goals10 = new Button("goals10", 700, 260, smallButtonWidth, smallButtonHeight, "10", this);
	goalButtons.push_back(btn_goals3);
	goalButtons.push_back(btn_goals5);
	goalButtons.push_back(btn_goals10);

	//Maps
	Button* btn_level1 = new Button("level1", 500, 320, smallButtonWidth, smallButtonHeight, "Lvl 1", this);
	Button* btn_level2 = new Button("level2", 600, 320, smallButtonWidth, smallButtonHeight, "Lvl 2", this);
	Button* btn_level3 = new Button("level3", 700, 320, smallButtonWidth, smallButtonHeight, "Lvl 3", this);
	mapButtons.push_back(btn_level1);
	mapButtons.push_back(btn_level2);
	mapButtons.push_back(btn_level3);

	//Options
	Button* btn_option1 = new Button("option_local", 500, 380, 140, smallButtonHeight, "Local", this);
	Button* btn_option2 = new Button("option_ai", 650, 380, 140, smallButtonHeight, "AI", this);
	optionButtons.push_back(btn_option1);
	optionButtons.push_back(btn_option2);

	//Set defaults
	btn_time3->select();
	btn_goals5->select();
	btn_level1->select();
	btn_option1->select();


	//Add game setting buttons
	//Time
	this->addWidget(btn_time1);
	this->addWidget(btn_time3);
	this->addWidget(btn_time5);

	//Goals
	this->addWidget(btn_goals3);
	this->addWidget(btn_goals5);
	this->addWidget(btn_goals10);

	//Maps
	this->addWidget(btn_level1);
	this->addWidget(btn_level2);
	this->addWidget(btn_level3);

	//Option
	this->addWidget(btn_option1);
	this->addWidget(btn_option2);


	//Add Start and Go Back buttons 
	int y = height - widgetHeight - 200;

	this->addWidget(new Button("start", centerX, y, widgetWidth, widgetHeight, "Start Game", this));
	this->addWidget(new Button("back", centerX, y + 60, widgetWidth, widgetHeight, "Go Back", this));
}

void GameSelectionState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
}

void GameSelectionState::onUpdate(Keyboard* keyboard)
{
}

void GameSelectionState::onDestroy()
{
	Log::debug("OnDestroy GameSelectionState");
}

bool GameSelectionState::onClick(Button* button)
{
	//Settings

	//Time
	if (button->getId() == "time1")
	{
		deselectAll(timeButtons);
		game->setTime(1);
	}
	else if (button->getId() == "time3")
	{
		deselectAll(timeButtons);
		game->setTime(3);
	}
	else if (button->getId() == "time5")
	{
		deselectAll(timeButtons);
		game->setTime(5);
	}

	//Goals
	if (button->getId() == "goals3")
	{
		deselectAll(goalButtons);
		game->setGoals(3);
	}
	else if (button->getId() == "goals5")
	{
		deselectAll(goalButtons);
		game->setGoals(5);
	}
	else if (button->getId() == "goals10")
	{
		deselectAll(goalButtons);
		game->setGoals(10);
	}

	//Map
	if (button->getId() == "level1")
	{
		deselectAll(mapButtons);
		game->setMap(1);
	}
	else if (button->getId() == "level2")
	{
		deselectAll(mapButtons);
		game->setMap(2);
	}
	else if (button->getId() == "level3")
	{
		deselectAll(mapButtons);
		game->setMap(3);
	}

	//Map
	if (button->getId() == "option_local")
	{
		deselectAll(optionButtons);
		game->setAI(false);
	}
	else if (button->getId() == "option_ai")
	{
		deselectAll(optionButtons);
		game->setAI(true);
	}

	button->select();

	//Start and Back button
	if (button->getId() == "start")
	{
		context->setState(new GameState(context, game));
		return false;
	}
	else if (button->getId() == "back")
	{
		context->setState(new MenuState(context));
		return false;
	}

	return true;
}

void GameSelectionState::deselectAll(std::vector<Button*> buttons)
{
	for (Button* button : buttons)
	{
		button->deselect();
	}
}
