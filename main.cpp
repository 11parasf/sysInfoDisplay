#include <iostream>
#include <unistd.h>
#include "include/memInfo.h"
#include "include/cpuInfo.h"
#include "include/diskUtilization.h"

using namespace std;


int main() 
{	
	while(true)
	{
		std::cout << "\033[2J\033[H";
		std::cout << "==============================\n";
		std::cout << "     System Information\n";
		std::cout << "==============================\n\n";

		//RAM usage infomartion
		std::cout << "\033[1;34m";
		std::cout << "RAM\n";
		std::cout << "\033[0m";
		displayMemoryInfo();

		std::cout << "\n\n------------------------------\n\n";
	
		std::cout << "\033[1;34m" << "CPU\n" << "\033[0m";
		displayCPUusage();

		
		//Disk Utilizaiton
	
		std::cout << "\n\n------------------------------\n\n";
	
		std::cout << "\033[1;34m" << "Disk Utilization\n" << "\033[0m";
		diskUtilization();
		sleep(1);


	}


	return 0;
}
