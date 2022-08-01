// devowel.c
// Censors the vowels with "*"
// Written by Bowen Wu on 01/08/22

#include "devowel.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int devowel(void) {
	int c;
	do {
		c = getchar();

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			putchar('*');
		} else {
			putchar(c);
		}
	}
	while (c != '\n');

	return 0;
}
