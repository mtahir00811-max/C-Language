#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define PASSWORD "king1234"
#define PASS_LEN 8
// struct for student data
struct student
{
   char name[20];
   char reg[15];
   int marks[7];
   //int total_marks;
   double cgpa_all[7];
   double total_gpa;
};
void get_password(char arr[]);
void print_student(int index);
void clear_input();
void add_student();
void view_all();
int total_marks(int index);
// void del_student();
// void update_student();
void search_student();
 void name();
 void map_marks(int mrk[]);
// void reg();
void cgpa();
void show_student();
int get_valid_int(const char *prompt, int min, int max);


struct student *s=NULL;
int count=0;
size_t max_student = 0;
// function for adding and deleting data of the students


void admin(){
  while(1)
  { 
    char pass[9];
    get_password(pass);
    if(!strcmp(pass,PASSWORD))
    {
    break; 
    }
    printf("Invalid password! Try again\n");
  }
      while(1)
      {
      printf("\t\t==(1)==Add Students Data====\n");
      printf("\t\t==(2)==Delete Students Data====\n");
      printf("\t\t==(3)==Update Students Data====\n");
      printf("\t\t==(4)==Quit====\n");

      int choose_1=get_valid_int("\n\t\t====Select a choice====\n",1,4);

      switch (choose_1)
      {
      case 1:
        add_student();
        break;
      case 2:
       // del_student();
        break;
      case 3:
       // update_student();
        break; 
      case 4:
         break;   
      }
      }   
}
void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// function for getting password from the user and checking the password from the user 
  void get_password(char arr[])
  {
    
    char buffer[100];
    int run=1;

    while(run)
    {
      printf("Enter 8-characters password\n");

      if(!fgets(buffer,sizeof(buffer),stdin))
      {
        printf("Error reading input\n");
        continue;
      }
      buffer[strcspn(buffer,"\n")]='\0';

      int len=strlen(buffer);

      if(len<PASS_LEN)
      {
        printf("password too short must be 8-characters\n");
      }
      else if(len>PASS_LEN)
      {
        printf("password too long must be 8-characters\n");
      }
      else
      {
        strcpy(arr,buffer);
        run=0;
      }
    }
  }
  // function for checking the user input
  int get_valid_int(const char *prompt, int min, int max) {
    char buffer[100];
    int value;

    while (1) {
        printf("%s", prompt);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("\n\t\tError reading input!\n\t\t\tTry again.\n");
            continue;
        }

         // Check if input was too long (no newline found)
        if (strchr(buffer, '\n') == NULL) {
            // Input too long: truncate at 99 chars
            buffer[99] = '\0'; // force null-termination
            // Clear remaining characters from stdin
            clear_input();
            printf("Input too long. Only first 99 characters are considered.\n");
        } else {
            // Remove newline if present
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Check that all characters are digits
        int valid = 1;
        int i ;
        for ( i = 0; buffer[i]; i++) {
            if (!isdigit(buffer[i])) {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("\n\t\tInvalid input!\n\t\t\tEnter digits only.\n");
            continue;
        }

        // Convert string to integer
        value = atoi(buffer);

        // Check limits
        if (value < min || value > max) {
            printf("\n\t\tValue must be between %d and %d.\n", min, max);
            continue;
        }

        return value; // valid input
    }
}
// // function to add student data
 void add_student(){
  int flag1 =1;

  while(flag1)
   {
     max_student=get_valid_int("For How much student you want to Enter the data\n",1,1000);
     break;
   }
  //free old data when reallocating again
  if (s!=NULL)
   {
     free(s);
     s=NULL;
     count=0;
   }
  // memory allocation dynamically
  s=malloc(max_student*sizeof(struct student));

  if(s==NULL)
   {
     printf("Memory Allocation Failed!\n");
     return ;
   }
  printf("\t\t==Enter Students Data==\n");

  size_t i;
  for (i=0;i<max_student;i++)
   {
    printf("==Student (%d)==\n",i+1);

    if(count>=max_student)
     {
      printf("Student Limit Reached!\n");
      break;
     }
      char buffer2[100];
       while(1)
      {
       //name of each student
       printf("\nEnter name of student\n");
       if (!fgets(buffer2,sizeof(buffer2),stdin))
       {
        printf("Reading input error!\n");
        continue;
       }
       buffer2[strcspn(buffer2,"\n")]='\0';

        if (buffer2[0] == '\0') {
        printf("Name cannot be empty\n");
        continue;
        }
       int valid2=1;
       int j ;
       for(j=0;buffer2[j];j++)
       {
        if(!isalpha((unsigned char)buffer2[j]) && buffer2[j] != ' ')
         {
          printf("\n\t\tInvalid Input ! \n");
          valid2=0;
          break;
         }
        }
        if(!valid2)
         {
           printf("\t\t\tEnter letters only\n");
           continue;
         }
         break; 
        }

    strcpy(s[i].name,buffer2);

    // registration number of each student
    char buffer3[100];
    while(1){ 
    printf("==Registration Number==\n");

    if (!fgets(buffer3,sizeof(buffer3),stdin))
     {
      printf("\n\t\tReading input error!\n");
      continue;
     }
    buffer3[strcspn(buffer3,"\n")]='\0';

    int letters=0,digits=0,invalid=0;

    int z; 
    for(z=0;buffer3[z];z++)
    {
      if(isalpha((unsigned char)buffer3[z]))
      {
        letters++;
      }else if (isdigit((unsigned char)buffer3[z]))
      {
        digits++;
      }else{
        invalid=1;
        break;
      }
    }
     if (invalid) 
     {
        printf("\n\t\tInvalid character detected! Only letters and digits allowed.\n");
        continue;
      }
      if (letters == 0 || digits == 0)
       {
          printf("\n\t\tRegistration must contain both letters and digits!\n");
          continue;
        }
     strcpy(s[i].reg,buffer3);
     break;
  }

    printf("==Marks==\n");
    // each student marks
    size_t j;
    for (j=0;j<sizeof(s[i].marks)/sizeof(s[i].marks[0]);j++)
     {
      switch(j)
       {
        case 0:
          s[i].marks[j]=get_valid_int("\t\t==Programming Fundamental Theory==\n",1,100);
        break; 
        case 1:
        s[i].marks[j]=get_valid_int("\t\t==Programming Fundamental Lab==\n",1,100);
        break; 
        case 2:
        s[i].marks[j]=get_valid_int("\t\t==ICT Theory==\n",1,100);
        break; 
        case 3:
        s[i].marks[j]=get_valid_int("\t\t==ICT Lab==\n",1,100);
        break; 
        case 4:
        s[i].marks[j]=get_valid_int("\t\t==Islamic Studies==\n",1,100);
        break; 
        case 5:
        s[i].marks[j]=get_valid_int("\t\t==Functional English==\n",1,100);
        break; 
        case 6:
        s[i].marks[j]=get_valid_int("\t\t==PRE CALCULUS==\n",1,100);
        break; 
       }
      }
  count++;
  }
  count=max_student;
  cgpa();
 }
  
 //print data
 void print_student(int index)
 {  
    // print name
    printf("\t%s\n",s[index].name);
    // print registration number
    printf("\t%s\n",s[index].reg);
    //print marks
    int j;
    for (j =0;j<sizeof(s[0].marks)/sizeof(s[0].marks[0]);j++){
    switch(j)
    {
    case 0:
    printf("\t\tProgramming Fundamental Theory =%d \t GPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j]);
    break; 
    case 1:
    printf("\t\tProgramming Fundamental Lab    =%d \t GPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j]);
    break; 
    case 2:
    printf("\t\tICT Theory                     =%d \t GPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j]);
    break; 
    case 3:
    printf("\t\tICT LAB                        =%d \t GPA = %.1f \tCGPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j],s[index].total_gpa);
    break; 
    case 4:
    printf("\t\tIslamic Studies                =%d \t GPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j]);
    break; 
    case 5:
    printf("\t\tFunctional English             =%d \t GPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j]);
    break; 
    case 6:
    printf("\t\tPRE CALCULUS                   =%d \t GPA = %.1f\n",s[index].marks[j],s[index].cgpa_all[j]);
    printf("\n");
    break; 
    }
  }
  // print total marks
  int res2=total_marks(index);
  printf("\t\tTotal Marks                    =%d\n",res2);
 }
// function for viewing student data
void view_student(){
     if(count==0){
        printf("Data Not Found!\n");
     }else{
        show_student();
     }
}
// // function for showing student data
 void show_student(){
  int chase=0;
  while(chase != 3)
  {
  printf("\t\t==(1)==View ALL Student Data====\n");
  printf("\t\t==(2)==Search student====\n");
  printf("\t\t==(3)==Quit====\n");
   printf("\t\t==Select a choice====\n");
  scanf("%d",&chase);
  switch(chase)
  {
    case 1:
      view_all();
      break;
    case 2:
      search_student();
      break;
  }
  }
 }

 //view all student data
 void view_all(){
 	int i;
  for(i=0;i<count;i++)
  {
    print_student(i);
  } 
}
 // Search student by name
  void search_student(){
   int search;
   while(search!=3){
   printf("\t\t==(1)Search By Name====\n");
   printf("\t\t==(2)BY Registration Number====\n");
   printf("\t\t==Select a choice====\n");
   scanf("%d",&search);

   switch(search)
   {
   case 1:
       name();
      break;}}}
//   case 2:
//       reg();
//       break;    
//    }
//   }
// }
void name(){
  char named[20];
  printf("Enter The name\n");
  clear_input();
  fgets(named,sizeof(named),stdin);
  named[strcspn(named,"\n")]='\0';
   // mistakes and bugs
   int flag=0;
   int k;
  for(k=0;k<count;k++)
  {
    if(!strcmp(named,s[k].name))
    {
    printf("data found!\n");
    print_student(k);
    flag = 1;
    }
 }
  if(!flag)
  {
    printf("No Name Found!\n");
  }
}
// total marks

int total_marks(int index){
  int total_mrk=0;
  int i;
  for(i=0;i<sizeof(s[0].marks)/sizeof(s[0].marks[0]);i++)
  {
    total_mrk+=s[index].marks[i];
  }
 return total_mrk;
}
// for gpa calculation
void cgpa()
{  
   int count = sizeof(s[0].marks) / sizeof(s[0].marks[0]);
   int gpa_count = sizeof(s[0].cgpa_all) / sizeof(s[0].cgpa_all[0]);
   int count_student=max_student;
   int diff=0;
   // loops for finding the highest marks
   //outer loop iterate over each subject
   int f;
   for(f=0;f<count;f++)
   {
    int highest_marks=s[0].marks[f];
    // inner loop go through each student and get the highest marks
    int g;
    for(g=0;g<count_student;g++)
    {
      if(s[g].marks[f]>highest_marks)
      {
       highest_marks=s[g].marks[f];
      }
    }
    if(highest_marks<100)
    {
      diff=100-highest_marks;
      // loop for setting all the same highest marks to 100
      int g;
      for(g=0;g<count_student;g++)
      {
        if(highest_marks==s[g].marks[f])
        {
         s[g].marks[f]=100;
        }
      }
    }
    int q;
    for(q=0;q<count_student;g++)
    {
      if(s[q].marks[f]!=100)
      {
        s[q].marks[f]+=diff;
      }
    }
  }
  // now criteria of cgpa
  //outer loop for checking all the subject
  int k;
  for(k=0;k<gpa_count;k++)
  {
  	int m;
    for(m=0;m<count_student;m++)
    {
      if(s[m].marks[k]>=95 && s[m].marks[k]<=100)
      {
        s[m].cgpa_all[k]=4.0;
      }
      else if(s[m].marks[k]<95 && s[m].marks[k]>=90)
      {
       s[m].cgpa_all[k]=3.5; 
      }
      else if(s[m].marks[k]<90 && s[m].marks[k]>=85)
      {
       s[m].cgpa_all[k]=3.0; 
      }
      else if(s[m].marks[k]<85 && s[m].marks[k]>=80)
      {
       s[m].cgpa_all[k]=2.5; 
      }
      else if(s[m].marks[k]<80 && s[m].marks[k]>=75)
      {
       s[m].cgpa_all[k]=2.0; 
      }
      else if(s[m].marks[k]<75 && s[m].marks[k]>=70)
      {
       s[m].cgpa_all[k]=1.5; 
      }
      else if(s[m].marks[k]<70 && s[m].marks[k]>=65)
      {
       s[m].cgpa_all[k]=1.0; 
      }
      else if(s[m].marks[k]<65 && s[m].marks[k]>=60)
      {
       s[m].cgpa_all[k]=0.5; 
      }
      else
      {
        s[m].cgpa_all[k]=0.0; 
      }
    }
  }

  // now totaling the gpa
  int i;
  for(i=0;i<count_student;i++)
  {
    double tot_gpa=0;
    int j;
    for(j=0;j<gpa_count;j++)
    {
      tot_gpa+=s[i].cgpa_all[j];
    }
    s[i].total_gpa=tot_gpa/7;
  }
}
 

// main function
int main() { 
    int choice=0;
    char input[3];
     // for getting the user choice
    int running=1;
    while (running){
    printf("\t\t=======Menu====\n");
    printf("\t\t==(1)==View Student====\n");
    printf("\t\t==(2)==Admin====\n");
    printf("\t\t==(3)==Exit====\n");
    printf("\n\t\t==Select a Choice====\n");
    
    if(!fgets(input,sizeof(input),stdin))
    {
      printf("Error reading input\n");
      continue;
    }
    if (input[strlen(input)-1] != '\n')
    {
    clear_input();
    }
    int valid=1;
    input[strcspn(input,"\n")]='\0';
    int i;
    for(i=0;input[i];i++)
    {
      if(!isdigit(input[i]))
      {
        valid = 0;
        break;
      }
    }
    if(!valid)
    {
      printf("Invalid Input! try again\n");
      continue;
    }
    
    choice=atoi(input);

    if(choice<1 || choice > 3)
    {
      printf("Invalid Input! Try Again\n");
      continue;
    }
    switch(choice)
    {
        case 1:
        view_student();
        break;
        case 2:
        admin();
        break; 
        case 3:
        printf("==Good Bye==\n");
        running=0;
        break;    
    }
    }
    
return 0;
}
