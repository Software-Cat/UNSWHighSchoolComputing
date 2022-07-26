//=============================================================================
// CS Pizzeria
// ingredient.c
//
// This program was written by Bowen Wu
// on 04/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#include "ingredient.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

//=============================================================================
// Functions
//=============================================================================

ingredient* ingredient_new() {
    // Allocate memory for the order
    ingredient* new_ingredient = malloc(sizeof(ingredient));

    // Use helper functions to get the information from the user
    // Don't forget to set all the fields to an initial value. The NULL
    // value has a special meaning in some other helper functions.
    get_char_input(new_ingredient->name, "Name: ", INGREDIENT_NAME_LENGTH);
    get_integer_input(&new_ingredient->amount, "Amount: ");
    get_double_input(&new_ingredient->price, "Cost: ");
    new_ingredient->next = NULL;

    return new_ingredient;
}

void ingredient_print(ingredient* self) {
    // Print whitespace (26 chars)
    printf("                               ");

    // Print amount (4 chars)
    // TODO: Fix weird trick here to limit to one digit with modulus
    printf("+ %d ", self->amount % 10);

    // Print ingredient name (15 chars)
    printf("%-15s", self->name);

    // Print price (10 chars)
    printf("$%-9.2f", self->price);

    // Newline
    printf("\n");
}

void ingredient_append(ingredient** head, ingredient* element) {
    // Ensure the new node is the last node
    element->next = NULL;

    // If list is empty, make new node head
    if (*head == NULL) {
        *head = element;
        return;
    }

    // Else traverse to last node
    ingredient* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Append element as next of last node
    last->next = element;
}
