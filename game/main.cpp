#include "Game.h"
#include "AudioController.h"

int main(int argc, char* args[])
{

	AudioController audio{};
	
	audio.playSound("../game/sound/fullsample.wav", -1, 0);
	audio.playSound("../game/sound/sample.wav", 1, -1);
	audio.playSound("../game/sound/samplechunk.wav", 1, -1);

	Game game("Awesome game", 600, 400);
	

	return 0;
}
