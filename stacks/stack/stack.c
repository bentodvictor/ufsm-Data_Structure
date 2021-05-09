#include <stdio.h>
#include "stack.h"

// using vector
#define MAX 50
struct stack_vec
{
   int n;
   float vet[MAX];
};

struct node
{
   float info;
   struct node *next;
};
typedef struct node Node;

struct stack
{
   Node *prim;
};

Stack *stack_create(void)
{
   Stack *p = (Stack *)malloc(sizeof(Stack));
   p->prim = NULL;
   return p;
}

Stack_vec *stack_vec_create(void)
{
   Stack_vec *p = (Stack_vec *)malloc(sizeof(Stack_vec));
   p->n = 0;
   return p;
}

Node *ins_ini(Node *l, float v)
{
   Node *p = (Node *)malloc(sizeof(Node));
   p->info = v;
   p->next = l;
   return p;
}

Node *ret_ini(Node *l)
{
   Node *p = l->next;
   free(l);
   return p;
}

void stack_push(Stack *p, float v)
{
   p->prim = ins_ini(p->prim, v);
}

void stack_vec_push(Stack_vec *p, float v)
{
   if (p->n == MAX)
   {
      printf("Stack overflow!\n");
      exit(1);
   }

   p->vet[p->n] = v;
   p->n++;
}

float stack_pop(Stack *p)
{
   float v;
   if (stack_empty(p))
   {
      printf("Stack empty.\n");
      exit(1);
   }

   v = p->prim->info;
   p->prim = ret_ini(p->prim);
   return v;
}

float stack_vec_pop(Stack_vec *p)
{
   float v;
   if (p->n == 0)
   {
      printf("Stack empty!\n");
      exit(1);
   }

   v = p->vet[p->n - 1];
   p->n--;
   return v;
}

int stack_empty(Stack *p)
{
   return (p->prim == NULL);
}

int stack_vec_empty(Stack_vec *p)
{
   return (p->n == 0);
}

void stack_free(Stack *p)
{
   Node *q = p->prim;

   while (q != NULL)
   {
      Node *t = q->next;
      free(q);
      q = t;
   }
   free(p);
}

void stack_vec_free(Stack_vec *p)
{
   free(p);
}

void stack_print(Stack *p)
{
   Node *q;

   for (q = p->prim; q != NULL; q = q->next)
      printf("%f\n", q->info);
}

void stack_vec_print(Stack_vec *p)
{
   int i;

   for (i = p->n - 1; i >= 0; i--)
      printf("%f\n", p->vet[i]);
}
