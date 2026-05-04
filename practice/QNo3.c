#include<stdio.h>
int main(){
	int size ;
	printf("Enter the size of an Array \n");
	scanf("%d",&size);
	
	int arr[size];
	int i ;
	int sum = 0;
	for (i=0 ; i<size ;i++){
		printf("Size of an Array %d",i+1);
		scanf("%d",&arr[i]);
		
		int k ;
		for(k=0 ; k<size ; k++ )
		   sum = sum + arr[i];
		   
		   
		printf("%d",arr);
	}
	return 0;
}
