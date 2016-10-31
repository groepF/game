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
	std::string& ltrim(std::string &str);

	std::string& rtrim(std::string& str);

	std::string& trim(std::string& str);

	std::vector<std::string> split(const std::string& str, char delimeter);

	int toInt(std::string text);
}
