
/* TAD: Árvore Binária */

/* Tipo Exportado */
typedef struct arvb Arvb;

/* criar uma estrutura de Árvore Binária Vazia*/
Arvb *arvb_criavazia(void);

/* criar uma estrutura de Árvore Binária */
Arvb *arvb_cria(char c, Arvb *sae, Arvb *sad);

/* Verifica se uma Árvore Binária está vazia*/
int arvb_vazia(Arvb *a);

/* Imprime uma Árvore Binária */
void arvb_imprime(Arvb *a);

/* Libera a memória ocupada pela Árvore Binária */
Arvb *arvb_libera(Arvb *a);

/* Verifica se determinado caractere pertence a Árvore Binária */
int arvb_pertence(Arvb *a, char c);

/* Retorna a altura da Árvore Binária */
int arvb_altura(Arvb *a);
