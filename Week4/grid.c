// grid.c
// A program that prints a n x n grid
// Written by Bowen Wu on 21/07/22

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf(" 0");
		}
		printf("\n");
	}

	return 0;
}
