#include <stdio.h>

void insertionsort(int a[], int n);

int main(){
	int i,n;
	printf("Enter number of elemets of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	insertionsort(a,n);
	printf("After sorting:\t");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

void insertionsort(int a[], int n){
	int i,j,index;
	for(i=0;i<n;i++){
		index = a[i];
		j = i;
		while((j>0) && (a[j-1] > index)){
			a[j] = a[j-1];
			j = j-1;
		}
		a[j] = index;
	}
}
