//=============================================================================
// CS Pizzeria
// utils.h
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#pragma once

//=============================================================================
// Functions
//=============================================================================

/**
 * \brief get user string input and write to variable
 * \param variable the variable to write to
 * \param prompt inquiry question to ask user
 * \param length length of input to read
 */
void get_char_input(char* variable, const char* prompt, int length);

/**
 * \brief get user double input and write to variable
 * \param variable the variable to write to
 * \param prompt inquiry question to ask user
 */
void get_double_input(double* variable, const char* prompt);

/**
 * \brief get user int input and write to variable
 * \param variable the variable to write to
 * \param prompt inquiry question to ask user
 */
void get_integer_input(int* variable, const char* prompt);

void get_command_input(char* command, const char* prompt, int length);

void print_divider(void);

void print_short_divider(void);
