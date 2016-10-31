#include "Utils.h"

std::string& String::ltrim(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return str;
}

std::string& String::rtrim(std::string& str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
	return str;
}

std::string& String::trim(std::string& str)
{
	return String::ltrim(String::rtrim(str));
}

std::vector<std::string> String::split(const std::string& str, char delimeter)
{
	std::stringstream ss(str);
	std::string item;
	std::vector<std::string> elements;

	while (std::getline(ss, item, delimeter))
	{
		elements.push_back(String::trim(item));
	}

	return elements;
}

int String::toInt(std::string text)
{
	return std::stoi(text);
}
