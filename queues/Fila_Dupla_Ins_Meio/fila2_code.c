#include <stdio.h>
#include "fila2.h"

int main(void)
{
   int i, elem;
   float conteudo;

   Fila2 *f;
   f = fila2_cria();

   printf("\n Digite o numero de elementos da fila2: ");
   scanf("%d", &elem);
   for (i = 1; i <= elem; i++)
   {
      printf("\n Digite um elemento da fila2 a ser inserido no final da fila: ");
      scanf("%f", &conteudo);
      fila2_insere_fim(f, conteudo);
   }
   printf("\n Imprimindo a fila2: \n");
   fila2_imprime(f);

   /* conta elementos da fila */
   elem = fila2_tamanho(f);
   printf("Número de elementos da lista = %d\n", elem);
   printf("\n Digite um elemento da fila2 a ser inserido no meio da fila: ");
   scanf("%f", &conteudo);
   if (elem == 0 || elem == 1)
      fila2_insere_fim(f, conteudo);
   else
   {
      i = elem / 2;
      printf("Posição a ser inserido o elemento = %d\n", i);
      fila2_insere_meio(f, conteudo, i);
   }

   printf("\n Imprimindo a fila2 após a inserção no meio \n");
   fila2_imprime(f);

   fila2_libera(f);

   return 0;
}
