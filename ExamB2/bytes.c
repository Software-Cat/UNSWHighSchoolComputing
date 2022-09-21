// bytes.c
// A program that calculates factorial values
// Written by Bowen Wu on 21/09/2022
// ============================================================================

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
void printmemory(double* number)
{
    unsigned char* ptr = (char*)number;

    for (int i = 0; i < 8; i++)
    {
        printf("%d|", ptr[i]);
    }

    //printf("%d", *ptr);

    // Print some white space after the last '|'
    printf("\n\n");
}

// ============================================================================
int bytes(void)
{

    double number = 0;

    while (number != 7) {

        // Scan a number
        // Include a prompt
        // Remember to provide the address of the variable using '&'
        printf("Enter a double from 1.7E-308 to 1.7E+308 (Enter 7 to terminate)\n");
        scanf("%lf", &number);

        // TODO: print the number in "%12f |" format
        // TODO: call the function printmemory() to print out the bytes
        //       using "%d|" format
        printf("%12f", number);
        printf(" |");
        printmemory(&number);
    }

    return 0;
}
