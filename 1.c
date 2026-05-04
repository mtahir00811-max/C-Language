#include <stdio.h>

int main() {
    FILE *fp;
    char line[100];
     

    
    fp = fopen("D:\\1st semester uet mardan\\Programming Fundamental Lab\\lab14\\student.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Data from file:\n\n");

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}

