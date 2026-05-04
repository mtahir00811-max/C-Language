#include <stdio.h>

int main() {
    FILE *fp;            
    char name[5][50];    
    int i;
    printf("Enter 5 names:\n");
    for(i = 0; i < 5; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", name[i]);   
    }
    fp = fopen("NAMES.DAT", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for(i = 0; i < 5; i++) {
        fprintf(fp, "%s\n", name[i]);  // Write each name on a new line
    }

    fclose(fp);  // Close file

    printf("Names written to NAMES.DAT successfully!\n");

    return 0;
}

