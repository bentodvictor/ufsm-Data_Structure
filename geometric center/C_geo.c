#include <stdio.h>
#include <stdlib.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

Point center_geo(int n, Point *v)
{
    int i;
    Point p = {0.0f, 0.0f};

    for (i = 0; i < n; i++)
    {
        p.x += v[i].x;
        p.y += v[i].y;
    }

    p.x /= n;
    p.y /= n;

    return p;
}

int main()
{
    int i, n;
    Point *coord;
    Point center;

    printf("Insert a set of points (Cartesian coordinates)\n");
    printf("Enter the number of points (n): ");
    scanf("%d", &n);

    coord = (Point *)malloc(n * sizeof(Point));
    
    if (coord == NULL)
    {
        printf("Insufficient Memory");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nInsert x%d =  ", i);
        scanf("%f", &coord[i].x);

        printf("\nInsert y%d =  ", i);
        scanf("%f", &coord[i].y);
    }

    center = center_geo(n, coord);
    printf("\nGeometric center =  [%.2f , %.2f]", center.x, center.y);
    free(coord);
    
    return 0;
}
