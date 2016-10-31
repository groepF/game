#include "Engine.h"

int main(int argc, char** argv)
{
	Engine engine("config.ini");

	engine.run();

	return 0;
}