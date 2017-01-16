#include "HelpState.h"
#include "../../engine/widgets/Button.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"
#include "../../engine/widgets/Label.h"
#include "../../engine/util/Config.h"

HelpState::HelpState(StateContext* context) : State(context)
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


	std::vector<std::string> labels;
	labels.push_back("PLAYER 1");
	labels.push_back("W:Jump");
	labels.push_back("A:Walk left");
	labels.push_back("D:Walk right");
	labels.push_back("E:Pick up the ball");
	labels.push_back("E:Drop the ball");
	labels.push_back("E:Slap the ball out of the enemy's hands");
	labels.push_back("Left Shift: Throw the ball");
	labels.push_back("");
	labels.push_back("PLAYER 2");
	labels.push_back("Up:Jump");
	labels.push_back("Left: Walk left");
	labels.push_back("Right: Walk right");
	labels.push_back("Right Ctrl:Pick up the ball");
	labels.push_back("Right Ctrl:Drop the ball");
	labels.push_back("Right Ctrl:Slap the ball out of the enemy's hands");
	labels.push_back("Right Shift: Throw the ball");

	for (auto index = 0; index < labels.size(); index++)
	{
		auto strings = String::split(labels.at(index), ':');
		if (strings.size() > 0)
		{
			this->addWidget(new Label(400, 125 + ((index + 2) * 30), 200, 80, strings.at(0) + ":", Color{ "cyan" }, 2));
		}if (strings.size() > 1)
		{
			this->addWidget(new Label(625, 125 + ((index + 2) * 30), 200, 80, strings.at(1), Color{ "white" }, 0));
		}
	}
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

bool HelpState::onClick(Button* button)
{
	if (button->getText() == "<")
	{
		context->setState(new MenuState(context));
	}
	return false;
}
