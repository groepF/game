#include "AchievementsState.h"
#include "../../engine/widgets/Button.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"


AchievementsState::AchievementsState(StateContext* context): State(context), background(nullptr), logo(nullptr)
{
}

AchievementsState::~AchievementsState()
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

void AchievementsState::onCreate()
{
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);
	this->logo = new Sprite("achievements", 0, 0, 597, 78);

	this->addWidget(new Button("back", 20, 60, 80, 40, "<", this));
}

void AchievementsState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	screen->render(logo,
		(screen->getWidth() / 2) - (logo->getWidth() / 2),
		40);
}

void AchievementsState::onUpdate(Keyboard* keyboard)
{

}

void AchievementsState::onDestroy()
{

}

void AchievementsState::onClick(Button* button)
{
	if (button->getText() == "<")
	{
		context->setState(new MenuState(context));
	}
}
