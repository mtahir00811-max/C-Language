#include <stdio.h>
#include <string.h>

#define ADMIN_PASS "admin123"  // Admin password

struct Student {
    int id;
    char name[50];
    float marks;
    float cgpa;
    char grade;
};

struct Student students[2];
int count = 0; // number of students

// Function to calculate CGPA and grade from marks
void calculateCGPAandGrade(int index) {
    students[index].cgpa = students[index].marks / 25.0; // simple example CGPA out of 4
    if(students[index].marks >= 90) students[index].grade = 'A';
    else if(students[index].marks >= 80) students[index].grade = 'B';
    else if(students[index].marks >= 70) students[index].grade = 'C';
    else if(students[index].marks >= 60) students[index].grade = 'D';
    else students[index].grade = 'F';
}

// Admin login
int adminLogin() {
    char pass[20];
    printf("Enter admin password: ");
    scanf("%s", pass);

    if(strcmp(pass, ADMIN_PASS) == 0) {
        printf("Login successful!\n\n");
        return 1;
    } else {
        printf("Wrong password!\n\n");
        return 0;
    }
}

// Add student (admin only)
void addStudent() {
    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]s", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    calculateCGPAandGrade(count);

    count++;
    printf("Student added successfully!\n\n");
}

// View all students (anyone)
void showStudents() {
    if(count == 0) {
        printf("No students found!\n\n");
        return;
    }

    printf("ID\tName\tMarks\tCGPA\tGrade\n");
    int i;
    for( i = 0; i < count; i++) {
        printf("%d\t%s\t%.1f\t%.2f\t%c\n",
               students[i].id,
               students[i].name,
               students[i].marks,
               students[i].cgpa,
               students[i].grade);
    }
    printf("\n");
}

// Update marks, CGPA, grade (admin only)
void updateStudent() {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    int i;
    for(i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);

            calculateCGPAandGrade(i);

            printf("Student updated successfully!\n\n");
            return;
        }
    }
    printf("Student not found!\n\n");
}

// Delete student (admin only)
void deleteStudent() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
int i;
    for(i = 0; i < count; i++) {
        if(students[i].id == id) {
            int j;
			for(j = i; j < count - 1; j++) {
                students[j] = students[j + 1]; // shift left
            }
            count--;
            printf("Student deleted successfully!\n\n");
            return;
        }
    }
    printf("Student not found!\n\n");
}

int main() {
    int choice;

    while(1) {
        printf("=== Student Management System ===\n");
        printf("1. View Students\n");
        printf("2. Admin Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            showStudents();
        }
        else if(choice == 2) {
            if(adminLogin()) {
                int adminChoice;
                while(1) {
                    printf("=== Admin Menu ===\n");
                    printf("1. Add Student\n");
                    printf("2. Update Marks/CGPA/Grade\n");
                    printf("3. Delete Student\n");
                    printf("4. Logout\n");
                    printf("Enter choice: ");
                    scanf("%d", &adminChoice);

                    if(adminChoice == 1)
                        addStudent();
                    else if(adminChoice == 2)
                        updateStudent();
                    else if(adminChoice == 3)
                        deleteStudent();
                    else if(adminChoice == 4)
                        break;
                    else
                        printf("Invalid option!\n\n");
                }
            }
        }
        else if(choice == 3) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice!\n\n");
        }
    }

    return 0;
}

