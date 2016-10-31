#pragma once

#include <string>
#include <ctime> 
#include <Windows.h>
#include <iostream>

class Log
{
public:
	static void error(const std::string message);
	static void warning(const std::string message);
	static void log(const std::string message);
	static void debug(const std::string message);

private:
	static void print(const std::string message, const unsigned short color);
	static void setColor(unsigned short color);
};