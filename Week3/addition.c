#include "addition.h"
#include <stdio.h>

void ask_for(char* inquiry, char* responseFormat, int* r1, int* r2) {
	printf(inquiry);
	scanf(responseFormat, r1, r2);
}

void addition() {
	int students = 0;
	int tutors = 0;
	int total;

	// Scan for two numbers
	// Include a prompt
	// Remember to provide the address of the variable using '&'
	ask_for("Please enter the number of students and tutors: ", "%d %d", &students, &tutors);

	// Calculate the total
	total = students + tutors;

	// Print the addition as an equation
	printf("%d + %d = %d\n", students, tutors, total);
}
