#include <stdio.h>
#include "pilha.h"


struct no {
float info;
struct no* prox;
};
typedef struct no No;

struct pilha {
No* prim;
};


/* criar uma estrutura de pilha */
Pilha* pilha_cria (void)
{
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->prim = NULL;
  return p;
}
/* função auxiliar: insere no início */
No* ins_ini (No* l, float v)
{
   No* p = (No*) malloc(sizeof(No));
   p->info = v;
   p->prox = l;
   return p;
}

/* função auxiliar: retira do início */
No* ret_ini (No* l)
{
    No* p = l->prox;
    free(l);
    return p;
}
/* inserir um elemento no topo (push) */
void pilha_push (Pilha* p, float v)
{
   p->prim = ins_ini(p->prim,v);
}

/* remover o elemento do topo (pop) */
float pilha_pop (Pilha* p)
{
   float v;
   if (pilha_vazia(p)) {
      printf("Pilha vazia.\n");
      exit(1); /* aborta programa */
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}
/* verificar se a pilha está vazia */
int pilha_vazia (Pilha* p)
{
   return (p->prim==NULL);
}

/* liberar a estrutura de pilha */
void pilha_libera (Pilha* p)
{
   No* q = p->prim;
   while (q!=NULL) {
       No* t = q->prox;
       free(q);
       q = t;
    }
    free(p);
}

/* imprime: versão com lista */
void pilha_imprime (Pilha* p)
{
   No* q;

   for (q=p->prim; q!=NULL; q=q->prox)
   printf("%f\n",q->info);
}

/* concatena: versão com lista sem recursão utilizando estrutura auxiliar */
void pilha_concatena (Pilha* p1, Pilha* p2)
{
   Pilha* aux = pilha_cria();
   while (!pilha_vazia(p2))
        pilha_push(aux,pilha_pop(p2));
   while(!pilha_vazia(aux))
        pilha_push(p1,pilha_pop(aux));
}


/* concatena: versão com lista com recursão  */
void pilha_concatena_rec (Pilha* p1, Pilha* p2)
{
   float aux;
   if (pilha_vazia(p2)) return;
   else{
      aux = pilha_pop(p2);
      pilha_concatena_rec(p1,p2);
      pilha_push(p1,aux);
   }
}
