#include "Game.h"
#include "FirstState.h"

int main(int argc, char* args[])
{
	Game game("Awesome game", 600, 400);

	FirstState state1;
	game.Add(&state1);

	game.Run();

	return 0;
}
