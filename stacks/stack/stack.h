typedef struct stack Stack;

/* stack structure using vector */
typedef struct stack_vec Stack_vec;

/* create struct */
Stack *stack_create(void);
Stack_vec *stack_vec_create(void);

/* insert top element (push) */
void stack_push(Stack *p, float v);
void stack_vec_push(Stack_vec *p, float v);

/* remove top element (pop) */
float stack_pop(Stack *p);
float stack_vec_pop(Stack_vec *p);

/* empty */
int stack_empty(Stack *p);
int stack_vec_empty(Stack_vec *p);

/* free */
void stack_free(Stack *p);
void stack_vec_free(Stack_vec *p);

/* print */
void stack_print(Stack *p);
void stack_vec_print(Stack_vec *p);
