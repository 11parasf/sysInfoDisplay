#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/memInfo.h"

int conversion(int value)
{
	return value/1000000;
}


void displayMemoryInfo()
{
	//std::cout << "\033[2J\033[H";
	std::ifstream memInfo("/proc/meminfo");
	if(!memInfo)
	{
		std::cerr << "Error opening file" << std::endl;
	}

	std::string line;
	int totalMemory = 0;
	int availableMemory = 0;
	while(getline(memInfo, line))
	{
		std::istringstream iss(line);

		std::string dataName;
		int value;
		std::string unit;
		
		iss >> dataName >> value >> unit;
		
		if(dataName == "MemTotal:")
		{
			totalMemory = value;
			std::cout << std::left << std::setw(20) << "Total Memory "<< " = " << conversion(value) << " GB" << std::endl ;
		}
		else if(dataName == "MemAvailable:")
		{
			availableMemory = value;
			std::cout << std::left << std::setw(20) << "Available Memory " << " = " << conversion(value) << " GB" << std::endl;
		}
	
		//std::cout << "Used Memory : " << conversion(totalMemory - usedMemory) << " GB" << std::endl;

	}
	memInfo.close();
	std::cout << std::left << std::setw(20) << "Used Memory " << " = " << conversion(totalMemory - availableMemory) << " GB" << std::endl;
}


