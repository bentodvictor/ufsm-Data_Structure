#include <stdio.h>
#include "list_ord.h"

int main(void)
{
    int content, elem, i;
    List *l;
    l = lst_init();

    printf("\nInsert the number of elements for the List: ");
    scanf("%d", &elem);

    for (i = 1; i <= elem; i++)
    {
        printf("\nInsert an element: ");
        scanf("%d", &content);
        l = lst_insert_ord(l, content);
    }

    lst_print(l);
    printf("\nInsert the element to remove from list: ");
    scanf("%d", &content);

    l = lst_out(l, content);
    printf("\nRemoving the element %d\n", content);

    lst_print_rec(l);
    printf("\nPrinting the list in inverse order (desc): \n");

    lst_print_rec_ord_inv(l);

    lst_free(l);

    return 0;
}
