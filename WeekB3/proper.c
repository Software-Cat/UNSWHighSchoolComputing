// proper.c
// Capitalize every word in the line.
// Written by Bowen Wu on 01/08/22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int c;
    int needCaps = 1;

    do {
        c = getchar();

        if (needCaps == 1) {
            putchar(toupper(c));
        } else {
            putchar(c);
        }

        if (c == ' ') {
            needCaps = 1;
        } else {
            needCaps = 0;
        }
    } while (c != '\n');

    return 0;
}
