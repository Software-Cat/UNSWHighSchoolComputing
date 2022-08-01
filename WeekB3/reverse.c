// reverse.c
// Reverses input line
// Written by Bowen Wu on 01/08/22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char line[100];

	// Read line
	fgets(line, 100, stdin);

	// Put in reverse
	for (int i = strlen(line) - 1; i >= 0; --i) {
		const char current = line[i];
		if (current != '\n') {
			putchar(current);
		}
	}

	// Extra newline
	printf("\n");

	return 0;

}
