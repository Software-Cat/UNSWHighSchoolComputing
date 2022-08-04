// A program that accepts a sample of student height
//
// Bowen Wu
// 21/07/22
// I hereby declare that this submission is my own work and to the best of my knowledge
// it contains no materials previously published or written by another person, or
// substantial proportions of material which have been submitted for an assignment
// at UNSW or any other educational institution, except where due acknowledgement
// is made in the code.

//=============================================================================
// Library files
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

//=============================================================================
// Defines
//=============================================================================
#define MAX_SAMPLE_SIZE 15

//=============================================================================
// Main
//=============================================================================
int part1(void) {
    int count = 0;
    double input;
    double observations[MAX_SAMPLE_SIZE];

    while (1) {
        scanf("%lf", &input);

        observations[count] = input;

        count++;

        if (input == 0.0 || count >= MAX_SAMPLE_SIZE) {
            break;
        }
    }

    // The correct format for accepting a double is scanf("lf", &input);

    printf("count = %d\n", count);
}
