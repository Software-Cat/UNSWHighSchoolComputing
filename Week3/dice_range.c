#include "dice_range.h"
#include <stdio.h>

int dice_min(int diceSides, int diceNumber) {
	return diceNumber;
}

int dice_max(int diceSides, int diceNumber) {
	return diceNumber * diceSides;
}

void dice_range() {
	int diceSides;
	printf("Enter the number of sides on your dice: ");
	scanf("%d", &diceSides);

	int diceNumber;
	printf("Enter the number of dice being rolled: ");
	scanf("%d", &diceNumber);

	printf("Your dice range is %d to %d.\n", dice_min(diceSides, diceNumber), dice_max(diceSides, diceNumber));
	printf("The average value is %f", ((float)dice_min(diceSides, diceNumber) + dice_max(diceSides, diceNumber)) / 2);
}
