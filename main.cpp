#include "include/memInfo.h"
#include "include/cpuInfo.h"
#include "include/diskUtilization.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main() 
{	
	while(true)
	{
		std::cout << "\033[2J\033[H";
		std::cout << "==============================\n";
		std::cout << "     System Information\n";
		std::cout << "==============================\n\n";

		//RAM Utilization
		std::cout << "\033[1;34m" << "RAM\n" << "\033[0m";	
		displayMemoryInfo();

		std::cout << "\n\n------------------------------\n\n";
		
		//CPU Utilization
		std::cout << "\033[1;34m" << "CPU\n" << "\033[0m";
		displayCPUusage();
	
		std::cout << "\n\n------------------------------\n\n";
	
		//Disk Utilizaiton
		std::cout << "\033[1;34m" << "Disk Utilization\n" << "\033[0m";
		diskUtilization();
		sleep(1);


	}


	return 0;
}
