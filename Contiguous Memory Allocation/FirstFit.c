#include<stdio.h>
#include<stdbool.h>

int main() {
    printf("NOTE: IT USES FIXED SIZE PARTITIONING\n");

    printf("Enter number of processes: ");
    int pro;
    scanf("%d",&pro);
    printf("Enter number of blocks: ");
    int block;
    scanf("%d",&block);

    if(pro>block) {
        printf("WARNING: Atleast %d processes won't be allocated memory\n",(pro-block));
    }

    int psize[pro]; //stores size of processes
    int bsize[block]; //stores size of blocks
    int frag[block]; //stores size of memory wasted in internal fragmentation
    int alloc[pro];
    int occup[block];

    for(int i=0; i<pro; i++) {
        printf("Enter size of process %d: ", (i+1));
        scanf("%d",&psize[i]);
        alloc[i] = -1;
    }
    for(int i=0;i<block;i++) {
        printf("Enter size of memory block %d: ", (i+1));
        scanf("%d",&bsize[i]);
        occup[i] = -1;
    }

    for(int i=0;i<pro;i++) {
        for(int j=0;j<block;j++) {
            if(psize[i]<bsize[j]&&occup[j]==-1) {
                frag[j] = bsize[j]-psize[i];
                alloc[i] = j;
                occup[j] = i;
                j = block;
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
