#include <stdio.h>

void selectionsort(int a[], int n);

int main(){
	int i,n;
	printf("Enter number of elemets of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	selectionsort(a,n);
	printf("After sorting:\t");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

void selectionsort(int a[], int n){
	int i,j,min,temp;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[min]){
				min = j;
			}
			
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
	
	
