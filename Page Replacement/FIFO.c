
#include<stdio.h>
#include<stdbool.h>

//checks whether a page already occupies a frame or not
bool check(int x, int arr[], int n) {
	for(int i=0; i<n; i++) {
		if(arr[i]==x) return true;
	}
	return false;
}

//name specifies!
void printContent(int page[], int n, int a) {
	printf("Page table when %d enters: ", a);
	for(int i=0; i<n; i++) {
		if(page[i]!=0) {
			printf("%d\t", page[i]);
		}
	}
	printf("\n");
}

int main() {
	int n; //holds size of page reference string
	printf("Enter size of page reference string: ");
	scanf("%d", &n);
	int a[n]; //the page reference string
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
	int j=0; //count page faults.
	for(int i=0; i<n; i++) {
		if(!check(a[i], page, size)) {
				page[j%size] = a[i];
				j++;
				printContent(page,size,a[i]);
		}
		else {
		    printContent(page,size,a[i]);
		}
	}
	printf("Number of page faults are %d\n", j);

    system("pause");
    return 0;
}
