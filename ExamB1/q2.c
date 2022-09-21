#include <stdio.h>

int q2()
{
    int m, n;
    int *p, *q;

    m = 42;
    p = &m;
    q = &n;

    *q = 2 * m;
    n = *q / *p;
    printf("%d\n", n);

    return 1;
}
