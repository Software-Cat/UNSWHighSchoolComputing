//=============================================================================
// Slide
// slide.c
//
// This program was written by Bowen Wu
// on 20/07/22
//
// Version 1.0.0 (2021-03-08): Initial Assignment Release
//=============================================================================

#include "slide.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void slide() {
	// This line creates our 2D array called "map" and sets all
	// of the blocks in the map to EMPTY.
	int map[SIZE][SIZE] = { EMPTY };

	// This line creates our laser_y variable. The laser starts in the
	// middle of the map, at position 7.
	int laser_y = SIZE / 2;

	// TODO: Scan in the blocks.
	parse_blocks(map);

	// Validate the build instructions by printing the map
	print_map(map, laser_y);

	// Loop until the game is over
	bool gameOver = false;
	while (!gameOver) {
		// TODO: Scan in commands until EOF.
		// After each command is processed, you should call print_map.
	}
}

void print_map(int map[SIZE][SIZE], int laser_y) {
	// Print out the contents of the map array.
	// Also print out a > symbol to denote the current laser position.

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", (int)map[i][j]);
		}
		printf("\n");
	}
}

void parse_blocks(int map[SIZE][SIZE]) {
	// Build blocks in the map
	printf("How many blocks? ");
	// TODO: Scan in the number of blocks.
	int blockCount;
	scanf("%d", &blockCount);

	printf("Enter blocks:\n");
	for (int i = 0; i < blockCount; i++) {
		parse_block(map);
	}
}

void parse_block(int map[SIZE][SIZE]) {
	int row, column, value;
	scanf("%d %d %d", &row, &column, &value);

	map[row][column] = value;
}
