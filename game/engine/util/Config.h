#pragma once

#include <string>
#include <map>
#include "Log.h"
#include "Utils.h"
#include <fstream>
#include <vector>

#define COMMENT '#'

class Config
{
public:
	/// Loads a config file based on the supplied filename.
	static bool load(std::string filename);
	/// Checks if the config has a key.
	static bool has(std::string key);
	/// Gets a variable from the config (string format).
	static std::string get(std::string key);
	/// Gets a string from the config.
	static std::string getString(std::string key, std::string defaultValue);
	/// Gets a boolean from the config.
	static bool getBool(std::string key, bool defaultValue);
	/// Gets an integer from the config.
	static int getInt(std::string key, int defaultValue);
private:
	/// Key/value pairs from a config file.
	static std::map<std::string, std::string> config;
};