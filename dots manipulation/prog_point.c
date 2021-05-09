#include <stdio.h>
#include "point.h"
#include<stdlib.h>

int main(void)
{
    Point* p = p_create(5.0, 3.0);
    Point* q = p_create(6.4, 2.1);
    Point* s;
    float r_x, r_y;

    p_get(p, &r_x, &r_y);
    printf("Point 1: (%.2f , %.2f)\n", r_x, r_y);
    
    p_get(q, &r_x, &r_y);
    printf("Point 2: (%.2f , %.2f)\n", r_x, r_y);

    float d = p_distance(p, q);
    printf("Distance between points: %.2f\n", d);

    s = p_sum(p, q);
    p_get (s, &r_x, &r_y);
    printf("Sum of Points: (%.2f , %.2f)\n", r_x, r_y);
    
    s = p_dif(p, q);
    p_get (s, &r_x, &r_y);
    printf("Difference between Points: (%.2f , %.2f)\n", r_x, r_y);

    p_free(q);
    p_free(p);
    p_free(s);

    return 0;
}
