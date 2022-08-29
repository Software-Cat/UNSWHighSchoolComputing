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
    new_pizzeria->selected_order = NULL;
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
        // If the order is not complete
        if (!(current_order->stage == COMPLETED)) {
            order_print(current_order, i, self->selected_order == current_order);
        }
        current_order = current_order->next;
        i++;
    }

    // TODO: Make a call to print the footer of the order book
    pizzeria_print_footer(self);
}

void pizzeria_print_header(pizzeria* self) {
    print_divider();

    printf("Orders for %s owned by %s\n", self->name, self->owner);

    printf("#   Customer                  Pizza               Price     Time      Tracking\n");
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
    // New order
    case 'n': {
        order* new_order = order_new();
        order_append(&self->orders, new_order);
        self->selected_order = new_order;
        break;
    }
    // Select order
    case 's': {
        // TODO: Get the number of the selected order and set the field in pizzeria.
        // TODO: Check for order number out of bounds
        int order_index = strtol(&command[1], NULL, 10) - 1;
        pizzeria_select_order(self, order_index);
        break;
    }
    // Add ingredient
    case 'i': {
        if (self->selected_order != NULL) {
            ingredient_append(&self->selected_order->ingredients, ingredient_new());
        }
        break;
    }
    // Tracking
    case 't': {
        if (self->selected_order != NULL) {
            get_integer_input(&self->selected_order->stage, "1 - Waiting, 2 - Prepared, 3 - Cooked, 4 - Delivered, 5 - Completed\nStage: ");
        }
        break;
    }
    // Report
    case 'r': {
        printf("0 - Uncompleted orders, 1 - Completed orders, 2 - Total revenue\n");
        int report_type;
        get_integer_input(&report_type, "Report: ");

        switch (report_type) {
        case 0:
            pizzeria_print_uncompleted(self);
            break;
        case 1:
            pizzeria_print_completed(self);
            break;
        case 2:
            printf("Total revenue for all completed orders: $%.2f\n", pizzeria_revenue(self));
            break;
        default:;
        }
        break;
    }
    default:;
    }
}

void pizzeria_select_order(pizzeria* self, int order_index) {
    order* nullable_order = order_get(self->orders, order_index);

    // Reassign order number only if order index is in bounds
    if (!nullable_order == NULL) {
        self->selected_order = nullable_order;
    }
}

void pizzeria_print_completed(pizzeria* self) {
    printf("+-- Completed Orders --------------------------------------+\n");
    printf("#   Customer                  Pizza               Price\n");
    print_short_divider();

    // Use a pointer to walk through the orders
    order* current_order = self->orders;
    int i = 1;

    while (current_order != NULL) {
        // If the order is complete complete
        if (current_order->stage == COMPLETED) {
            order_print_short(current_order, i, self->selected_order == current_order);
        }
        current_order = current_order->next;
        i++;
    }

    print_short_divider();
}

void pizzeria_print_uncompleted(pizzeria* self) {
    printf("+-- Uncompleted Orders --------------------------------------------------------+\n");
    printf("#   Customer                  Pizza               Price     Time      Tracking\n");
    print_divider();

    // Use a pointer to walk through the orders
    order* current_order = self->orders;
    int i = 1;

    // TODO: Create a loop to print each order, testing for a NULL order
    // and limiting the number of order so the screen does not overflow
    // Advance the_order pointer and the number with each iteration of the loop
    while (current_order != NULL) {
        // If the order is not complete
        if (!(current_order->stage == COMPLETED)) {
            order_print(current_order, i, self->selected_order == current_order);
        }
        current_order = current_order->next;
        i++;
    }

    // TODO: Make a call to print the footer of the order book
    pizzeria_print_footer(self);
}

double pizzeria_revenue(pizzeria* self) {
    double sum = 0;

    // Sum all orders
    order* order = self->orders;
    while (order != NULL) {
        if (order->stage == COMPLETED) {
            sum += order_revenue(order);
        }
        order = order->next;
    }

    return sum;
}
