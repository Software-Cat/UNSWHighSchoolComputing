//=============================================================================
// CS Pizzeria
// order.h
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#pragma once

#include <stdbool.h>

#define ORDER_CUSTOMER_LENGTH 32
#define ORDER_PIZZA_LENGTH 32

//=============================================================================
// Structs
//=============================================================================

typedef struct order_t {
	char customer[ORDER_CUSTOMER_LENGTH];
	char pizza[ORDER_PIZZA_LENGTH];
	double price;
	int time;
	struct order_t* next;
} order;

//=============================================================================
// Functions
//=============================================================================

/**
 * \brief instantiates a new order
 * \return pointer to created order
 */
order* order_new(void);

/**
 * \brief print the current order node in the linked list
 * \param self the current order
 * \param order_number the index of the order in the list
 * \param selected whether the current order is selected
 */
void order_print(order* self, int order_number, bool selected);

/**
 * \brief append element at end of list
 * \param head reference to head of list
 * \param element the new element to append
 */
void order_append(order** head, order* element);
