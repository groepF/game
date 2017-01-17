#pragma once

#include <string>
#include <ctime> 
#include <Windows.h>
#include <iostream>

class Log
{
public:
	/// Logs error messages to the console.
	static void error(const std::string message);
	/// Logs warning messages to the console.
	static void warning(const std::string message);
	/// Logs normal messages to the console.
	static void log(const std::string message);
	/// Logs debug messages to the console.
	static void debug(const std::string message);

private:
	/// The inplementation of the methods above.
	/// It allows for logging to the console with a specific color.
	static void print(const std::string message, const unsigned short color);
	/// Sets the color for the console.
	static void setColor(const unsigned short color);
};