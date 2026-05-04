#include<stdio.h>
void count_it() {
    static int count = 0; 
    count++; 
    printf("The number of times this function has been called is: %d\n",count);
}

// Main function to test the count_it() function
int main() {
    count_it(); 
    count_it(); 
    count_it();
    count_it(); 
    count_it();
    count_it();
    count_it();
    count_it();
    count_it();
    count_it();
    return 0;
}

