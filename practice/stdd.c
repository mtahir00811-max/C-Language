#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade; 
};

int main() {

    struct Student s[10]; 
    int i;
    for (i = 0; i < 10; i++) {
        printf("\nEnter data for student %d:\n", i + 1);

        printf("Name: ");
        // CORRECTED: Removed the redundant 's'
        scanf(" %[^\n]", s[i].name); 

        printf("Age: ");
        scanf("%d", &s[i].age);

        printf("Grade: ");
        scanf("%f", &s[i].grade);
    }
    
    printf("\n------ Student Data Entered ------\n");
    // Output Loop
      //int i;
    for (i = 0; i < 10; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Grade: %.2f\n", s[i].grade);
    }
    return 0;
}
