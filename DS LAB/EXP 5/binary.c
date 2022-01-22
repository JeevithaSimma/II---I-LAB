#include <stdio.h>

int binary(int a[],int n,int l,int h,int key);

int main(){
	int n,i,pos,key,l,h;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the value of key: ");
	scanf("%d",&key);
	pos = binary(a,n,0,n-1,key);
	if(pos>=0){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
	return 0;
}

int binary(int a[],int n,int l,int h, int key){
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(key == a[mid]){
			return mid+1;
		}
		else if(key > a[mid]){
			l = mid + 1;
		}
		else{
			h = mid - 1;
		}
	}
	return -1;
	return 0;	
}

