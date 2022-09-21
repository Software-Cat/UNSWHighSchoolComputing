// vector.c
// A program that calculates cross product of two vectors
// Written by Bowen Wu on 21/09/2022
// ============================================================================

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

vector* cross(vector* a, vector* b)
{
    vector* result = malloc(sizeof(vector));

    result->x = a->y * b->z - b->y * a->z;
    result->y = b->x * a->z - a->x * b->z;
    result->z = a->x * b->y - b->x * a->y;

    return result;
}

vector* scan_vector()
{
    vector* new_vector = malloc(sizeof(vector));

    scanf("%lf,", &new_vector->x);
    scanf("%lf,", &new_vector->y);
    scanf("%lf", &new_vector->z);

    return new_vector;
}

void print_vector(vector* v)
{
    printf("%.2lf,%.2lf,%.2lf\n", v->x, v->y, v->z);
}

// ============================================================================
int main(void)
{
    printf("Enter vector 1: ");
    vector* a = scan_vector();
    printf("Enter vector 2: ");
    vector* b = scan_vector();

    vector* result = cross(a, b);
    printf("vector1 x vector2 = ");
    print_vector(result);

    return 0;
}
