#include "MenuState.h"
#include "../../engine/widgets/Button.h"
#include "../../engine/util/Config.h"
#include "GameState.h"
#include "GameSelectionState.h"
#include "CreditsState.h"
#include "AchievementsState.h"
#include "HelpState.h"
#include "../../engine/core/StateContext.h"

MenuState::MenuState(StateContext* context): State(context), background(nullptr), logo(nullptr)
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

	if (ad != nullptr)
	{
		delete ad;
		ad = nullptr;
	}
}

void MenuState::onCreate()
{
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);

	this->chooseRandomAd();

	int buttonWidth = 300;
	int buttonHeight = 50;

	int width = Config::getInt("width", 800);
	int height = Config::getInt("height", 600);

	int centerX = (width / 2) - (buttonWidth / 2);
	int centerY = (height / 2) - (buttonHeight / 2);
	int y = centerY - 120;

	this->addWidget(new Button("play", centerX, y, buttonWidth, buttonHeight, "Play", this));

	y += 60;

	this->addWidget(new Button("credits", centerX, y, buttonWidth, buttonHeight, "Credits", this));

	y += 60;

	this->addWidget(new Button("achievements", centerX, y, buttonWidth, buttonHeight, "Achievements", this));

	y += 60;

	this->addWidget(new Button("help", centerX, y, buttonWidth, buttonHeight, "Help", this));

	y += 60;

	this->addWidget(new Button("quit", centerX, y, buttonWidth, buttonHeight, "Quit Game", this));

	this->logo = new Sprite("foxtrot_menu", 0, 0, 427, 93);

	this->context->playMusic("menu");
}

void MenuState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	screen->render(ad, (screen->getWidth() / 2) - (ad->getWidth() / 2), screen->getHeight() - ad->getHeight());
	screen->render(logo,
	               (screen->getWidth() / 2) - (logo->getWidth() / 2),
	               40);
}

void MenuState::onUpdate(Keyboard* keyboard)
{
}

void MenuState::onDestroy()
{
}

bool MenuState::onClick(Widget* button)
{
	std::string text = button->getId();

	if (text == "play")
	{
		context->setState(new GameSelectionState(context));
	}
	else if (text == "achievements")
	{
		context->setState(new AchievementsState(context));
	}
	else if (text == "credits")
	{
		context->setState(new CreditsState(context));
	}
	else if (text == "help")
	{
		context->setState(new HelpState(context));
	}
	else if (text == "quit")
	{
		exit(0);
	}
	return false;
}

void MenuState::chooseRandomAd()
{
	auto ads = this->context->getFilesIn("../game/res/images/ads");
	auto random = Math::random(1, ads.size());

	ad = new Sprite("ad_" + std::to_string(random), 0, 0, 400, 130);
}
