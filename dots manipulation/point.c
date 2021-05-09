#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

struct point
{
    float x;
    float y;
};

Point *p_create(float x, float y)
{
    Point *p = (Point *)malloc(sizeof(Point));

    if (p == NULL)
    {
        printf("memory error!\n");
        exit(1);
    }

    p->x = x;
    p->y = y;

    return p;
}

void p_free(Point *p)
{
    free(p);
}

void p_get(Point *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}

void p_edit(Point *p, float x, float y)
{
    p->x = x;
    p->y = y;
}

float p_distance(Point *p1, Point *p2)
{
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}

Point *p_sum(Point *p1, Point *p2)
{
    Point *p = (Point *)malloc(sizeof(Point));

    if (p == NULL)
    {
        printf("Memory error!\n");
        exit(1);
    }

    p->x = p1->x + p2->x;
    p->y = p1->y + p2->y;

    return p;
}

Point *p_dif(Point *p1, Point *p2)
{
    Point *p = (Point *)malloc(sizeof(Point));

    if (p == NULL)
    {
        printf("Memory error!\n");
        exit(1);
    }

    p->x = p1->x - p2->x;
    p->y = p1->y - p2->y;
    
    return p;
}
