#include <stdio.h>
#include "fila2.h"

struct lista2
{
   float info;
   struct lista2 *ant;
   struct lista2 *prox;
};
typedef struct lista2 Lista2;

struct fila2
{
   Lista2 *ini;
   Lista2 *fim;
};

/* criar uma estrutura de fila2 */
Fila2 *fila2_cria(void)
{
   Fila2 *f = (Fila2 *)malloc(sizeof(Fila2));
   f->ini = f->fim = NULL;
   return f;
}

/* função auxiliar: insere elemento no início da fila: retorna o novo nó inicial */
static Lista2 *ins2_ini(Lista2 *ini, float v)
{
   Lista2 *p = (Lista2 *)malloc(sizeof(Lista2));
   p->info = v;
   p->prox = ini;
   p->ant = NULL;
   if (ini != NULL) /* verifica se a fila2 não estava vazia */
      ini->ant = p;
   return p;
}

/* função auxiliar: insere elemento no fim da fila: retorna o novo nó final */
static Lista2 *ins2_fim(Lista2 *fim, float v)
{
   Lista2 *p = (Lista2 *)malloc(sizeof(Lista2));
   p->info = v;
   p->prox = NULL;
   p->ant = fim;
   if (fim != NULL) /* verifica se a fila2 não estava vazia */
      fim->prox = p;
   return p;
}

/* inserir um elemento no inicio da fila2 */
void fila2_insere_ini(Fila2 *f, float v)
{
   f->ini = ins2_ini(f->ini, v);
   if (f->fim == NULL) /* verifica se a fila2 estava vazia */
      f->fim = f->ini;
}

/* inserir um elemento no fim da fila2 */
void fila2_insere_fim(Fila2 *f, float v)
{
   f->fim = ins2_fim(f->fim, v);
   if (f->ini == NULL) /* verifica se a fila2 estava vazia */
      f->ini = f->fim;
}

/* função auxiliar: retira elemento no início da fila: retorna o novo nó inicial */
static Lista2 *ret2_ini(Lista2 *ini)
{
   Lista2 *p = ini->prox;
   if (p != NULL) /* verifica se a fila2 não ficou vazia */
      p->ant = NULL;
   free(ini);
   return p;
}

/* função auxiliar: retira elemento no fim da fila: retorna o novo nó final */
static Lista2 *ret2_fim(Lista2 *fim)
{
   Lista2 *p = fim->ant;
   if (p != NULL) /* verifica se a fila2 não ficou vazia */
      p->prox = NULL;
   free(fim);
   return p;
}

/* remover o elemento do início da fila2 */
float fila2_retira_ini(Fila2 *f)
{
   float v;
   if (fila2_vazia(f))
   {
      printf("Filha vazia.\n");
      exit(1); /* aborta programa */
   }
   v = f->ini->info;
   f->ini = ret2_ini(f->ini);
   if (f->ini == NULL) /* verifica se a fila2 ficou vazia */
      f->fim = NULL;
   return v;
}

/* remover o elemento do fim da fila2 */
float fila2_retira_fim(Fila2 *f)
{
   float v;
   if (fila2_vazia(f))
   {
      printf("Filha vazia.\n");
      exit(1); /* aborta programa */
   }
   v = f->fim->info;
   f->fim = ret2_fim(f->fim);
   if (f->fim == NULL) /* verifica se a fila2 ficou vazia */
      f->ini = NULL;
   return v;
}
/* verificar se a fila2 está vazia */
int fila2_vazia(Fila2 *f)
{
   return (f->ini == NULL);
}

/* liberar a estrutura de Fila2 */
void fila2_libera(Fila2 *f)
{
   Lista2 *q = f->ini;
   while (q != NULL)
   {
      Lista2 *t = q->prox;
      free(q);
      q = t;
   }
   free(f);
}

/* imprime: versão com lista */
void fila2_imprime(Fila2 *f)
{
   Lista2 *q;
   for (q = f->ini; q != NULL; q = q->prox)
      printf("%f\n", q->info);
}

/* retorna o tamanho da Fila */
int fila2_tamanho(Fila2 *f)
{
   int tamanho = 0;
   if (!fila2_vazia(f))
   {
      Lista2 *q = f->ini;
      while (q != NULL)
      {
         q = q->prox;
         tamanho++;
      }
   }
   return (tamanho);
}

/* insere no meio da fila */
void fila2_insere_meio(Fila2 *f, float v, int pos)
{
   Lista2 *p = (Lista2 *)malloc(sizeof(Lista2));
   Lista2 *q = f->ini;
   int i = 1;
   while (i <= pos)
   {
      p->ant = q;
      q = q->prox;
      i++;
   }
   q->ant = p;
   p->ant->prox = p;
   p->info = v;
   p->prox = q;
}
