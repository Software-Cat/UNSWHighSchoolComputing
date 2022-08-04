// ============================================================================
// bitsbytes.c
// Examine the memory used to store an integer
// Written by Bowen Wu on 25/07/22
// ============================================================================

#include "bitsbytes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ============================================================================
void printmemory(int* number) {

    // Print a starting marker
    printf("|");

    // Unsigned char are single bytes with values 0 to 255
    // We can examine memory one byte at a time
    // Remember that (int *number) passes an address not a value
    unsigned char* address = (unsigned char*) number;

    // Loop through the 4 bytes used to store an integer
    // TODO: create a loop for exactly 4 cycles
    for (int i = 0; i < 4; ++i) {

        // Set a byte equal to the data stored at the address in 'memory'
        unsigned char byte = *address;
        // Set the bit to 1 ie. the 0'th bit as 2^0 = 1
        unsigned char bit = 1;

        // loop through the 8 bits 1,2,4, .. etc
        // TODO: create a loop for exactly 8 cycles
        for (int j = 0; j < 8; ++j) {

            // Use a bitwise operator for AND to test a specific bit for '0' or '1'
            if ((byte & bit) == 0) {
                printf("0");
            } else {
                printf("1");
            }

            // Increment the bit and the loop counter
            bit = bit * 2;
            // TODO: increment loop counter
        }

        // Print an end-of-byte marker
        printf("|");

        // Increment the memory address and the loop counter
        // The compiler knows the size of an unsigned char is exactly 1 byte
        address++;
        // TODO: increment loop counter
    }

    // Print some white space to finish
    printf("\n\n");
}

// ============================================================================
int bitsbytes(void) {

    // Allocate memory
    // The char type ia one unsigned byte 0 to 255
    int number = 0;

    while (number != 7) {
        // Scan a number
        // Include a prompt
        // Remember to provide the address of the variable using '&'
        printf("Enter an integer from -2,147,483,648 to 2,147,483,647 (Enter 7 to terminate)\n");
        // TODO: add scanf() for an integer
        scanf("%d", &number);

        // TODO: print the number in "%12d |" format
        printf("           %12d ", number);
        // TODO: call the function printmemory() to print out the bits
        printmemory(&number);
    }

    return 0;
}
