#include "GameSelectionState.h"
#include "../../engine/widgets/Button.h"
#include "GameState.h"
#include "MenuState.h"


GameSelectionState::GameSelectionState(StateContext* context) :
	State(context)
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

void GameSelectionState::onCreate()
{
	Log::debug("OnCreate GameSelectionState");

	game = new Game();

	this->background = new Sprite("menu_background", 0, 0, 1300, 720);

	int buttonWidth = 300;
	int buttonHeight = 50;

	int width = Config::getInt("width", 800);
	int height = Config::getInt("height", 600);

	int centerX = (width / 2) - (buttonWidth / 2);
	int centerY = (height / 2) - (buttonHeight / 2);
	int y = centerY - 30;

	this->addWidget(new Button(centerX, y, buttonWidth, buttonHeight, "Start Game", this));
	y += 60;

	this->addWidget(new Button(centerX, y, buttonWidth, buttonHeight, "Go Back", this));
	
}

void GameSelectionState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	/*screen->render(logo,
		(screen->getWidth() / 2) - (logo->getWidth() / 2),
		30);*/
}

void GameSelectionState::onUpdate(Keyboard* keyboard)
{
}

void GameSelectionState::onDestroy()
{
	Log::debug("OnDestroy GameSelectionState");
}

void GameSelectionState::onClick(Button* button)
{
	std::string text = button->getText();
	if (text == "Start Game")
	{
		context->setState(new GameState(context, game));
	} 
	else if(text == "Go Back")
	{
		context->setState(new MenuState(context));
	}
}
