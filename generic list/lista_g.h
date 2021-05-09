
/* TAD: Lista Genérica */

/* Tipo Exportado */

typedef struct listag Listag;

/* função de inicialização: retorna uma lista genérica vazia */
Listag *lstg_inicializa(void);

/* inserção no início: retorna a lista genérica atualizada */
Listag *lstg_insere(Listag *l, void *p);

/* função percorre: percorre os elementos de uma lista genérica*/
void lstg_percorre(Listag *l, void (*cb)(void *));

/* função percorre: percorre os elementos de uma lista genérica, mas também passando dados*/
void lstg_percorre_dados(Listag *l, void (*cbd)(void *, void *), void *dado);

/* função percorre: percorre os elementos de uma lista genérica,
mas também passando dados e parando através de algum critério estabelecido pelo cliente*/
int lstg_percorre_para(Listag *l, int (*cbp)(void *, void *), void *dado);
