#include "Console.h"

Console::Console()
{
}

Console::~Console()
{
}

void Console::Println(const char* line)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	printf("[%02d:%02d:%02d INFO] %s\n", newtime.tm_hour, newtime.tm_min, newtime.tm_sec, line);
}