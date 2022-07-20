#pragma once

#define SIZE 15
#define EMPTY 0
#define STONE 1

void slide();

void print_map(int* map[SIZE][SIZE], int laser_y);

void parse_block(int* map[SIZE][SIZE]);

void parse_blocks(int* map[SIZE][SIZE]);