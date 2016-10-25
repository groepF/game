#include "Game.h"
#include "AudioController.h"
#include <chrono>
#include <thread>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char* args[])
{
	//leakdetectie
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	AudioController audio{};
	
	audio.playSound("../game/sound/fullsample.wav", -1);
	audio.playSound("../game/sound/sample.wav", 1);
	//audio.playSound("../game/sound/samplechunk.wav", 1);

	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	sleep_for(seconds(5));

	audio.pauseBackgroundSound();

	sleep_for(seconds(3));

	audio.resumeBackgroundSound();

	sleep_for(seconds(5));

	audio.stopBackgroundSound();

	Game game("Awesome game", 600, 400);
	

	return 0;
}
