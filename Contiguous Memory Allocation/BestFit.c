#include<stdio.h>
#include<stdbool.h>

void sort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    printf("NOTE: IT USES FIXED SIZED PARTITIONING\n");

    printf("Enter number of processes: ");
    int pro;
    scanf("%d",&pro);
    printf("Enter number of blocks: ");
    int block;
    scanf("%d",&block);

    if(pro>block) {
        printf("WARNING: Atleast %d processes won't be allocated memory\n",(pro-block));
    }

    int psize[pro]; //stores isze of processes
    int bsize[block]; //stores size of blocks
    int frag[block]; //stores size of memory wasted in internal fragmentation
    int alloc[pro]; //stores the address of block to which process i is allocated
    int occup[block]; //stores the address of process that is allocated to block i

    for(int i=0; i<pro; i++) {
        printf("Enter size of process %d: ",(i+1));
        scanf("%d",&psize[i]);
        alloc[i] = -1;
    }
    for(int i=0; i<block; i++) {
        printf("Enter size of block %d: ",(i+1));
        scanf("%d",&bsize[i]);
        occup[i] = -1;
    }

    sort(psize, pro);
    sort(bsize, block);

    for(int i=0; i<pro; i++) {
        for(int j=0; j<block; j++) {
            if(psize[i]<=bsize[j]&&occup[j]==-1) {
                occup[j] = i;
                alloc[i] = j;
                frag[j] = bsize[j]-psize[i];
                j=block;
            }
        }
    }

    printf("PS\tBS\tIF\n");
    if(pro>block) {
        for(int i=0; i<pro; i++) {
            if(alloc[i]==-1) {
                printf("%d\t-\t-\n",psize[i]);
            }
            else {
                printf("%d\t%d\t%d\n",psize[i],bsize[alloc[i]],frag[alloc[i]]);
            }
        }
    }
    else {
        for(int i=0; i<block; i++) {
            if(occup[i]==-1) {
                printf("-\t%d\t-\n",bsize[i]);
            }
            else {
                printf("%d\t%d\t%d\n",psize[occup[i]],bsize[i],frag[i]);
            }
        }
    }
    printf("where,\nPS: Process size\nBS: Block Size\nIF: Internal fragmentation\n");

    system("pause");
    return 0;
}
