#include "../include/diskUtilization.h"

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>

std::vector<diskUsage> diskReading()
{
	std::vector<diskUsage> vec;
	std::string line;
	int major = 0;
	int minor = 0;
	std::string device = "";
	int readCompleted = 0;
	int readMerged = 0;
	int sectorRead = 0;
	int timeIOreading = 0;
	int writesComplete = 0;
	int writeMerged = 0;
	int sectorWritten = 0;
	int timeIOwriting = 0;
	int currentIO = 0;
	int timeIO = 0;

	std::ifstream diskUtilization("/proc/diskstats");

	if(!diskUtilization)
	{
		std::cerr << "Error opening file" << std::endl;
		return {};
	}

	while(getline(diskUtilization, line))
	{
		std::istringstream iss(line);
		iss >> major >> minor >> device >> readCompleted >> readMerged >> sectorRead >> timeIOreading >> writesComplete >> writeMerged >> sectorWritten >> timeIOwriting >> timeIOwriting >> currentIO >> timeIO ;

	if(device.starts_with("loop") || (minor != 0))
	{
		continue;
	}

	diskUsage newDisk;
	newDisk.diskName = device;
	newDisk.reading = timeIO;

	vec.push_back(newDisk);
	
	}


	diskUtilization.close();
	return vec;
}


void diskUtilization()
{
	std::vector<diskUsage> firstReading = diskReading();
	sleep(1);
	std::vector<diskUsage> secondReading = diskReading();


	int n1 = firstReading.size();
	double utilization = 0;
	for(int i = 0 ; i < n1 ; i++)
	{
		utilization = (secondReading[i].reading - firstReading[i].reading) *100 / 1000;
		std::cout << firstReading[i].diskName <<  " : " << utilization << "%" << std::endl;
	}


	
}



