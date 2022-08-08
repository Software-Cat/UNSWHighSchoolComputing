// vector.c
// Struct to store 3D vector
// Written by Bowen Wu on 08/08/2022
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct vector_t {
    double x;
    double y;
    double z;
} vector;

void print_coord(vector* self) {
    printf("x = %.4f\n", self->x);
    printf("y = %.4f\n", self->y);
    printf("z = %.4f\n", self->z);
}

double vector_size(vector* self) {
    return sqrt(pow(self->x, 2) + pow(self->y, 2) + pow(self->z, 2));
}

vector* normal_vector(vector* self) {
    vector* normal = malloc(sizeof(vector));

    double size = vector_size(self);
    normal->x = self->x / size;
    normal->y = self->y / size;
    normal->z = self->z / size;

    return normal;
}

int run_vector(void) {
    // Declare out variables
    vector the_vector;
    char input[16];
    char* pointer;

    // Accept input from the user removing any trailing special characters
    printf("Enter vector (x,y,z): ");
    fgets(input, 16, stdin);
    input[strcspn(input, "\r\n")] = 0;

    // Split the input string using a ',' as the delimiter
    // This code has no error checking
    // Note the NULL in the second strtok function call
    pointer = strtok(input, ",");
    the_vector.x = atof(pointer);

    pointer = strtok(NULL, ",");
    the_vector.y = atof(pointer);

    pointer = strtok(NULL, ",");
    the_vector.z = atof(pointer);

    // Normalize
    vector* new_vector = normal_vector(&the_vector);

    // Print
    printf("Normal vector:\n");
    print_coord(new_vector);

    return 0;
}
