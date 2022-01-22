#include <stdio.h>

int rbinary(int a[], int n,int l,int h, int key);

int main(){
	int n,i,key,pos;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the value of key: ");
	scanf("%d",&key);
	pos = rbinary(a,n,0,n-1,key);
	if(pos>=0){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
	return 0;
}


int rbinary(int a[], int n,int l,int h, int key){
	int mid;
	if(l<=h){
		mid = (l+h)/2;
		if(key == a[mid]){
			return mid+1;
			}
		else if(key > a[mid]){
			return rbinary(a,n,mid+1,h,key);
		}
		else{
			return rbinary(a,n,l,mid-1,key);
		}
	}
	return -1;
}

