#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void invert(int n, float *v)
{
    float aux;
    int i;

    for (i = 0; i < (n / 2); i++)
    {
        aux = v[n - i - 1];
        v[n - i - 1] = v[i];
        v[i] = aux;
    }
}

int main()
{
    int i, n;
    float *v;

    printf("Insert vector length: \n");
    scanf("%d", &n);

    v = (float *)malloc(n * sizeof(float));

    printf("\nInsert values for vector:\n");
    for (i = 0; i < n; i++)
    {
        printf("V[%d]: ", i);
        scanf("%f", &v[i]);
    }

    invert(n, v);

    printf("\nInverted vector:\n");
    for (i = 0; i < n; i++)
    {
        printf("V[%d]:  %f\n", i, v[i]);
    }

    return 0;
}