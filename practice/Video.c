#include <stdio.h>

struct VideoTape {
    char title[50];
    int length;// in minutes
    float cost;
    float rentalPrice;
    char releaseDate[20];
};

int main() {
    struct VideoTape t1 = {"Money Hiest", 180, 1000.0, 200.0, "04-05-2011"};
    struct VideoTape t2 = {"Stranger thing", 148, 1200.0, 180.0, "16-07-2010"};
    struct VideoTape t3 = {"Avenger", 136, 1000.0, 150.0, "31-03-1999"};

    printf("----- Video Tape Inventory -----\n");
    printf("\n--Tape01--\n");
    printf("Title: %s\n", t1.title);
    printf("Length: %d minutes\n", t1.length);
    printf("Cost: %.2f\n", t1.cost);
    printf("Rental Price: %.2f\n", t1.rentalPrice);
    printf("Release Date: %s\n", t1.releaseDate);

    printf("\n--Tape02--\n");
    printf("Title: %s\n", t2.title);
    printf("Length: %d minutes\n", t2.length);
    printf("Cost: %.2f\n", t2.cost);
    printf("Rental Price: %.2f\n", t2.rentalPrice);
    printf("Release Date: %s\n", t2.releaseDate);

    printf("\n--Tape03--\n");
    printf("Title: %s\n", t3.title);
    printf("Length: %d minutes\n", t3.length);
    printf("Cost: %.2f\n", t3.cost);
    printf("Rental Price: %.2f\n", t3.rentalPrice);
    printf("Release Date: %s\n", t3.releaseDate);

    return 0;
}
