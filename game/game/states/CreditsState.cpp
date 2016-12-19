#include "CreditsState.h"
#include "../../engine/widgets/Button.h"
#include "MenuState.h"
#include "../../engine/core/StateContext.h"

#define TARGET_SIZE 100
#define Y_OFFSET 80
#define TEXT_PADDING 70
#define START_SIZE 1000

CreditsState::CreditsState(StateContext* context): State(context), background(nullptr), logo(nullptr), angle(0), width(0), height(0), currentY(0), targetY(0)
{
}

CreditsState::~CreditsState()
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

void CreditsState::onCreate()
{
	this->background = new Sprite("menu_background", 0, 0, 1300, 720);
	this->logo = new Sprite("credits", 0, 0, 405, 93);
	this->width = START_SIZE;
	this->height = START_SIZE;

	remaining.push_back("Brian");
	remaining.push_back("Ruud");
	remaining.push_back("Laura");
	remaining.push_back("Diede");
	remaining.push_back("Stan");
	remaining.push_back("Bram");

	this->addWidget(new Button("back", 20, 60, 80, 40, "<", this));

	current = remaining[0];
}

void CreditsState::onRender(Screen* screen)
{
	screen->render(background, 0, 0);
	screen->render(logo,
		(screen->getWidth() / 2) - (logo->getWidth() / 2),
		40);

	int x = screen->getWidth() / 2 - width / 2;
	int y = screen->getHeight() / 2 - height / 2 - Y_OFFSET;

	if (width == TARGET_SIZE && height == TARGET_SIZE && targetY == 0)
	{
		targetY = y + ((shown.size() + 1) * TEXT_PADDING);
	}

	if(width == TARGET_SIZE && height == TARGET_SIZE && (y + currentY > targetY || remaining.size() == 1))
	{
		currentY = targetY - y;
		width = START_SIZE;
		height = START_SIZE;
		angle = 0;
		currentY = 0;
		shown.push_back(current);
		remaining.erase(remaining.begin());
		if (remaining.size() > 0) {
			current = remaining[0];
		} 
		else
		{
			current = "";
		}
	}

	screen->renderText(current, Color{ "white" }, x, y + currentY, width, height, angle, true);

	x = screen->getWidth() / 2 - TARGET_SIZE / 2;
	y = screen->getHeight() / 2 - TARGET_SIZE / 2 - Y_OFFSET;
	int counter = shown.size();
	if (remaining.size() == 0) counter--;
	for(auto &name : shown)
	{
		screen->renderText(name, Color{ "white" }, x, y + currentY + counter * TEXT_PADDING, TARGET_SIZE, TARGET_SIZE, 0, true);
		counter--;
	}

}

void CreditsState::onUpdate(Keyboard* keyboard)
{
	if (current != "") {
		if (width > TARGET_SIZE && height > TARGET_SIZE) {
			angle += 1.6;
			width -= 4;
			height -= 4;
		}
		else if (currentY < targetY)
		{
			currentY += 0.8;
		}
	}
}

void CreditsState::onClick(Button* button)
{
	if (button->getText() == "<")
	{
		context->setState(new MenuState(context));
	}
}

void CreditsState::onDestroy()
{
}