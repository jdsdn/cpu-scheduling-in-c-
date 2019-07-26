#ifndef __PRINT__TABLE__
#define __PRINT__TABLE__

#include "Process.h"

void print_table(Process p[], int n)
{
	int i;

	puts("\t+----------------+------------+-------------+----------+--------------------------------+");
	puts("\t|  Process Name  | Burst Time | Arrive Time | Priority | Waiting Time | Turnaround Time |");
	puts("\t+----------------+------------+-------------+----------+--------------------------------+");

	for (i = 0; i < n; i++)
	{
  		printf("\t|       %3s      |     %3d    |     %3d     |  %3d     |     %3d      |      %3d        |\n",
		p[i].id, p[i].burst, p[i].arrive_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);

	puts("\t+----------------+------------+-------------+----------+--------------+-----------------+");
	}

	puts("");
}

#endif
