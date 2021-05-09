
/* TAD: Lista */

/* Tipo Exportado */

typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista *lst_inicializa(void);

/* inser��o no in�cio: retorna a lista atualizada */
Lista *lst_insere(Lista *l, char i);

/* fun��o imprime: imprime valores dos elementos */
void lst_imprime(Lista *l);

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int lst_vazia(Lista *l);

/* fun��o free */
void lst_libera(Lista *l);

/* Cria Lista */
Lista *lst_cria(char v);

/* fun��o de ordenar de forma alfab�tica */
Lista *lst_insere_ordenado(Lista *l, char v);
