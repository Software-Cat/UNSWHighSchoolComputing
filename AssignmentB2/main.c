//=============================================================================
// CS Pizzeria
// main.c
//
// This program was written by Bowen Wu
// on 01/08/22
//=============================================================================

//=============================================================================
// Includes
//=============================================================================

#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizzeria.h"
#include "utils.h"

#if __has_include("config.h")
#include "config.h"
#endif

//=============================================================================
// Functions
//=============================================================================

int main() {
#ifdef CMAKE_BUILD_TYPE
    if (strcmp("Debug", CMAKE_BUILD_TYPE) == 0) {
        // Disable buffer to fix debugger issue in my IDE, no effect on program output
        setbuf(stdout, 0);
    }
#endif

    // Create the root for the data tree
    printf("Creating pizzeria\n");
    pizzeria* cs_pizzeria = pizzeria_new();

    // Get commands from the user and process them
    char command[MAX_COMMAND_LENGTH] = "?";
    while (command[0] != 'x') {
        // Print the order book first
        printf("\n");
        pizzeria_print_all(cs_pizzeria);

        // Get the command and process it
        get_command_input(command, "Command: ", MAX_COMMAND_LENGTH);
        pizzeria_process_command(cs_pizzeria, command);
    }

    return EXIT_SUCCESS;
}
