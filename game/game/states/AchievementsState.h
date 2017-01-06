#pragma once
#include "../../engine/core/State.h"
#include "../../engine/input/OnClickListener.h"

class AchievementsState : public State, public OnClickListener
{
public:
	AchievementsState(StateContext* context);
	~AchievementsState();

	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

	bool onClick(Button* button) final;

private:
	Sprite *background, *logo;
};

