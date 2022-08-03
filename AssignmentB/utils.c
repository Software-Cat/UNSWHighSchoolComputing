//=============================================================================
// CS Pizzeria
// utils.c
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=============================================================================
// Functions
//=============================================================================

void get_char_input(char* variable, const char* prompt, const int length) {
	// Ask user for input
	printf(prompt);

	// Get user input with fgets, not scanf
	fgets(variable, length, stdin);

	// Remove any special characters
	variable[strcspn(variable, "\r\n")] = 0;
}

void get_double_input(double* variable, const char* prompt) {
	// Get the user input
	printf(prompt);
	scanf("%lf", variable);

	// scanf leaves the \n character in the input buffer, so get rid of it.
	getchar();
}

void get_integer_input(int* variable, const char* prompt) {
	printf(prompt);
	scanf("%d", variable);

	// scanf leaves the \n character in the input buffer, so get rid of it.
	getchar();
}

void get_command_input(char* command, const char* prompt, const int length) {
	// Print list of commands
	printf("n - new order, s# - select order #, x - exit\n");

	get_char_input(command, prompt, length);
}

void print_divider() {
	printf("---------+---------+---------+---------+---------+---------+---------+---------+\n");
}
