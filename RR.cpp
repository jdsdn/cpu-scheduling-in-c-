#include "./headers/Process.h"
#include "./headers/FCFS.h"
#include "./headers/HRN.h"
#include "./headers/NPPS.h"
#include "./headers/PPS.h"
#include "./headers/RR.h"
#include "./headers/SJF.h"
#include "./headers/SRT.h"

#include <iostream>
#include <cstring>

using namespace std;

void Input();

int quantum;

int main()
{
    int process_count = 0;
    int i = 0;

    Quantum quantum;
    Process *process;

	Input();
    FILE *fp = fopen("process.txt", "r");

    fscanf(fp, " %d", &process_count);

    process = (Process *)malloc(sizeof(Process) * process_count);

    while (i < process_count)
    {
        fscanf(fp, "%s %d %d %d", process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);
        i++;
    }

    fscanf(fp, " %d", &quantum);
    
    puts("\t\t\t\t");
    RR(process, process_count, quantum);

    fclose(fp);

    system("pause");

    return 0;
}

void Input() {
	FILE *fptr;
	fptr = fopen("process.txt", "rb+");

    int process_count = 0;
    int i = 0;
    
    char id[100];
    int arrive_time;
    int burst;
    int priority;

	if(fptr == NULL){
		fptr = fopen("process.txt", "wb");
		
		fputs("4\n", fptr);
		fprintf(fptr, "%s %d %d %d\n", "P1", 0, 4, 3);
		fputs("P2 1 1 2\n", fptr);
		fputs("P3 5 3 4\n", fptr);
		fputs("P4 3 7 3\n", fptr);
		fputs("2\n", fptr);
	}
	
	fptr = fopen("process.txt", "wb");
	
	cout << "\t+------------------------+" << endl;
	cout << "\t| Algorithm: Round Robin |" << endl;
	cout << "\t+------------------------+" << endl;

    cout << "\n\tNumber of Processes: ";
    cin >> process_count;
    
    cout << "\n\tTime Quantum: ";
    cin >> quantum;
    
    fprintf(fptr, "%d\n", process_count);
    
    for(i = 0; i < process_count; i++) {
    	cout << "\n\tProcess Name: \t";
    	cin >> id;
    	
    	cout << "\tArrival Time: \t";
    	cin >> arrive_time;
    	
    	cout << "\tBurst Time: \t";
    	cin >> burst;
    	
    	priority = 0;
    	
		fprintf(fptr, "%s %d %d %d\n", id, arrive_time, burst, priority);
	}
	
	fprintf(fptr, "%d\n", quantum);

	fclose(fptr);
}

