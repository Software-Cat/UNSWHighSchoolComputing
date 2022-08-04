#include <stdio.h>

void is_leap_year() {
    int year;
    int isLeap = 0;

    printf("Enter year: ");
    scanf("%d", &year);

    if (year % 4 != 0) {
        isLeap = 0;
    } else if (year % 100 != 0) {
        isLeap = 1;
    } else if (year % 400 != 0) {
        isLeap = 0;
    } else {
        isLeap = 1;
    }

    if (isLeap) {
        printf("%d is a leap year.", year);
    } else {
        printf("%d is not a leap year.", year);
    }
    printf("\n");
}
