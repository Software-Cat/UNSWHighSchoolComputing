// numbers.c
// Prints out 1 to 10 using array
// Written by Bowen Wu on 21/07/22

#include <stdio.h>
#include <stdlib.h>

int numbers(void) {
	// Initialise the array
	int number[10] = { 0 };

	// Loop while testing the index and set each number element
	int index = 0;
	while (index < 10) {
		// Set the number element
		number[index] = index + 1;

		// Advance the index
		index++;
	}

	// Loop while testing the index and print each number element
	index = 0;
	while (index < 10) {
		// Print the number element
		printf("%d\n", number[index]);

		// Advance the index
		index = index + 1;
	}

	return 0;
}
