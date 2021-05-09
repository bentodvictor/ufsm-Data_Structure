#include <stdio.h>
#include "arvore_bin.h"

struct arvb
{
    char info;
    struct arvb *esq;
    struct arvb *dir;
};

int main(void)
{

    Arvb *a;

    a = arvb_cria('a',
                  arvb_cria('b',
                            arvb_criavazia(),
                            arvb_cria('d', arvb_criavazia(), arvb_criavazia())),
                  arvb_cria('c',
                            arvb_cria('e', arvb_criavazia(), arvb_criavazia()),
                            arvb_cria('f', arvb_criavazia(), arvb_criavazia())));
    arvb_imprime(a);
    printf("\n");
    printf("A altura atual da Árvore é: %d\n", arvb_altura(a));
    /* Acrescentando alguns nós na árvore */
    a->esq->esq = arvb_cria('x',
                            arvb_cria('y', arvb_criavazia(), arvb_criavazia()),
                            arvb_cria('z', arvb_criavazia(), arvb_criavazia()));
    printf("Imprimindo a Árvore Binária após a inserção dos carcteres x,y e z\n");
    arvb_imprime(a);
    printf("\n");
    if (arvb_pertence(a, 'x'))
        printf("O caractere x, pertence a Árvore Binária\n");
    else
        printf("O caractere x, não pertence a Árvore Binária\n");
    /* Retirando alguns nós na árvore */
    a->dir->esq = arvb_libera(a->dir->esq);
    printf("Imprimindo a Árvore Binária após retirada dos caracteres abaixo do ramo esquerdo de c\n");
    arvb_imprime(a);
    printf("\n");
    if (arvb_pertence(a, 'e'))
        printf("O caractere e, pertence a Árvore Binária\n");
    else
        printf("O caractere e, não pertence a Árvore Binária\n");
    printf("A altura atual da Árvore é: %d\n", arvb_altura(a));
    arvb_libera(a);
    return 0;
}
