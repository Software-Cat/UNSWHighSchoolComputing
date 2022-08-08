// coord.c
// Stores 3D coordinates
// Written by Bowen Wu on 08/08/2022
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coord_t {
    double x;
    double y;
    double z;
} coord;

// ============================================================================
// Print Coordinates
// ============================================================================
void print_coord(coord* self) {
    printf("x = %.2f\n", self->x);
    printf("y = %.2f\n", self->y);
    printf("z = %.2f\n", self->z);
}

// ============================================================================
// Main
// ============================================================================
int run_coord(void) {

    // Declare out variables
    coord the_coords;
    char input[16];
    char* pointer;

    // Accept input from the user removing any trailing special characters
    printf("Enter coordinates (x,y,z): ");
    fgets(input, 16, stdin);
    input[strcspn(input, "\r\n")] = 0;

    // Split the input string using a ',' as the delimiter
    // This code has no error checking
    // Note the NULL in the second strtok function call
    pointer = strtok(input, ",");
    the_coords.x = atof(pointer);

    pointer = strtok(NULL, ",");
    the_coords.y = atof(pointer);

    pointer = strtok(NULL, ",");
    the_coords.z = atof(pointer);

    print_coord(&the_coords);

    return 0;
}
