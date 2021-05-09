#include <stdio.h>
#include "list.h"

int main(void)
{
    List *l;

    l = lst_init();

    l = lst_insert(l, 23);
    l = lst_insert(l, 45);
    l = lst_insert(l, 56);
    l = lst_insert(l, 78);

    lst_print(l);

    l = lst_out(l, 78);
    printf("\nRemoving element 78\n");

    lst_print(l);

    l = lst_out(l, 45);
    printf("\nRemoving element 45\n");

    lst_print(l);

    lst_free(l);
    return 0;
}
