#include "Game.h"
#include "AudioController.h"
#include <chrono>
#include <thread>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "FirstState.h"

int main(int argc, char* args[])
{
	//leakdetectie
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	/*AudioController audio{};
	
	audio.playSound("../game/sound/fullsample.wav", true);
	audio.playSound("../game/sound/sample.wav", false);

	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	sleep_for(seconds(5));

	audio.pauseBackgroundSound();

	sleep_for(seconds(3));

	audio.resumeBackgroundSound();

	sleep_for(seconds(5));

	audio.stopBackgroundSound();*/

	Game game("Awesome game", 600, 400);

	FirstState state1;
	game.Add(&state1);

	game.Run();

	return 0;
}
