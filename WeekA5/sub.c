// sub.c
// Prints list of 0 with 1 at specified index
// Written by Bowen Wu on 21/07/22

#include <stdio.h>
#include <stdlib.h>

int devowel(void) {
    // Initialise the number array and the input
    int numbers[10] = {0};
    int input;

    // Print a prompt
    printf("Enter a number (1 to 10): ");

    // Get the user input, check validity and process
    scanf("%d", &input);
    if (input > 0 && input <= 10) {
        numbers[input - 1] = 1;
    }

    // Print the array
    for (int i = 0; i < 10; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    return 0;
}
