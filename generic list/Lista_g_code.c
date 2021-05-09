#include <stdio.h>
#include "lista_g.h"

struct ponto
{
   float x, y;
};
typedef struct ponto Ponto;

int NP;   /* variável global para ser utilizada como contador */
Ponto CG; /* variável auxiliar para ser utilizada como acumulador na função centro_geom */
float TOL = 1e-5f;

struct cgd
{
   int n;
   Ponto p;
};
typedef struct cgd Cgd;

static Listag *insere_ponto(Listag *l, float x, float y)
{
   Ponto *p = (Ponto *)malloc(sizeof(Ponto));
   p->x = x;
   p->y = y;
   return lstg_insere(l, p);
}

/* Função Callback para associar a informação ao ponteiro genérico e imprimir os elementos*/

static void imprime_ponto(void *info)
{
   Ponto *p = (Ponto *)info;
   printf("\nPonto %d  x = %f e y = %f \n", NP, p->x, p->y);
   NP++;
}

/* Função Callback para associar a informação ao ponteiro genérico e calcular o centro geométrico dos pontos*/
static void centro_geom(void *info)
{
   Ponto *p = (Ponto *)info;
   CG.x += p->x;
   CG.y += p->y;
   NP++;
}

/* Função Callback para associar a informação ao ponteiro genérico e calcular o centro geométrico dos pontos, com passagem de dados*/
static void centro_geom_dados(void *info, void *dado)
{
   Ponto *p = (Ponto *)info;
   Cgd *cg = (Cgd *)dado;
   cg->p.x += p->x;
   cg->p.y += p->y;
   cg->n++;
}

static int igualdade(void *info, void *dado)
{
   Ponto *p = (Ponto *)info;
   Ponto *q = (Ponto *)dado;
   if (fabs(p->x - q->x) < TOL && fabs(p->y - q->y) < TOL)
      return 1;
   else
      return 0;
}

static int pertence(Listag *l, float x, float y)
{
   Ponto q;
   q.x = x;
   q.y = y;
   return lstg_percorre_para(l, igualdade, &q);
}

int main(void)
{

   Listag *l;
   Cgd cg;

   l = lstg_inicializa();

   l = insere_ponto(l, 23.0, 23.5);
   l = insere_ponto(l, 45.0, 45.5);
   l = insere_ponto(l, 56.0, 56.5);
   l = insere_ponto(l, 78.0, 78.5);
   NP = 1;
   lstg_percorre(l, imprime_ponto);

   NP = 0;
   CG.x = 0.0f;
   CG.y = 0.0f;
   lstg_percorre(l, centro_geom);
   CG.x /= NP;
   CG.y /= NP;
   printf("\nCentro Geométrico x = %f e y = %f \n", CG.x, CG.y);
   printf("\n Calculando o Centro Geométrico com passagem de dados para a função callback \n");

   cg.p.x = 0.0f;
   cg.p.y = 0.0f;
   cg.n = 0;

   lstg_percorre_dados(l, centro_geom_dados, &cg);

   cg.p.x /= cg.n;
   cg.p.y /= cg.n;
   printf("\nCentro Geométrico x = %f e y = %f \n", cg.p.x, cg.p.y);
   printf("\n Verifica se o elemento (45.0 e 45.5) está na lista \n");

   if (pertence(l, 45.0f, 45.5f) == 1)
      printf("\n O elemento (45.0 e 45.5) está na lista \n");
   else
      printf("\n O elemento (45.0 e 45.5) não está na lista \n");

   printf("\n Verifica se o elemento (45.5 e 45.5) está na lista \n");
   if (pertence(l, 45.5f, 45.5f) == 1)
      printf("\n O elemento (45.5 e 45.5) está na lista \n");
   else
      printf("\n O elemento (45.5 e 45.5) não está na lista \n");

   return 0;
}
