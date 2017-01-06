#pragma once
#include "../../engine/core/State.h"
#include "../../engine/input/OnClickListener.h"

class HelpState : public State, public OnClickListener
{
public:
	HelpState(StateContext* context);
	~HelpState();

	void onCreate() final;
	void onRender(Screen* screen) final;
	void onUpdate(Keyboard* keyboard) final;
	void onDestroy() final;

	void onClick(Button* button) final;
private:
	Sprite *background, *logo;
};
