typedef struct queue Queue;

/* create */
Queue *create(void);

/* insert */
void insert(Queue *f, float v);

/* remove */
float remove(Queue *f);

/* empty */
int empty(Queue *f);

/* free */
void queue_free(Queue *f);

/* printZ */
void print(Queue *f);
