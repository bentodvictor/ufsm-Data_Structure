
/* TAD: Fila2 */

/* Tipo Exportado */

typedef struct fila2 Fila2;

/* criar uma estrutura de fila2 */
Fila2 *fila2_cria(void);

/* inserir um elemento no início da fila2 */
void fila2_insere_ini(Fila2 *f, float v);

/* inserir um elemento no fim da fila2 */
void fila2_insere_fim(Fila2 *f, float v);

/* remover o elemento do início da fila2 */
float fila2_retira_ini(Fila2 *f);

/* remover o elemento do fim da fila2 */
float fila2_retira_fim(Fila2 *f);

/* verificar se a Fila2 está vazia */
int fila2_vazia(Fila2 *f);

/* liberar a estrutura de Fila2 */
void fila2_libera(Fila2 *f);

/* imprime: versão com lista */
void fila2_imprime(Fila2 *f);

/* retorna o tamanho da Fila */
int fila2_tamanho(Fila2 *f);

/* insere no meio da fila */
void fila2_insere_meio(Fila2 *f, float v, int pos);
