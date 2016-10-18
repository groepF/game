#include "Game.h"
#include "AudioController.h"

int main(int argc, char* args[])
{

	/*AudioController audio{};
	audio.playSound("../game/sound/sample.wav");*/


	Game game("Awesome game", 600, 400);
	
	game.getAudioController().playSound("../game/sound/sample.wav");

	return 0;
}
