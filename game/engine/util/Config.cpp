#include "Config.h"

std::map<std::string, std::string> Config::config;

bool Config::load(std::string filename)
{
	config.clear();

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		Log::error("Config::load: Couldn't open '" + filename + "'");
		return false;
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line, '\n');

		if (line.empty())
			continue;

		if (line[0] == COMMENT)
			continue;

		auto current = String::split(line, '=');

		if (has(current.front()))
		{
			Log::warning("Config::load: Existing key '" + current.front() + "' that maps to '" + current.back() + "'");
			continue;
		}

		config.insert(std::pair<std::string, std::string>(current.front(), current.back()));
	}

	return true;
}

bool Config::has(std::string key)
{
	auto iterator = config.find(key);
	return (iterator != config.end());
}

std::string Config::get(std::string key)
{
	auto iterator = config.find(key);

	if (iterator == config.end())
	{
		Log::warning("Config::get: Tried to get unexisting key '" + key + "'");
		return "";
	}

	return (*iterator).second;
}

std::string Config::getString(std::string key, std::string defaultValue)
{
	auto value = get(key);
	return value.empty() ? defaultValue : value;
}

bool Config::getBool(std::string key, bool defaultValue)
{
	auto value = get(key);
	return value.empty() ? defaultValue : (value.compare("true") == 0) || (value.compare("yes") == 0);
}

int Config::getInt(std::string key, int defaultValue)
{
	auto value = get(key);
	return value.empty() ? defaultValue : String::toInt(value);
}