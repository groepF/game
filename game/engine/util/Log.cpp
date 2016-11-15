#include "Log.h"

void Log::debug(std::string message) { print(message, 111); }
void Log::error(std::string message) { print(message, 207); }
void Log::warning(const std::string message) { print(message, 79); }
void Log::log(const std::string message) { print(message, 15); }

void Log::print(const std::string message, const unsigned short color)
{
	setColor(color);
	struct tm newtime;
	auto now = time(nullptr);
	localtime_s(&newtime, &now);
	printf("[%02d:%02d:%02d] %s\n", newtime.tm_hour, newtime.tm_min, newtime.tm_sec, message.c_str());
	setColor(15);
}

void Log::setColor(unsigned short color)
{
	auto hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}