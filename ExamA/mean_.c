// A program that accepts a sample of student height and calulates the mean
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

double mean(double observations[MAX_SAMPLE_SIZE], int count);

//=============================================================================
// Main
//=============================================================================

int part2(void) {
    int count = 0;
    double input;
    double observations[MAX_SAMPLE_SIZE];

    while (1) {
        scanf("%lf", &input);

        observations[count] = input;

        if (input == 0.0 || count >= MAX_SAMPLE_SIZE - 1) {
            break;
        }

        count++;
    }

    // The correct format for accepting a double is scanf("lf", &input);

    printf("count = %d\n", count);
    printf("mean = %5.3f\n", mean(observations, count));
}

double mean(double observations[MAX_SAMPLE_SIZE], int count) {
    double sum = 0;
    for (int i = 0; i < MAX_SAMPLE_SIZE; i++) {
        sum += observations[i];
    }

    return sum / count;
}
