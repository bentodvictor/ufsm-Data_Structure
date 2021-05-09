#include <stdio.h>
#include "arvore_bin.h"

struct arvb
{
   char info;
   struct arvb *esq;
   struct arvb *dir;
};

/* criar uma estrutura de Árvore Binária Vazia*/
Arvb *arvb_criavazia(void)
{
   return NULL;
}

/* criar uma estrutura de Árvore Binária */
Arvb *arvb_cria(char c, Arvb *sae, Arvb *sad)
{
   Arvb *p = (Arvb *)malloc(sizeof(Arvb));
   p->info = c;
   p->esq = sae;
   p->dir = sad;
   return p;
}

/* Verifica se uma Árvore Binária está vazia*/
int arvb_vazia(Arvb *a)
{
   return (a == NULL);
}

/* Imprime uma Árvore Binária */
void arvb_imprime(Arvb *a)
{
   printf("<");
   if (!arvb_vazia(a))
   {
      printf("%c ", a->info); /* mostra a raiz */
      arvb_imprime(a->esq);   /* mostra a sae  */
      arvb_imprime(a->dir);   /* mostra a sad  */
   }
   printf(">");
}

/* Libera a memória ocupada pela Árvore Binária */
Arvb *arvb_libera(Arvb *a)
{
   if (!arvb_vazia(a))
   {
      arvb_libera(a->esq); /* libera a sae  */
      arvb_libera(a->dir); /* libera a sad  */
      free(a);             /*  libera a raiz */
   }
   return NULL;
}

/* Verifica se determinado caractere pertence a Árvore Binária */
int arvb_pertence(Arvb *a, char c)
{
   if (arvb_vazia(a))
      return 0; /* árvore vazia: não encontrou o caractere*/
   else
      return (a->info == c || arvb_pertence(a->esq, c) || arvb_pertence(a->dir, c));
}

/* Estrutura auxiliar para definir a altura de uma Árvore Binária */
static int max2(int a, int b)
{
   return (a > b) ? a : b;
}

/* Retorna a altura da Árvore Binária */
int arvb_altura(Arvb *a)
{
   if (arvb_vazia(a))
      return -1;
   else
      return 1 + max2(arvb_altura(a->esq), arvb_altura(a->dir));
}
