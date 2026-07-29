#include <iostream>
#include <unistd.h>
#include "include/memInfo.h"

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

		sleep(2);
	}


	return 0;
}
