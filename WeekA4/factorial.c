// factorial.c
// A program that calculates factorial values
// Written by Bowen Wu on 21/07/22

#include "factorial.h"

#include <stdio.h>
#include <stdlib.h>

int factorial(void) {
    // Declare the variables and initialise
    int input = 0;
    int counter = 1;
    int factorial = 1;      // Note: 0! = 1

    // Get the user input
    printf("Enter value: ");
    scanf("%d", &input);

    // Loop while testing the counter against the user input
    while (counter <= input) {
        // Calculate the factorial value
        factorial *= counter;

        // Advance the counter
        counter++;
    }

    // Special 0 case
    if (input == 0) {
        factorial = 1;
    }

    // Print the answer
    // Note: the printf() function can take multpile arguments using multiple '%d' formats
    printf("%d! = %d\n", input, factorial);

    return 0;
}
