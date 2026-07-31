#pragma once
#include <string>
#include <vector>
struct diskUsage
{
	std::string diskName;
	long reading;
};


std::vector<diskUsage> diskReading();

void diskUtilization();
