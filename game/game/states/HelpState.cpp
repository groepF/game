#include "HelpState.h"
#include "../../engine/widgets/Button.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"
#include "../../engine/widgets/Label.h"
#include "../../engine/util/Config.h"

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

	
	std::vector<std::string> labels;
	labels.push_back("W key:Jump");
	labels.push_back("A key:Walk left");
	labels.push_back("D key:Walk right");
	labels.push_back("CTRL key:Pick up the ball");
	labels.push_back("Left arrow:Throw ball in the left direction");
	labels.push_back("Right arrow:Throw ball in the right direction");

	for (auto index = 0; index < labels.size(); index++)
	{
		auto strings = String::split(labels.at(index), ':');
		this->addWidget(new Label(400, 200 + ((index + 2) * 30), 200, 80, strings.at(0) + ":", Color{ "cyan" }, 2));
		this->addWidget(new Label(625, 200 + ((index + 2) * 30), 200, 80, strings.at(1), Color{ "white" }, 0));
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

void HelpState::onClick(Button* button)
{
	if (button->getText() == "<")
	{
		context->setState(new MenuState(context));
	}
}
