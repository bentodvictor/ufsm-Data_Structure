#include <stdio.h>
#include "list.h"

struct list
{
    int info;
    struct list *next;
};

/* init */
List *lst_init(void)
{
    return NULL;
}

/* insert */
List *lst_insert(List *l, int i)
{
    List *new = (List *)malloc(sizeof(List));

    new->info = i;
    new->next = l;

    return new;
}

/* print */
void lst_print(List *l)
{
    List *p;

    for (p = l; p != NULL; p = p->next)
        printf("info = %d\n", p->info);
}

/* empty */
int lst_empty(List *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

/* search */
List *lst_search(List *l, int v)
{
    List *p;
    for (p = l; p != NULL; p = p->next)
        if (p->info == v)
            return p;
    return NULL;
}

/* out */
List *lst_out(List *l, int v)
{

    List *prev = NULL; /* prev element */
    List *p = l;

    /* search element in list and save prev element */
    while (p != NULL && p->info != v)
    {
        prev = p;
        p = p->next;
    }

    // find ?
    if (p == NULL)
        return l;
    if (prev == NULL)
    {
        /* remove element */
        l = p->next;
    }
    else
    {
        /* remove element */
        prev->next = p->next;
    }
    free(p);

    return l;
}

void lst_libera(List *l)
{
    List *p = l;

    while (p != NULL)
    {
        List *t = p->next;

        free(p);

        p = t;
    }
}
