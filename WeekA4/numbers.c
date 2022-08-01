// lab1.c
// A program that prints 1 to 10
// Written by Bowen Wu on 21/07/22

#include <stdio.h>
#include <stdlib.h>

int numbers(void) {
	// Initialise the counter
	int counter = 1;

	// Loop while testing the counter
	while (counter <= 10) {
		// Print the number
		printf("%d\n", counter);

		// Advance the counter
		counter++;
	}

	return 0;
}
