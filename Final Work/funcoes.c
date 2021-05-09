#include <stdio.h>
#include "func.h"

struct lista
{
    char info;
    struct lista *prox;
};

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista *lst_inicializa(void)
{
    return NULL;
}

/* inser��o no in�cio: retorna a lista atualizada */
Lista *lst_insere(Lista *l, char i)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* fun��o imprime: imprime valores dos elementos */
void lst_imprime(Lista *l)
{
    Lista *p = l;
    if (lst_vazia(p))
        printf("\nLISTA VAZIA\n");

    else
        for (p; p != NULL; p = p->prox) /* vari�vel auxiliar para percorrer a lista */
            if (p != NULL && p->info != ' ')
                printf("%2c\n", p->info);
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int lst_vazia(Lista *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

/* Libera Lista */
void lst_libera(Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
        free(p);
        /* libera a mem�ria apontada por p */
        p = t;
        /* faz p apontar para o pr�ximo */
    }
}

/* Cria Lista */
Lista *lst_cria(char v)
{
    Lista *p = (Lista *)malloc(sizeof(Lista));
    p->info = v;
    return p;
}

/* inser��o na lista em ordem crescente: retorna a lista aualizadada e ordenada */
Lista *lst_insere_ordenado(Lista *l, char v)
{
    Lista *novo = lst_cria(v); /* cria novo n� */
    Lista *ant = NULL;         /* ponteiro para elemento anterior */
    Lista *p = l;              /* ponteiro para percorrer a lista*/

    /* procura posi��o de inser��o */
    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }
    /* insere elemento */
    if (ant == NULL)
    { /* insere elemento no in�cio */
        novo->prox = l;
        l = novo;
    }
    else
    { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}
