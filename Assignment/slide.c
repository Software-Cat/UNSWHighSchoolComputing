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

void slide() {
	// Initialize the board with empty blocks and the lazer in the middle
	Board board = { {EMPTY}, SIZE / 2 };

	// Read user defined blocks
	read_blocks(&board);

	// Loop until the game is over
	while (!board.gameOver) {
		print_board(&board);
		read_command(&board);
	}
}

void print_board(Board* board) {
	// For each row
	for (int i = 0; i < SIZE; i++) {
		// If the lazer is on the row, print it
		if (board->lazerY == i) {
			printf("> ");
		} else {
			printf("  ");
		}

		// Print the cells
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", board->map[i][j]);
		}

		printf("\n");
	}
}

void change_block(Board* board, int row, int column, int value) {
	board->map[row][column] = value;
}

void read_block(Board* board) {
	int row, column, value;
	scanf("%d %d %d", &row, &column, &value);

	// Make sure row and column are valid locations on map
	if (row >= SIZE || column >= SIZE) {
		return;
	}

	// Modify the block type at a single position
	change_block(board, row, column, value);
}

void read_blocks(Board* board) {
	// Ask for total blocks to scan
	int blockCount;
	printf("How many blocks? ");
	scanf("%d", &blockCount);

	// Scan blocks
	printf("Enter blocks:\n");
	for (int i = 0; i < blockCount; i++) {
		read_block(board);
	}
}

void parse_command(Board* board, int args[]) {
	switch (args[0]) {
	case 1:
		move_lazer(board, args[1]);
		break;
	case 2:
		fire_lazer(board);
		break;
	default:
		break;
	}
}

void read_command(Board* board) {
	// Scan all arguments until newline
	int i = 0;
	int args[100];
	char temp;
	do {
		int result = scanf("%d%c", &args[i], &temp);

		// Stop program if EOF is reached
		if (result < 1) {
			board->gameOver = true;
			break;
		}

		i++;
	} while (temp != '\n');

	// Execute the command read
	parse_command(board, args);
}

void move_lazer(Board* board, int dir) {
	// If dir is not up or down (1 or -1), ignore
	if (!(dir == 1 || dir == -1)) {
		return;
	}

	// Make sure move is in bounds of map
	if (!(board->lazerY < 0 || board->lazerY >= SIZE)) {
		// Move up or down 1 unit
		board->lazerY -= dir;
	}
}

void fire_lazer(Board* board) {
	// The number of blocks can the lazer destroy at max
	int energyLeft = 4;

	for (int i = 0; i < SIZE; i++) {
		// Destroy the block
		int currentBlock = board->map[board->lazerY][i];
		if (currentBlock != EMPTY) {
			// Destroy block
			board->map[board->lazerY][i] = EMPTY;

			// Spend energy
			energyLeft--;
		}

		// Stop destroying if no energy left
		if (energyLeft == 0) {
			break;
		}
	}
}
