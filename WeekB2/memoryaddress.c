// ============================================================================
// memoryaddress.c
// Find the memory address of the elements in an int array.
// Written by Bowen Wu on 25/07/22
// ============================================================================

#include "memoryaddress.h"
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
int memory(void) {
	// Initialise the data in the number array
	int number[] = {3, 5, 1, 7, 3, 9};
	int* address;

	// Loop through the array elements
	for (int i = 0; i < 6; i++) {
		// Get the memory address of the i'th element of the number array
		address = &number[i];

		// Print the address of each element in decimal and hexadecimal
		printf("Address = %u   %X\n", address, address);

		// Increment the index otherwise the loop will run for ever
		// If you need to terminate a 'forever' loop just hit Ctrl-C
	}

	return 0;
}
