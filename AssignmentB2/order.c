﻿//=============================================================================
// CS Pizzeria
// order.c
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#include "order.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

//=============================================================================
// Functions
//=============================================================================

order* order_new() {
    // Allocate memory for the order
    order* new_order = malloc(sizeof(order));

    // Use helper functions to get the information from the user
    // Don't forget to set all the fields to an initial value. The NULL
    // value has a special meaning in some other helper functions.
    get_char_input(new_order->customer, "Customer: ", ORDER_CUSTOMER_LENGTH);
    get_char_input(new_order->pizza, "Pizza: ", ORDER_PIZZA_LENGTH);
    get_double_input(&new_order->price, "Cost: ");
    get_integer_input(&new_order->time, "Time: ");
    new_order->next = NULL;
    new_order->ingredients = NULL;
    new_order->stage = WAITING;

    return new_order;
}

void order_print(order* self, const int order_number, const bool selected) {
    // Print order number (4 chars)
    printf("%02d ", order_number);
    if (selected) {
        printf(">");
    }
    else {
        printf(" ");
    }

    // Print customer name (26 chars)
    // %-26s aligns the string to the left and prints 26 characters in field
    printf("%-26s", self->customer);

    // Print pizza name (20 chars)
    printf("%-20s", self->pizza);

    // Print price (10 chars)
    printf("$%-9.2f", self->price);

    // Print time (10 chars)
    printf("%-10d", self->time);

    // Print tracking (unlimited chars)
    stage_print(self->stage);

    // Newline
    printf("\n");

    // Print ingredients
    ingredient* ingredient = self->ingredients;
    if (ingredient != NULL) {
        while (ingredient != NULL) {
            ingredient_print(ingredient);
            ingredient = ingredient->next;
        }
    }
}

void order_print_short(order* self, int order_number, bool selected) {
    // Print order number (4 chars)
    printf("%02d ", order_number);
    if (selected) {
        printf(">");
    }
    else {
        printf(" ");
    }

    // Print customer name (26 chars)
    // %-26s aligns the string to the left and prints 26 characters in field
    printf("%-26s", self->customer);

    // Print pizza name (20 chars)
    printf("%-20s", self->pizza);

    // Print price (10 chars)
    printf("$%-9.2f", self->price);

    // Newline
    printf("\n");

    // Print ingredients
    ingredient* ingredient = self->ingredients;
    if (ingredient != NULL) {
        while (ingredient != NULL) {
            ingredient_print(ingredient);
            ingredient = ingredient->next;
        }
    }
}

void order_append(order** head, order* element) {
    // Ensure the new node is the last node
    element->next = NULL;

    // If list is empty, make new node head
    if (*head == NULL) {
        *head = element;
        return;
    }

    // Else traverse to last node
    order* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Append element as next of last node
    last->next = element;
}

order* order_get(order* head, int index) {
    order* current = head;

    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }

    // If the index does not exist
    return NULL;
}

void stage_print(stage self) {
    switch (self) {
    case WAITING:
        printf("Waiting");
        break;
    case PREPARED:
        printf("Prepared");
        break;
    case COOKED:
        printf("Cooked");
        break;
    case DELIVERED:
        printf("Delivered");
        break;
    case COMPLETED:
        printf("Completed");
        break;
    default:
        printf("Invalid");
    }
}

double order_revenue(order* self) {
    // Add price of order
    double sum = self->price;

    // Add all prices of ingredients
    ingredient* ingredient = self->ingredients;
    while (ingredient!=NULL) {
        sum += ingredient->price * ingredient->amount;
        ingredient = ingredient->next;
    }

    return sum;
}
