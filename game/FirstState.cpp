#include "FirstState.h"
#include "Console.h"
#include <chrono>
#include <thread>

FirstState::FirstState() {}
FirstState::~FirstState() {}

void FirstState::OnInitialize()
{
	//std::thread t1(&FirstState::playAudioDemo);

	audioConstoller.playSound("../game/sound/fullsample.wav", true);

}
void FirstState::OnRender() {}
void FirstState::OnUpdate() {}
void FirstState::OnCleanUp() {}

void FirstState::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_0:
			Console::Println("You pressed the 0 key.");
			audioConstoller.playSound("../game/sound/sample.wav", false);
			break;
		default:
			break;
		}
	}
}

void FirstState::playAudioDemo() const
{

	//AudioController audio{};

	//audio.playSound("../game/sound/fullsample.wav", true);
	//audio.playSound("../game/sound/sample.wav", false);

	//using namespace std::this_thread; // sleep_for, sleep_until
	//using namespace std::chrono; // nanoseconds, system_clock, seconds

	//sleep_for(seconds(5));

	//audio.pauseBackgroundSound();

	//sleep_for(seconds(3));

	//audio.resumeBackgroundSound();

	//sleep_for(seconds(5));

	//audio.stopBackgroundSound();
}
