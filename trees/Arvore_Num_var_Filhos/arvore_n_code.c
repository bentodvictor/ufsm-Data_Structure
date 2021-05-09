#include <stdio.h>
#include "arvore_n.h"

int main(void)
{

    /* cria todos os nós como folhas */
    Arvn *a = arvn_cria('a');
    Arvn *b = arvn_cria('b');
    Arvn *c = arvn_cria('c');
    Arvn *d = arvn_cria('d');
    Arvn *e = arvn_cria('e');
    Arvn *f = arvn_cria('f');
    Arvn *g = arvn_cria('g');
    Arvn *h = arvn_cria('h');
    Arvn *i = arvn_cria('i');
    Arvn *j = arvn_cria('j');

    /* nesse ponto montamos a hierarquia da árvore */
    arvn_insere(c, d);
    arvn_insere(b, e);
    arvn_insere(b, c);
    arvn_insere(i, j);
    arvn_insere(g, i);
    arvn_insere(g, h);
    arvn_insere(a, g);
    arvn_insere(a, f);
    arvn_insere(a, b);

    printf("\n");
    arvn_imprime(a);
    printf("\n");
    printf("A altura atual da Árvore é: %d\n", arvn_altura(a));

    arvn_libera(a);
    return 0;
}
