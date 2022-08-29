//=============================================================================
// CS Pizzeria
// ingredient.h
//
// This program was written by Bowen Wu
// on 04/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#pragma once

#define INGREDIENT_NAME_LENGTH 32

//=============================================================================
// Structs
//=============================================================================

typedef struct ingredient_t {
    char name[INGREDIENT_NAME_LENGTH];
    int amount;
    double price;
    struct ingredient_t* next;
} ingredient;

//=============================================================================
// Functions
//=============================================================================

/**
 * \brief instantiates a new ingredient
 * \return pointer to created ingredient
 */
ingredient* ingredient_new(void);

/**
 * \brief print the current ingredient node in the linked list
 * \param self the current ingredient
 */
void ingredient_print(ingredient* self);

/**
 * \brief append element at end of list
 * \param head reference to head of list
 * \param element the new element to append
 */
void ingredient_append(ingredient** head, ingredient* element);
