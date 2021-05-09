#include <stdio.h>
#include "list_circ.h"

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

void lst_convert(List *l)
{
  List *p;

  if (lst_empty(l))
    return;

  p = l;

  while (l->next != NULL)
    l = l->next;

  l->next = p;
  l = p;

  return;
}

void lst_free_circ(List *l)
{
  List *p = l;

  do
  {
    List *t = p->next;
    free(p);
    p = t;
  } while (p->next != l);
}

void lst_print_circ(List *l)
{
  List *p;
  if (lst_empty(l))
    return;
  p = l;
  do
  {
    printf("info = %d\n", p->info);
    p = p->next;
  } while (p != l);
}
