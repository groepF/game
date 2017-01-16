#pragma once
#include "../../engine/core/State.h"
#include "../Game.h"
#include "../../engine/input/OnClickListener.h"
#include "../../engine/core/StateContext.h"
#include "GameState.h"

class PauseState :
	public State, public OnClickListener
{
public:
	PauseState(StateContext* context, Game* game);
	~PauseState();
	void onCreate() override;
	void onRender(Screen* screen) override;
	void onUpdate(Keyboard* keyboard) override;
	void onDestroy() override;
	StateContext* context_;

	void addToiletFrames();
	bool onClick(Widget *button) final;


private:
	Game *game;
	Sprite* background;
	Sprite* logo;
	Sprite* toilet;

	int frames = 0;
	int explosionFrame = 0;

	std::vector<Sprite*> toiletAnimation;
};

