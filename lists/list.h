
typedef struct list List;

/* init */
List *lst_init(void);

/* insert */
List *lst_insert(List *l, int i);

/* print */
void lst_print(List *l);

/* empty */
int lst_empty(List *l);

/* search */
List *lst_search(List *l, int v);

/* out */
List *lst_out(List *l, int v);

// free
void lst_free(List *l);
