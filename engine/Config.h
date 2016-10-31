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
	Config();

	static bool load(std::string filename);

	static bool has(std::string key);

	static std::string get(std::string key);

	static std::string getString(std::string key, std::string defaultValue);

	static bool getBool(std::string key, bool defaultValue);

	static int getInt(std::string key, int defaultValue);

private:
	static std::map<std::string, std::string> config;
};
