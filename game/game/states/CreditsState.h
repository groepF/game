#pragma once
#include "../../engine/core/State.h"

class CreditsState : public State
{
public:

	CreditsState(StateContext* context);
	~CreditsState();

	void onCreate() final;
	void onRender(Screen *screen) final;
	void onUpdate(Keyboard *keyboard) final;
	void onDestroy() final;

private:
	Sprite *background, *logo;
	double angle;
	int width, height;
	double currentY;
	int targetY;
	std::vector<std::string> remaining;
	std::vector<std::string> shown;
	std::string current;
};

