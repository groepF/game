#pragma once
#include "../Game.h";
#include "../../engine/core/State.h"
#include "../../engine/world/World.h"
#include "../../engine/input/OnClickListener.h"

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
	bool onClick(Button* button) final;
private:
	Game* game;
	Sprite* background;
	std::vector<Button*> timeButtons;
	std::vector<Button*> goalButtons;
	std::vector<Button*> mapButtons;
	std::vector<Button*> optionButtons;
	void deselectAll(std::vector<Button*> buttons);
};

