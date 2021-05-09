#include <stdio.h>
#include "arvore_n.h"

struct arvn
{
   char info;
   struct arvn *prim;
   struct arvn *prox;
};

/* criar uma estrutura de Árvore com número variável de filhos */
Arvn *arvn_cria(char c)
{
   Arvn *a = (Arvn *)malloc(sizeof(Arvn));
   a->info = c;
   a->prim = NULL;
   a->prox = NULL;
   return a;
}

/* insere um elemento numa Árvore com número variável de filhos */
void arvn_insere(Arvn *a, Arvn *sa)
{
   sa->prox = a->prim;
   a->prim = sa;
}

/* Imprime uma Árvore com número variável de filhos */
void arvn_imprime(Arvn *a)
{
   Arvn *p;
   printf("<%c ", a->info);
   for (p = a->prim; p != NULL; p = p->prox)
      arvn_imprime(p); /* imprime cada sub-árvore */
   printf(">");
}

/* Libera a memória ocupada pela Árvore com número variável de filhos */
void arvn_libera(Arvn *a)
{
   Arvn *p = a->prim;
   while (p != NULL)
   {
      Arvn *t = p->prox;
      arvn_libera(p);
      p = t;
   }
   free(a);
}

/* Verifica se determinado caractere pertence a Árvore com número variável de filhos  */
int arvn_pertence(Arvn *a, char c)
{
   Arvn *p;
   if (a->info == c)
      return 1;
   else
   {
      for (p = a->prim; p != NULL; p = p->prox)
      {
         if (arvn_pertence(p, c))
            return 1;
      }
      return 0;
   }
}

/* Retorna a altura da Árvore com número variável de filhos */
int arvn_altura(Arvn *a)
{
   int hmax = -1; /* -1 para tratar o caso com zero filhos */
   Arvn *p;

   for (p = a->prim; p != NULL; p = p->prox)
   {
      int h = arvn_altura(p);
      if (h > hmax)
         hmax = h;
   }
   return hmax + 1;
}
