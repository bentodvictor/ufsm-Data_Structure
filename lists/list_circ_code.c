#include <stdio.h>
#include "list_circ.h"

int main(void)
{
    int content, elem, i;
    List *l;

    l = lst_init();
    printf("\nInsert the number of elements for the list: ");
    scanf("%d", &elem);

    for (i = 1; i <= elem; i++)
    {
        printf("\nInsert an element: ");
        scanf("%d", &content);
        l = lst_insert(l, content);
    }

    printf("\nPrinting the list \n");
    lst_print(l);

    printf("\nConvert List for Circular List");
    lst_convert(l);

    printf("\nPrinting the circular list \n");
    lst_print_circ(l);
    lst_free_circ(l);

    return 0;
}
