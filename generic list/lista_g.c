#include <stdio.h>
#include "lista_g.h"

struct listag
{
   void *info;
   struct listag *prox;
};

typedef struct listag Listag;

/* função de inicialização: retorna uma lista genérica vazia */
Listag *lstg_inicializa(void)
{
   return NULL;
}

/* inserção no início: retorna a lista genérica atualizada */
Listag *lstg_insere(Listag *l, void *p)
{
   Listag *novo = (Listag *)malloc(sizeof(Listag));
   novo->info = p;
   novo->prox = l;
   return novo;
}

/* função percorre: percorre os elementos de uma lista genérica*/
void lstg_percorre(Listag *l, void (*cb)(void *))
{
   Listag *p; /* variável auxiliar para percorrer a lista genérica*/
   for (p = l; p != NULL; p = p->prox)
      cb(p->info);
}

/* função percorre: percorre os elementos de uma lista genérica, mas também passando dados*/
void lstg_percorre_dados(Listag *l, void (*cbd)(void *, void *), void *dado)
{
   Listag *p; /* variável auxiliar para percorrer a lista genérica*/
   for (p = l; p != NULL; p = p->prox)
      cbd(p->info, dado);
}

/* função percorre: percorre os elementos de uma lista genérica,
mas também passando dados e parando através de algum critério estabelecido pelo cliente*/
int lstg_percorre_para(Listag *l, int (*cbp)(void *, void *), void *dado)
{
   Listag *p; /* variável auxiliar para percorrer a lista genérica*/
   for (p = l; p != NULL; p = p->prox)
   {
      int r = cbp(p->info, dado);
      if (r != 0)
         return r;
   }
   return 0;
}
