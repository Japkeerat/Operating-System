#include <stdio.h>

int main() {
    printf("NOTE: THIS ASSUMES ALL PROCESSES ARRIVE AT TIME=0\n");
    printf("Enter number of processes to schedule: ");
    int n; //number of processes
    scanf("%d", &n);

    int pid[n]; //Process ID
    int priority[n]; //priority time of processes
    int burst[n]; //burst time of processes

    //Taking input of priority and burst time of processes
    for(int i=0; i<n; i++) {
        pid[i] = i+1;
        printf("priority of process %d: ", (i+1));
        scanf("%d", &priority[i]);
        printf("Burst time of process %d: ", (i+1));
        scanf("%d", &burst[i]);
    }

    //Sorting processes according to priority
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(priority[i]>priority[j]||(priority[i]==priority[j]&&burst[i]>burst[j])) {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                int temp1 = pid[i];
                pid[i] = pid[j];
                pid[j] = temp1;
            }
        }
    }

    int waiting[n];
    int turnaround[n];

    waiting[0] = 0;
    turnaround[0] = burst[0];

    //Calculating waiting time and turnaround time for all processes
    for(int i=1; i<n; i++) {
        waiting[i] = waiting[i-1]+burst[i-1];
        turnaround[i] = waiting[i]+burst[i];
    }

    //Sorting processes by process id
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(pid[i]>pid[j]) {
                int temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
                int temp1 = priority[i];
                priority[i] = priority[j];
                priority[j] = temp1;
                temp1 = burst[i];
                burst[i] = burst[j];
                burst[j] = temp1;
                temp1 = waiting[i];
                waiting[i] = waiting[j];
                waiting[j] = temp1;
                temp1 = turnaround[i];
                turnaround[i] = turnaround[j];
                turnaround[j] = temp1;
            }
        }
    }

    //Printing the output
    printf("PID AT  P  BT  WT  TAT\n");
    for(int i=0; i<n; i++) {
        printf("%d, 0, %d, %d, %d, %d\n",pid[i],priority[i],burst[i],waiting[i],turnaround[i]);
    }
    printf("where,\nPID: Process ID\nAT: Arrival Time\nP: Priority\nBT: Burst Time\nWT: Waiting Time\nTAT: Turnaround Time\n");

    system("pause");
    return 0;
}
