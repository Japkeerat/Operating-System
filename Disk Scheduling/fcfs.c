#include<stdio.h>

int main() {
    int start;
    printf("Enter the starting point: ");
    scanf("%d", &start);
    int n;
    printf("Enter number of locations to visit: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter locations to visit on new line. Locations lie between 0, 199\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if(a[i]>199||a[i]<0) {
            printf("Error. Number out of bounds... Reenter this location\n");
            i--;
        }
    }
    int seek = 0;
    for(int i=0; i<n; i++) {
        int x = start - a[i];
        if(x<0) {
            seek = seek - x;
        }
        else {
            seek = seek + x;
        }
        start = a[i];
    }
    printf("Total head movement using FCFS is %d\n", seek);
    system("pause");
    return 0;
}
