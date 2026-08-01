#pragma once

struct CpuUsage
{
	long totalTicks;
	long idleTicks;
};

CpuUsage calculateCpuUsage();
void displayCPUusage();


