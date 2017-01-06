#include "HelpState.h"
#include "../../engine/widgets/Button.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"

HelpState::HelpState(StateContext* context): State(context)
{
}

HelpState::~HelpState()
{
}

void HelpState::onCreate()
{
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);
	this->logo = new Sprite("help", 0, 0, 196, 87);

	this->addWidget(new Button("back", 20, 60, 80, 40, "<", this));
}

void HelpState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	screen->render(logo,
	               (screen->getWidth() / 2) - (logo->getWidth() / 2),
	               40);
}

void HelpState::onUpdate(Keyboard* keyboard)
{
}

void HelpState::onDestroy()
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

void HelpState::onClick(Button* button)
{
	if (button->getText() == "<")
	{
		context->setState(new MenuState(context));
	}
}
