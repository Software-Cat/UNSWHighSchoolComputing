#pragma once

#include <stdbool.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1

typedef struct Board {
	int map[SIZE][SIZE];
	int lazerY;
	bool gameOver;
} Board;

void slide();

void print_board(Board* board);

// Initialization

void change_block(Board* board, int row, int column, int value);

void read_block(Board* board);

void read_blocks(Board* board);

// Commands

/// <summary>
/// Maps the correct functions according to command in args
/// </summary>
/// <param name="board">the board</param>
/// <param name="args">the arguments passed to the command</param>
void parse_command(Board* board, int args[]);

/// <summary>
/// Reads command from standard input
/// </summary>
/// <param name="board">the board</param>
void read_command(Board* board);

void move_lazer(Board* board, int dir);

void fire_lazer(Board* board);
