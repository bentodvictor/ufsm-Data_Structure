#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"

int main(void)
{

    char arquivo[81], nome_arq[100];
    FILE *letras;
    int c = 0;
    char aux;

    /* Cria arquivo principal */
    printf("Digite o nome do arquivo a ser criado: \n");
    scanf("%99s", nome_arq);

    letras = fopen(nome_arq, "wt");
    if (letras == NULL)
    {
        printf("\n Erro na Abertura do arquivo  \n");
        exit(1);
    }
    /* Usuario insere texto/ palavras no arquivo criado, até condição de parada <0> */
    printf("\nDigite uma palavra por linha (<0> para finalizar): \n");
    scanf("%80s", arquivo);
    while (arquivo[0] != '0')
    {
        fprintf(letras, "%80s\n", arquivo);
        scanf("%80s", arquivo);
    }
    fclose(letras);
    system("clear"); // Limpa a tela

    /* Inicializa a lista normal */
    Lista *l_normal;
    l_normal = lst_inicializa();
    letras = fopen(nome_arq, "rt");
    while ((c = getc(letras)) != EOF)
        if (c >= 97 && c <= 220)
        {
            l_normal = lst_insere(l_normal, c - 32);
        }
    fclose(letras);
    printf("\n\t < Lista Desordenada >\n");
    lst_imprime(l_normal);
    printf("\n");

    /* Inicializa a lista que ordena */
    Lista *l_ordena;
    l_ordena = lst_inicializa();
    letras = fopen(nome_arq, "rt");
    c = 0;
    while ((c = fgetc(letras)) != EOF)
    {
        aux = (c - 32);
        if (aux >= 65 && aux <= 90)
            l_ordena = lst_insere_ordenado(l_ordena, aux); //insere na lista alfabeticamente
    }
    fclose(letras);
    printf("\n\n");
    printf("\n\t < Lista Ordenada >\n");
    lst_imprime(l_ordena);
    printf("\n");

    return 0;
}
