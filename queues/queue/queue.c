#include <stdio.h>
#include "queue.h"

struct list
{
   float info;
   struct list *next;
};
typedef struct list List;

struct queue
{
   List *start;
   List *end;
};

Queue *create(void)
{
   Queue *f = (Queue *)malloc(sizeof(Queue));
   f->start = f->end = NULL;
   return f;
}

void insert(Queue *f, float v)
{
   List *n = (List *)malloc(sizeof(List));
   n->info = v;    /* store information */
   n->next = NULL; /* new node is the last */

   if (f->end != NULL)
      f->end->next = n;
   else
      f->start = n;
   f->end = n;
}

float remove(Queue *f)
{
   List *t;
   float v;

   if (empty(f))
   {
      printf("Empty Queue.\n");
      exit(1);
   }

   t = f->start;
   v = t->info;
   f->start = t->next;

   if (f->start == NULL)
      f->end = NULL;

   free(t);
   return v;
}

int empty(Queue *f)
{
   return (f->start == NULL);
}

void queue_free(Queue *f)
{
   List *q = f->start;

   while (q != NULL)
   {
      List *t = q->next;
      free(q);
      q = t;
   }
   free(f);
}

void print(Queue *f)
{
   List *q;

   for (q = f->start; q != NULL; q = q->next)
      printf("%f\n", q->info);
}
