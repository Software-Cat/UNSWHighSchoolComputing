// fibonacci.c
// Prints the first 10 fibonacci numbers
// Written by Bowen Wu on 21/07/22

#include <stdio.h>
#include <stdlib.h>

int fibonacci(void) {
	// Initialise the number array and the first two elements
	int number[10] = { 0, 1 };

	// Calculate the sequence
	int index = 2;
	while (index < 10) {
		number[index] = number[index - 2] + number[index - 1];
		index++;
	}

	// Print the array
	index = 0;
	while (index < 10) {
		// Print the number element
		printf("%d\n", number[index]);

		// Advance the index
		index = index + 1;
	}

	return 0;
}
