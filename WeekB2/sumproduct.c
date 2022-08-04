// ============================================================================
// sumproduct.c
// Calculate the sum and product of an array numbers.
// Written by Bowen Wu on 25/07/22
// ============================================================================

#include "sumproduct.h"
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
void sum_product(int length, int number[], int* sum, int* product) {
    // If length is zero, sum and product must be zero.
    if (length == 0) {
        *sum = 0;
        *product = 0;
    }

    int currentSum = 0;
    int currentProduct = 1;
    for (int i = 0; i < length; ++i) {
        currentSum += number[i];
        currentProduct *= number[i];
    }

    *sum = currentSum;
    *product = currentProduct;
}

// ============================================================================
int sumproduct(void) {

    // Initialise the array
    int number[] = {3, 5, 1, 7, 3, 9};
    int length = 6;
    int sum;
    int product;

    // Call the function
    sum_product(length, number, &sum, &product);

    // Print the number element
    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);

    return 0;
}
