#include <stdio.h>
#include "queue.h"

int main(void)
{
    int i, elem;
    float content;

    Queue *f;
    f = create();

    printf("\nInsert the number of elements in queue: ");
    scanf("%d", &elem);

    for (i = 1; i <= elem; i++)
    {
        printf("\nInsert element: ");
        scanf("%f", &content);
        insert(f, content);
    }

    printf("\nQueue print: \n");
    print(f);

    printf("\nRemove element %f: \n", remove(f));
    printf("\nPrint new queue \n");

    print(f);

    queue_free(f);

    return 0;
}
