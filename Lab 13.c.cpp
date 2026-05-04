*#include<stdio.h>
#include<string.h>
#include <stdlib.h>
// structure for the friends information
struct friends
{
    char name[20];
    char address[100];
    char number[20];
}; 
// function for comparing the name  
int compare(const void *a,const void *b)
{
    const struct friends *f1 = a;
    const struct friends *f2 = b;

    return strcmp(f1->name, f2->name);
}


int main() { 
    int size;
    printf("For how many friends YOu want to enter Data:\n");
    scanf("%d",&size);
    getchar();
    // stuct pointer
    struct friends *fellow;
    // dynamically allocated memory
    fellow=malloc(size*sizeof(struct friends));
    // if memory allocation failed
    if(fellow==NULL)
    {
        printf("Memory Allocation failed\n");
        return 1;
    }
   
    int length=size;
    int i=0;
    // getting input from the user
    while(i<length)
    {   
        
        printf("\nFriend Number ==(%d)== Data\n",i+1);
        printf("\nEnter your Friends Name:\n");
        fgets(fellow[i].name,sizeof(fellow[i].name),stdin);
        fellow[i].name[strcspn(fellow[i].name,"\n")]='\0';

        printf("Enter your friend address:\n");
        fgets(fellow[i].address,sizeof(fellow[i].address),stdin);
        fellow[i].address[strcspn(fellow[i].address,"\n")]='\0';

        printf("Enter your friend Phone Number:\n");
        fgets(fellow[i].number,sizeof(fellow[i].number),stdin);
        fellow[i].number[strcspn(fellow[i].number,"\n")]='\0';
        i++;
    }

    // name and address
    // for sorting we use built in function of c name qsort
    qsort(fellow,length,sizeof(struct friends),compare);
    int j=0;
    printf("\t\tprinting in Alphabetically sorted order\n");
    printf("\t\tName  && Addresses\n");

    while(j<length)
    {   printf("\n\t\tFriend Number %d Data \n",j+1);
        printf("\n\t\tName = %s\n",fellow[j].name);
        printf("\t\tAddress = %s\n",fellow[j].address);
        j++;
    }
    //for name and phone number
    int k=0;
    printf("Name  && Phone Number\n");
    while(k<length)
    {
        printf("\n\t\tFriend Number %d Data \n",k+1);
        printf("\n\t\tName = %s\n",fellow[k].name);
        printf("\t\tPhone Number = %s\n",fellow[k].number);
        k++;
    }
    free(fellow);
return 0;
}*
