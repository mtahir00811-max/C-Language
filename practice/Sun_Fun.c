#include<stdio.h>

int sum ( int a, int b);//function prototype/Function Declaration

int main ()
{
	 int a ,b;
	 printf("Enter 1st number \n");
	 scanf("%d",&a);
	 printf("Enter 2nd number \n");
	 scanf("%d",&b);
	 
	 int s =sum(a,b);
	 printf("Sum is : %d",s);
	return 0;
}
//Function Definition
int sum ( int a, int b){
	return a + b;
}
