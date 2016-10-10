#pragma once

#include <iostream>
#include <ctime> 
#include <string> 

class Console
{
public:
	Console();
	~Console();

	static void Println(const char* line);
};

