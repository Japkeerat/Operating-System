#include<stdio.h>
#include<stdbool.h>

int main() {
    printf("NOTE: IT IS ASSUMED THAT ALL PROCESSES ARRIVE AT TIME=0\n");
    int n; //stores number of processes
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n]; //Process ID
    int burst[n]; //Process burst time
    int remburst[n]; //remaining burst time of process
    bool completed[n]; //keeps a check whether a process is completed or not. TRUE if completed
    int quantum;

    for(int i=0; i<n; i++) {
        pid[i] = i+1;
        printf("Enter burst time of %d: ",pid[i]);
        scanf("%d",&burst[i]);
        completed[i] = false;
        remburst[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d",&quantum);

    int waiting[n]; //waiting time of a process
    int turn[n]; //turnaround time of a process
    int clt = 0; //clock time

    //scheduling according to round robin algorithm
    for(int i=0; i<n; i++) {
        if(completed[i]==false) {
            for(int i=0; i<n; i++) {
                if(remburst[i]>quantum) {
                    clt = clt+quantum;
                    remburst[i] = remburst[i]-quantum;
                    if(remburst[i]==0) {
                        completed[i] = true;
                        waiting[i] = clt-burst[i];
                    }
                }
                else if(remburst[i]<=quantum && completed[i]==false) {
                    clt = clt+remburst[i];
                    remburst[i] = 0;
                    completed[i] = true;
                    waiting[i] = clt-burst[i];
                }
            }
            i=-1;
        }
    }

    for(int i=0; i<n; i++) {
        turn[i] = waiting[i] + burst[i];
    }

    //Sorting according to process id
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(pid[i]>pid[j]) {
                int temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                temp = waiting[i];
                waiting[i] = waiting[j];
                waiting[j] = temp;
                temp = turn[i];
                turn[i] = turn[j];
                turn[j] = temp;
            }
        }
    }

    printf("PID, AT, BT, WT, TAT\n");
    for(int i=0; i<n; i++) {
        printf("%d, 0, %d, %d, %d\n",pid[i],burst[i],waiting[i],turn[i]);
    }

    system("pause");
    return 0;
}
