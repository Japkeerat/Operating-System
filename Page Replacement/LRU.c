
#include <stdio.h>
#include<stdbool.h>

bool check(int x, int arr[], int n) {
	for(int i=0; i<n; i++) {
		if(arr[i]==x) return true;
	}
	return false;
}

void printContent(int page[], int n, int a) {
	printf("Page table when %d enters: ", a);
	for(int i=0; i<n; i++) {
		if(page[i]!=0) {
			printf("%d\t", page[i]);
		}
	}
	printf("\n");
}

void rep(int x, int page[], int n, bool t[]) {
    for(int i=0; i<n; i++) {
        if(page[i]==x) {
            t[i]=true;
        }
    }
}

int main() {
	int n;
	printf("Enter size of page reference string: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter page reference string, each element seperated with spaces: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int size;
	printf("Enter frame size: ");
	scanf("%d", &size);
	int page[size];
	for(int i=0; i<size; i++) {
		page[i] = 0;
	}
	int j=0;
	bool x[size];
	for(int i=0; i<n; i++) {
	    for(int k=0;k<size;k++) {
	        x[k] = false;
	    }
	    if(!check(a[i], page, size)) {
	        if(i>size-1) {
	            for(int k=i-1; k>=i-size+1; k--) {
	                rep(a[k],page,size,x);
	            }
	            for(int k=0; k<size; k++) {
	                if(!x[k]) {
	                    page[k] = a[i];
	                    k=size;
	                }
	            }
	        }
	        else {
	            page[i] = a[i];
	        }
	        j++;
	        printContent(page, size, a[i]);
	    }
	    else {
	        printContent(page,size,a[i]);
	    }
	}
	printf("Total number of page faults are %d\n", j);

	system("pause");
	return 0;
}
