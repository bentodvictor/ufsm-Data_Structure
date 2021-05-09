typedef struct list List;

List *lst_init(void);

List *lst_insert(List *l, int i);

void lst_print(List *l);

int lst_empty(List *l);

List *lst_search(List *l, int v);

List *lst_create(int v);

void lst_convert(List *l);

void lst_free_circ(List *l);

void lst_print_circ(List *l);
