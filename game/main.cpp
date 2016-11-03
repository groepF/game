#include "Game.h"
#include "AudioController.h"
#include <chrono>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "FirstState.h"

int main(int argc, char* args[])
{
	//leakdetectie
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game game("Awesome game", 600, 400);

	FirstState state1;
	game.Add(&state1);

	game.Run();

	return 0;
}
