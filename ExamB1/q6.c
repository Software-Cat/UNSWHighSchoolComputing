#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct student
{
    int ID;
    char* name;
    double ave_mark;
};

int q6()
{
    struct student* mary = malloc(sizeof(struct student));

    printf("%s", mary->name);
}
