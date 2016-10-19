#pragma once

#include <iostream>
#include <ctime> 
#include <string> 

class Console
{
private:
	Console();
	~Console();

public:
	static void Println(const char* line);
};

