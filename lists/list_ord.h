
typedef struct list List;

// init
List *lst_init(void);

// insert
List *lst_insert(List *l, int i);

// print
void lst_print(List *l);

// empty
int lst_empty(List *l);

// search
List *lst_search(List *l, int v);

// remove
List *lst_out(List *l, int v);

void lst_free(List *l);

// create and init a node
List *lst_create(int v);

// insert in asc order
List *lst_insert_ord(List *l, int v);

// recursive print
void lst_print_rec(List *l);

// recursive print in reverse order
void lst_print_rec_ord_inv(List *l);
