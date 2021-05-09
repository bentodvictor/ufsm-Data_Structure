#include <stdio.h>
#include "stack.h"

int main(void)
{
    int i, elem;
    float content;

    Stack *l;
    l = stack_create();
    Stack_vec *v;
    v = stack_vec_create();

    printf("\nInsert the number of elements in the Stack: ");
    scanf("%d", &elem);

    for (i = 1; i <= elem; i++)
    {
        printf("\nInsert an element: ");
        scanf("%f", &content);
        stack_push(l, content);
        stack_vec_push(v, content);
    }

    printf("\nPrint stack as a list \n");
    stack_print(l);
    printf("\nPrint stack as a vector  \n");
    stack_vec_print(v);

    printf("\nRemove an element\n");
    stack_pop(l);
    stack_vec_pop(v);

    printf("\nPrint stack as a list \n");
    stack_print(l);
    printf("\nPrint stack as a vector  \n");
    stack_vec_print(v);

    stack_print(l);
    stack_vec_print(v);

    return 0;
}
