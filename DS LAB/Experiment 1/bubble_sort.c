#include <stdio.h>

void bubblesort(int a[], int n);

int main(){
	int i,n;
	printf("Enter number of elemets of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubblesort(a,n);
	printf("After sorting:\t");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

void bubblesort(int a[], int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
	
