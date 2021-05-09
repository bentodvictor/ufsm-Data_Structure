
/* TAD: Lista */

/* Tipo Exportado */

typedef struct pilha Pilha;

/* criar uma estrutura de pilha */
Pilha* pilha_cria (void);

/* inserir um elemento no topo (push) */
void pilha_push (Pilha* p, float v);

/* remover o elemento do topo (pop) */
float pilha_pop (Pilha* p);

/* verificar se a pilha está vazia */
int pilha_vazia (Pilha* p);

/* liberar a estrutura de pilha */
void pilha_libera (Pilha* p);

/* imprime: versão com lista */
void pilha_imprime (Pilha* p);

/* concatena: versão recursiva com lista */
void pilha_concatena (Pilha* p1, Pilha* p2);

/* concatena: versão com lista com recursão  */
void pilha_concatena_rec (Pilha* p1, Pilha* p2);
