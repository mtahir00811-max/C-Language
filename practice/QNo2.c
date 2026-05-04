#include<stdio.h>
int main (){

int a = 10;
int *b = &a ;
printf("Address via variable is %d \n ",&a);
printf("Address via pointer is %d \n ",b);
return 0;
}
