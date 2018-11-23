#include<stdio.h>

int main() {
    int start;
    printf("Enter starting point: ");
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
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(a[j]<a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int i=0;
    int seek = 0;
    while(a[i]<start) {
        int x;
        if(i>0) {
            x = a[i]-a[i-1];
        }
        else {
            x = a[i];
        }
        seek = seek+x;
        i++;
    }
    seek = seek + (start - a[i-1]);
    seek = seek + a[i];
    while(i<n-1) {
        int x = a[i+1]-a[i];
        seek = seek+x;
        i++;
    }
    printf("Total head movement using SCAN is %d\n", seek);
    system("pause");
    return 0;
}
