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

    printf("\n Retirando o elemento %f do início fila2: \n", fila2_retira_ini(f));
    printf("\n Imprimindo a fila2 após a retirada \n");
    fila2_imprime(f);

    printf("\n Retirando o elemento %f do fim fila2: \n", fila2_retira_fim(f));
    printf("\n Imprimindo a fila2 após a retirada \n");
    fila2_imprime(f);

    printf("\n Digite um elemento da fila2 a ser inserido no início da fila: ");
    scanf("%f", &conteudo);
    fila2_insere_ini(f, conteudo);

    printf("\n Imprimindo a fila2 após a inserção no inicio \n");
    fila2_imprime(f);

    fila2_libera(f);

    return 0;
}
