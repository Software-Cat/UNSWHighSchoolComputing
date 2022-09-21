// rot13.c
// A program that encrypts with ROT13 algorithm
// Written by Bowen Wu on 21/09/2022
// ============================================================================

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 81

char* rot13(char* original)
{
    char* encrypted = malloc(strlen(original));
    strcpy(encrypted, original);

    char* current = encrypted;
    while (*current !='\0') {
        if ((*current >= 'a' && *current <= 'z') || (*current >= 'A' && *current <= 'Z')) {
            if (*current > 'm' || (*current > 'M' && *current < '[')) {
                *current -= 13;
            } else {
                *current += 13;
            }
        }
        current++;
    }

    return encrypted;
}

// ============================================================================
int rot(void)
{
    printf("Enter plain text: ");

    char original[BUFFERSIZE]; 
    fgets(original, BUFFERSIZE, stdin);

    char* encrypted = rot13(original);
    printf("%s", encrypted);

    return 0;
}
