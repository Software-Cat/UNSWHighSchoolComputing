//=============================================================================
// CS Pizzeria
// pizzeria.c
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#include "pizzeria.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

//=============================================================================
// Functions
//=============================================================================

pizzeria* pizzeria_new() {
    // Allocate memory for the pizzeria
    // pizzeria* new_pizzeria = malloc(sizeof(struct pizzeria_t));
    pizzeria* new_pizzeria = malloc(sizeof(pizzeria));

    // Use helper functions to get the information from the user
    // Don't forget to all the fields to an initial value. The NULL
    // value has a special meaning in some of the other helper functions.
    get_char_input(new_pizzeria->name, "Pizzeria name: ", PIZZERIA_NAME_LENGTH);
    get_char_input(new_pizzeria->owner, "Owner's name: ", PIZZERIA_OWNER_LENGTH);
    new_pizzeria->selected_order = 1;
    new_pizzeria->orders = NULL;

    return new_pizzeria;
}

void pizzeria_print_all(pizzeria* self) {
    // TODO: Make a call to print the header of the order book
    pizzeria_print_header(self);

    // Use a pointer to walk through the orders
    order* current_order = self->orders;
    int i = 1;

    // TODO: Create a loop to print each order, testing for a NULL order
    // and limiting the number of order so the screen does not overflow
    // Advance the_order pointer and the number with each iteration of the loop
    while (current_order != NULL) {
        order_print(current_order, i, self->selected_order == i);
        current_order = current_order->next;
        i++;
    }

    // TODO: Make a call to print the footer of the order book
    pizzeria_print_footer(self);
}

void pizzeria_print_header(pizzeria* self) {
    print_divider();

    printf("Orders for %s owned by %s\n", self->name, self->owner);

    printf("#   Customer                  Pizza               Price     Time      \n");
    print_divider();
}

void pizzeria_print_footer(pizzeria* self) {
    print_divider();
}

void pizzeria_process_command(pizzeria* self, char* command) {
    // NOTE: the new order code below is a bit tricky.  Study it to get
    // an understanding on how it works.  Next time you will have to
    // figure it out for yourself
    switch (command[0]) {
    case 'n': {
        order_append(&self->orders, order_new());
        break;
    }
    case 's': {
        // TODO: Get the number of the selected order and set the field in pizzeria.
        // TODO: Check for order number out of bounds
        int order_number = strtol(&command[1], NULL, 10);
        self->selected_order = order_number;
        break;
    }
    default: ;
    }
}
