
/* TAD: Árvore Número Variável de Filhos */

/* Tipo Exportado */
typedef struct arvn Arvn;

/* criar uma estrutura de Árvore com número variável de filhos */
Arvn *arvn_cria(char c);

/* insere um elemento numa Árvore com número variável de filhos */
void arvn_insere(Arvn *a, Arvn *sa);

/* Imprime uma Árvore com número variável de filhos */
void arvn_imprime(Arvn *a);

/* Libera a memória ocupada pela Árvore com número variável de filhos */
void arvn_libera(Arvn *a);

/* Verifica se determinado caractere pertence a Árvore com número variável de filhos  */
int arvn_pertence(Arvn *a, char c);

/* Retorna a altura da Árvore com número variável de filhos */
int arvn_altura(Arvn *a);
