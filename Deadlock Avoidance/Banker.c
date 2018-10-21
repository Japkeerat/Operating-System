#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>

int main() {
    int p, r; //p-->processes||r-->resources
    printf("Enter number of processes: ");
    scanf("%d",&p);
    printf("Enter number of resources: ");
    scanf("%d",&r);

    int pid[p]; //Priocess id
    int alloc[p][r]; //allocation matrix
    int max[p][r]; //max requirement matrix
    int avail[r]; //available resources vector
    bool done[p]; //is TRUE if process i has successfully gotten out of chances of creation of deadlock

    printf("NOTE: In next steps, VECTOR is defined as the row of a table, elements entered in linear order from left to right.\n\n");
    printf("Enter available resource vector: ");
    for(int i=0; i<r; i++) {
        scanf("%d",&avail[i]);
    }
    for(int i=0; i<p; i++) {
        pid[i] = -1;
        done[i] = false;
        printf("Enter allocated resource vector to process %d: ", (i+1));
        for(int j=0; j<r; j++) {
            scanf("%d",&alloc[i][j]);
        }
    }
    for(int i=0; i<p; i++) {
        printf("Enter max resources required vector to process %d: ", (i+1));
        for(int j=0; j<r; j++) {
            scanf("%d",&max[i][j]);
        }
    }

    int need[p][r];

    //getting need matrix
    for(int i=0; i<p; i++) {
        for(int j=0; j<r; j++) {
            need[i][j] = max[i][j]-alloc[i][j];
            if(need[i][j]<0) {
                printf("ERROR!!! (%d, %d) element of max and allocation table results in a negative element in need matrix.\nTERMINATING...\n",i,j);
                sleep(5);
                return 0;
            }
        }
    }

    int k=0;
    int count=0;
    label:
    for(int i=0; i<p; i++) {
        if(!done[i]) {
            bool possible = true;
            for(int j=0; j<r; j++) {
                if(need[i][j]>avail[j]) {
                    possible = false;
                    j=r;
                }
            }
            if(possible) {
                done[i] = true;
                pid[k] = i+1;
                k++;
                for(int j=0; j<r; j++) {
                    avail[j] = avail[j]+alloc[i][j];
                }
            }
        }
    }
    count++;
    for(int i=0; i<p; i++) {
        if(count<p) {
            if(!done[i]) {
                goto label;
            }
        }
    }

    if(count==p) {
        printf("Deadlock can't be avoided.\n");
    }
    else {
        printf("Order of execution of processes that doesn't cause a deadlock is: ");
        for(int i=0; i<p; i++) {
            printf("%d-->",pid[i]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
