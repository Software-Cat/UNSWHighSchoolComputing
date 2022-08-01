//=============================================================================
// CS Pizzeria
// pizzeria.h
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#pragma once

#include "order.h"

#define PIZZERIA_NAME_LENGTH 32
#define PIZZERIA_OWNER_LENGTH 32

//=============================================================================
// Structs
//=============================================================================

typedef struct pizzeria_t {
	char name[PIZZERIA_NAME_LENGTH];
	char owner[PIZZERIA_OWNER_LENGTH];
	int selected_order;
	order* orders;
} pizzeria;

//=============================================================================
// Functions
//=============================================================================

/**
 * \brief instantiates a new pizzeria
 * \return pointer to new pizzeria
 */
pizzeria* pizzeria_new(void);

/**
 * \brief print all attributes of the pizzeria in neat formatting
 * \param self the pizzeria to print
 */
void pizzeria_print_all(pizzeria* self);

void pizzeria_print_header(pizzeria* self);

void pizzeria_print_footer(pizzeria* self);

void pizzeria_process_command(pizzeria* self, char* command);
