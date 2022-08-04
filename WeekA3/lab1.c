#include <stdio.h>
#include <stdlib.h>

void negative(void) {
    int number;

    // Scan for a number
    // Remember to provide the address of the variable using '&'
    scanf("%d", &number);

    // Test for negative numbers and report
    if (number > 0) {
        printf("You have entered a positive number.");
    } else if (number < 0) {
        printf("Don't be so negative!");
    } else {
        printf("You have entered zero.");
    }

    printf("\n");
}
