#include "Utils.h"
#include <random>
#include <chrono>

std::string& String::ltrim(std::string &string)
{
	string.erase(string.begin(), std::find_if(string.begin(), string.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return string;
}

std::string& String::rtrim(std::string& string)
{
	string.erase(std::find_if(string.rbegin(), string.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), string.end());
	return string;
}

std::string& String::trim(std::string& string)
{
	return String::ltrim(String::rtrim(string));
}

std::vector<std::string> String::split(const std::string& string, char delimeter)
{
	std::stringstream ss(string);
	std::string item;
	std::vector<std::string> elements;

	while (std::getline(ss, item, delimeter))
	{
		elements.push_back(String::trim(item));
	}

	return elements;
}

int String::toInt(std::string string)
{
	return std::stoi(string);
}

int Math::random(int low, int high)
{
	std::default_random_engine generator;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);

	std::uniform_int_distribution<int> distribution(low, high);

	return distribution(generator);
}
