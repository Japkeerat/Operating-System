#include <stdio.h>

int main() {
    int n; //number of processes
    printf("Number of processes: ");
    scanf("%d", &n);
    int pid[n];
    float arrival[n]; //arrival time of processes
    float burst[n]; //burst time of processes
    float waiting[n];
    float turnaround[n];
    for(int i=0; i<n; i++) {
        pid[i] = i+1;
        printf("Arrival time of Process %d: ", (i+1));
        scanf("%f", &arrival[i]);
        printf("Burst time of Process %d: ", (i+1));
        scanf("%f", &burst[i]);
        waiting[i] = -1;
        turnaround[i] = -1;
    }

    //sorting according to arrival time. if arrival time matches, sort according to burst time
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arrival[i]>arrival[j] || (arrival[i]==arrival[j]&&burst[i]>burst[j])) {
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

    float clocktime = arrival[0]+burst[0];
    waiting[0]=0;
    turnaround[0]=burst[0];

    for(int i=1; i<n; i++) {
        float temp1=burst[i];
        int j=i;
        int temp=j;
        while(arrival[j]<=clocktime) {
            if(burst[j]<temp1&&waiting[j]==-1) {
                temp=j;
            }
            j++;
        }
        waiting[temp]=clocktime-arrival[temp];
        turnaround[temp]=waiting[temp]+burst[temp];
        clocktime=clocktime+burst[temp];
        if(temp!=i) {
            i--;
        }
    }

    //sort according to pid
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(pid[i]>pid[j]) {
                int temp1 = pid[i];
                pid[i] = pid[j];
                pid[j] = temp1;
                float temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                temp = waiting[i];
                waiting[i] = waiting[j];
                waiting[j] = temp;
                temp = turnaround[i];
                turnaround[i] = turnaround[j];
                turnaround[j] = temp;
            }
        }
    }

    //printing output
    printf("PID, AT, BT, WT, TAT\n");
    for(int i=0; i<n; i++) {
        printf("%d, %f, %f, %f, %f", pid[i], arrival[i], burst[i], waiting[i], turnaround[i]);
        printf("\n");
    }

    system("pause");
	return 0;
}
