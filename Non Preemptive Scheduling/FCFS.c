#include <stdio.h>

int main() {
    printf("Enter number of processes to schedule: ");
    int n; //number of processes
    scanf("%d", &n);

    int pid[n]; //Process ID
    float arrival[n]; //arrival time of processes
    float burst[n]; //burst time of processes

    //Taking input of arrival and burst time of processes
    for(int i=0; i<n; i++) {
        pid[i] = i+1;
        printf("Arrival time of process %d: ", (i+1));
        scanf("%f", &arrival[i]);
        printf("Burst time of process %d: ", (i+1));
        scanf("%f", &burst[i]);
    }

    //Sorting processes according to arrival time
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arrival[i]>arrival[j]||(arrival[i]==arrival[j]&&burst[i]>burst[j])) {
                float temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                int temp1 = pid[i];
                pid[i] = pid[j];
                pid[j] = temp1;
            }
        }
    }

    float waiting[n];
    float turnaround[n];

    waiting[0] = 0;
    turnaround[0] = burst[0];

    //Calculating waiting time and turnaround time for all processes
    for(int i=1; i<n; i++) {
        waiting[i] = waiting[i-1]+arrival[i-1]+burst[i-1]-arrival[i];
        turnaround[i] = waiting[i]+burst[i];
    }

    //Sorting processes by process id
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(pid[i]>pid[j]) {
                int temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
                float temp1 = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp1;
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
    printf("PID  AT  BT  WT  TAT\n");
    for(int i=0; i<n; i++) {
        printf("%d,%f,%f,%f,%f\n",pid[i],arrival[i],burst[i],waiting[i],turnaround[i]);
    }
    printf("where,\nPID: Process ID\nAT: Arrival Time\nBT: Burst Time\nWT: Waiting Time\nTAT: Turnaround Time\n");

    system("pause");
    return 0;
}
