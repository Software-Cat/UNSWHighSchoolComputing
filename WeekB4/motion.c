// motion.c
// Model object speed, velocity, and acceleration
// Written by Bowen Wu on 08/08/2022
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ============================================================================
// Structures
// ============================================================================
struct st_xyz {
    double x;
    double y;
    double z;
};

typedef struct st_xyz coord;
typedef struct st_xyz vector;

typedef struct st_object {
    char id[16];
    coord* position;
    vector* velocity;
    vector* acceleration;
} object;

// ============================================================================
// Instantiate (means to create and instance of an object)
// This will create and instance of both coord and vector
// ============================================================================
struct st_xyz* xyz(double x, double y, double z) {

    struct st_xyz* result = malloc(sizeof(struct st_xyz));
    result->x = x;
    result->y = y;
    result->z = z;
}

// TODO: Everything else
// This code uses a mix of '.' and '->'
// Don't get distracted as its easy to make a mistake

// In this lab the time step == 1 sec so we don't need to scale
// the acceleration and velocity
// We can just add them eg.  v1 = v0 + a  and  p1 = p0 + v1

void print_xyz(struct st_xyz* self) {
    printf("%*.4f,", 10, self->x);
    printf("%*.4f,", 10, self->y);
    printf("%*.4f", 10, self->z);
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

void add_to(coord* c, vector* v) {
    c->x += v->x;
    c->y += v->y;
    c->z += v->z;
}

void multiply_by(vector* v, double d) {
    v->x *= d;
    v->y *= d;
    v->z *= d;
}

// ============================================================================
// Main
// ============================================================================
int motion(void) {

    struct st_object the_object;
    strcpy(the_object.id, "Space ship");

    // TODO: Set initial values
    the_object.position = xyz(0, 0, 0);
    the_object.velocity = xyz(0, 0, 0);
    the_object.acceleration = normal_vector(xyz(1, 2, -1.5));
    multiply_by(the_object.acceleration, 5);

    //Print the intital state
    printf("%s\n", the_object.id);
    printf(" 0");
    print_xyz(the_object.position);
    printf("\n");

    // Do 10 time steps
    for (int i = 1; i <= 10; i++) {

        // TODO: calculate new values
        // v1 = v0 + a  and  p1 = p0 + v1
        add_to(the_object.velocity, the_object.acceleration);
        add_to(the_object.position, the_object.velocity);

        // Print the result
        printf("%2d", i);
        print_xyz(the_object.position);
        printf("\n");
    }

    return 0;

}
