#include <stdio.h>
#include "list_ord.h"

struct list
{
    int info;
    struct list *next;
};

List *lst_init(void)
{
    return NULL;
}

List *lst_insert(List *l, int i)
{
    List *new = (List *)malloc(sizeof(List));
    new->info = i;
    new->next = l;
    return new;
}

void lst_print(List *l)
{
    List *p;

    for (p = l; p != NULL; p = p->next)
        printf("info = %d\n", p->info);
}

int lst_empty(List *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

List *lst_search(List *l, int v)
{
    List *p;
    for (p = l; p != NULL; p = p->next)
        if (p->info == v)
            return p;
    return NULL;
}

List *lst_out(List *l, int v)
{

    List *prev = NULL;
    List *p = l;

    /* searc helement in list and store prev element */
    while (p != NULL && p->info != v)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
        return l;

    if (prev == NULL)
    {
        l = p->next;
    }
    else
    {
        prev->next = p->next;
    }

    free(p);

    return l;
}

void lst_free(List *l)
{
    List *p = l;

    while (p != NULL)
    {
        List *t = p->next;

        free(p);

        p = t;
    }
}

List *lst_create(int v)
{
    List *p = (List *)malloc(sizeof(List));

    p->info = v;
    return p;
}

List *lst_insert_ord(List *l, int v)
{
    List *new = lst_create(v); /* create new node */
    List *prev = NULL;
    List *p = l;

    while (p != NULL && p->info < v)
    {
        prev = p;
        p = p->next;
    }

    if (prev == NULL)
    {
        new->next = l;
        l = new;
    }
    else
    {
        new->next = prev->next;
        prev->next = new;
    }

    return l;
}

void lst_print_rec(List *l)
{
    if (lst_empty(l))
        return;

    printf("info: %d\n", l->info);

    lst_print_rec(l->next);
}

/* Função imprime recursiva em ordem inversa */
void lst_print_rec_ord_inv(List *l)
{
    if (lst_empty(l))
        return;

    lst_print_rec_ord_inv(l->next);

    printf("info: %d\n", l->info);
}
