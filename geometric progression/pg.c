#include <stdio.h>
#include <math.h>

/* 
    geometric progression
    1+x^1+x^2+...+x^n
*/
int pg(int y, int m)
{
    if (m <= 0)
        return 1;
    else
        return (pow(y, m) + pg(y, m - 1));
}

int main(void)
{
    int n, x;

    printf("geometric progression\n");
    printf("1+x^1+x^2+...+x^n\n\n");

    printf("x value:\n");
    scanf("%d", &x);

    printf("n value: \n");
    scanf("%d", &n);

    if (n < 0)
        return 1;

    printf("\nGeometric progression = %d\n", pg(x, n));

    return 0;
}
