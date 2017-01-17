#pragma once
#include "../Game.h";
#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../../engine/input/OnClickListener.h"
#include "../../engine/widgets/ImageButton.h"

class Button;

class GameSelectionState : public State, public OnClickListener
{
public:
	GameSelectionState(StateContext* context);
	~GameSelectionState();
	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;
	bool onClick(Widget* button) final;
private:
	Game* game;
	Sprite* background;
	std::vector<Button*> timeButtons;
	std::vector<Button*> goalButtons;
	std::vector<ImageButton*> mapButtons;
	std::vector<Button*> optionButtons;
	void deselectAll(std::vector<Button*> buttons);
	void deselectAll(std::vector<ImageButton*> buttons);
};

