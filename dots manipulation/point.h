// exported type
typedef struct point Point;

// exported functions

// Create a point
Point *p_create(float x, float y);

// Free point
void p_free(Point *p);

// Get point
void p_get(Point *p, float *x, float *y);

// Edit point
void p_edit(Point *p, float x, float y);

// Return distance between points
float p_distance(Point *p1, Point *p2);

// Return pointer sum
Point *p_sum(Point *p1, Point *p2);

// Return diifference between points
Point *p_dif(Point *p1, Point *p2);
