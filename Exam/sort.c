// A program that accepts a sample of student height and calulates the mean and
// standard deviation, then sort the observations
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
double sum(double observations[MAX_SAMPLE_SIZE], int count);
double std(double observations[MAX_SAMPLE_SIZE], int count);
void sort(double* observations[MAX_SAMPLE_SIZE]);

//=============================================================================
// Main
//=============================================================================

int part4(void) {
	int count = 0;
	double input;
	double observations[MAX_SAMPLE_SIZE] = { 0 };

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
	printf("stDev = %5.3f\n", std(observations, count));

	sort(observations);

	for (int i = 0; i < MAX_SAMPLE_SIZE; i++) {
		if (observations[i] != 0) {
			printf("%5.3f\n", observations[i]);
		}
	}
}

double sum(double observations[MAX_SAMPLE_SIZE], int count) {
	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum += observations[i];
	}

	return sum;
}

double mean(double observations[MAX_SAMPLE_SIZE], int count) {
	return sum(observations, count) / count;
}

double std(double observations[MAX_SAMPLE_SIZE], int count) {
	// Cache mean calculation for efficiency
	double cachedMean = mean(observations, count);

	double squareDiffs[MAX_SAMPLE_SIZE];
	for (int i = 0; i < count; i++) {
		squareDiffs[i] = (observations[i] - cachedMean) * (observations[i] - cachedMean);
	}

	printf("debug: %f\n", sum(squareDiffs, count));

	return sqrt(sum(squareDiffs, count) / (double)(count - 1));
}

void sort(double* observations[MAX_SAMPLE_SIZE]) {
	for (int i = 0; i < MAX_SAMPLE_SIZE; i++) {
		for (int j = 0; j < MAX_SAMPLE_SIZE - i - 1; j++) {
			if (observations[j] > observations[j + 1]) {
				// If the order is wrong, swap it (bubble sort)
				double* temp = observations[j + 1];
				observations[j + 1] = observations[j];
				observations[j] = temp;
			}
		}
	}
}
