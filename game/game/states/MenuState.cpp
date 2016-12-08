#include "MenuState.h"
#include "../../engine/widgets/Button.h"
#include "../../engine/util/Config.h"
#include "GameState.h"
#include "GameSelectionState.h"

MenuState::MenuState(StateContext* context): State(context)
{
}

MenuState::~MenuState()
{
	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}

	if (logo != nullptr)
	{
		delete logo;
		logo = nullptr;
	}
}

void MenuState::onCreate()
{
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);

	int buttonWidth = 300;
	int buttonHeight = 50;

	int width = Config::getInt("width", 800);
	int height = Config::getInt("height", 600);

	int centerX = (width / 2) - (buttonWidth / 2);
	int centerY = (height / 2) - (buttonHeight / 2);
	int y = centerY - 30;

	this->addWidget(new Button(centerX, y, buttonWidth, buttonHeight, "Play", this));

	y += 60;

	this->addWidget(new Button(centerX, y, buttonWidth, buttonHeight, "Quit Game", this));

	this->logo = new Sprite("foxtrot_menu", 0, 0, 514, 129);
}

void MenuState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	screen->render(logo,
	               (screen->getWidth() / 2) - (logo->getWidth() / 2),
	               30);
}

void MenuState::onUpdate(Keyboard* keyboard)
{
}

void MenuState::onDestroy()
{
}

void MenuState::onClick(Button* button)
{
	std::string text = button->getText();
	if (text == "Play")
	{
		Log::debug("clicked");
		context->setState(new GameSelectionState(context));
	}
	else if (text == "Quit Game")
	{
		exit(0);
	}
}
