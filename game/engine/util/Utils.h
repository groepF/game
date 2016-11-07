#pragma once

#include <string>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <sstream>

namespace String
{
	/// Trims the left side of a string.
	std::string& ltrim(std::string &string);
	/// Trims the right side of a string.
	std::string& rtrim(std::string& string);
	/// Trims both the left and the right side of a string.
	std::string& trim(std::string& string);
	/// Splits a string based on the supplied delimeter.
	std::vector<std::string> split(const std::string& string, char delimeter = ' ');
	/// Converts a string to an int.
	int toInt(std::string string);
}