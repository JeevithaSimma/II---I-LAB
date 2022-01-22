#include <stdio.h>

int linear(int a[], int key,int n);

int main(){
	int n,i,pos,key;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements of array:\t");
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&key);
	pos = linear(a,key,n);
	if(pos >= 0){
		printf("Elements found at position %d  ",pos);
	}
	else{
		printf("Element not found");
	}
}

int linear(int a[],int key,int n){
	int i;
	for(i=0;i<n;i++){
		if(key == a[i]){
			return i;
		}
	}
	return -1;
}

