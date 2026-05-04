#include<stdio.h>
int main()
{
	
     int Num ;
     int *prt ;
     prt = &Num;
     printf("Enter any number \n");
     scanf("%d",&Num);
	 printf("You enter: %d\n",*prt);
	 printf("The address of   a number is %p : ",prt);
     
	 return 0;
}
