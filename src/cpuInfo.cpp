#include "../include/cpuInfo.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>



CpuUsage calculateCpuUsage()
{

	std::ifstream CpuUsage("/proc/stat");
	if(!CpuUsage)
	{
		std::cerr << "Error opening file" << std::endl;
		return {};
	}


	std::string line;
	int user = 0;
	int nice = 0;
	int system = 0;
	int idle = 0;
	int iowait = 0;
	int irq = 0;
	int softirq = 0;
	int steal = 0;
	int guest = 0;
	int guest_nice = 0;
	std::string info;

	getline(CpuUsage, line);

	std::istringstream iss(line);

	iss >> info >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;
	
	int totalTicks = user+nice+system+idle;

	CpuUsage.close();

	return {totalTicks , idle};
	
}


void  displayCPUusage()
{
	CpuUsage first = calculateCpuUsage();
	
	sleep(2);

	CpuUsage second = calculateCpuUsage();

	long total1 = first.totalTicks;
	long idle1 = first.idleTicks;

	long total2 = second.totalTicks;
	long idle2 = second.idleTicks;

	long totalDiff = total2 - total1;
	long idleDiff = idle2 - idle1;
	long calculation = ((totalDiff - idleDiff)* 100/totalDiff) ;

	std::cout << "CPU Usage : " << calculation << "%" << std::endl;
}





