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

#include "ingredient.h"

#define ORDER_CUSTOMER_LENGTH 32
#define ORDER_PIZZA_LENGTH 32

//=============================================================================
// Enums
//=============================================================================

typedef enum stage_t {
    WAITING = 1,
    PREPARED = 2,
    COOKED = 3,
    DELIVERED = 4,
    COMPLETED = 5
} stage;

//=============================================================================
// Structs
//=============================================================================

typedef struct order_t {
    char customer[ORDER_CUSTOMER_LENGTH];
    char pizza[ORDER_PIZZA_LENGTH];
    double price;
    int time;
    struct order_t* next;
    ingredient* ingredients;
    stage stage;
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

void order_print_short(order* self, int order_number, bool selected);

/**
 * \brief append element at end of list
 * \param head reference to head of list
 * \param element the new element to append
 */
void order_append(order** head, order* element);

/**
 * \brief gets the nth element in the list
 * \param head reference to head of list
 * \param index the index of the element to get
 * \return pointer to nth element, null if out of bounds
 */
order* order_get(order* head, int index);

/**
 * \brief prints the enum in nice formatting
 * \param self the stage to print
 */
void stage_print(stage self);

/**
 * \brief sums the cost of the order and all ingredients
 * \return cost of order and ingredients
 */
double order_revenue(order* self);
