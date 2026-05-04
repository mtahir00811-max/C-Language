#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Name: Muhammad Tahir\n");
    fprintf(fp, "Registration Number: 25MDBCS798\n");
    fprintf(fp, "Class Number: 12\n");
    fprintf(fp, "Department: Computer Science\n");
    fclose(fp);
    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char ch;
    printf("\nContents of student.txt:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    fp = fopen("NAMES.DAT", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char *names[5] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    int i;
    for (i = 0; i < 5; i++) {
        fprintf(fp, "%s\n", names[i]);
    }

    fclose(fp);

    printf("\nFive names written to NAMES.DAT successfully.\n");

    return 0;
}

