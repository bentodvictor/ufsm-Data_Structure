#include <stdio.h>
#include "pilha.h"


int main (void) {
int i, elem;
float conteudo;

Pilha* l1;
Pilha* l2;
l1 = pilha_cria();
l2 = pilha_cria();
Pilha* l1_r;
Pilha* l2_r;
l1_r = pilha_cria();
l2_r = pilha_cria();

printf("\n Digite o numero de elementos da pilha1: ");
scanf("%d", &elem);
for (i=1 ; i <= elem ; i++)
{
 printf("\n Digite o elemento %d da pilha1: ",i);
 scanf("%f", &conteudo);
 pilha_push (l1, conteudo);
 pilha_push (l1_r, conteudo);
}

printf("\n Digite o numero de elementos da pilha2: ");
scanf("%d", &elem);
for (i=1 ; i <= elem ; i++)
{
 printf("\n Digite o elemento %d da pilha2: ",i);
 scanf("%f", &conteudo);
 pilha_push (l2, conteudo);
 pilha_push (l2_r, conteudo);
}
printf("\n Imprimindo pilha1\n");
pilha_imprime(l1);
printf("\n Imprimindo pilha2\n");
pilha_imprime(l2);
printf("\n Concatenando pilha1 e pilha 2 sem recursão\n");
pilha_concatena(l1,l2);
printf("\n Imprimindo pilha concatenada \n");
pilha_imprime(l1);
printf("\n Concatenando pilha1 e pilha 2 com recursão\n");
pilha_concatena_rec(l1_r,l2_r);
printf("\n Imprimindo pilha concatenada \n");
pilha_imprime(l1_r);

pilha_libera(l1);
pilha_libera(l2);
pilha_libera(l1_r);
pilha_libera(l2_r);
return 0;
}

