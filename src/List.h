#ifndef LIST_H
#define LIST_H

#define INITIAL_CAPACITY 10;

typedef int ListItem;

// Estrutura que define o tipo List (uma lista dinâmica por arranjos)
typedef struct {
	ListItem *data;
	int capacity;
	int size;
} List;

/*------------------------------------------------------------------------------
 Função:  verifica se a lista está vazia.
 Entrada: ponteiro para a list a ser verificada.
 Saída:   retorna 1 se a lista estiver vazia e 0 caso contrário.
------------------------------------------------------------------------------*/
int isListEmpty(List *pList);


/*------------------------------------------------------------------------------
 Função:  obtém o tamanho atual da lista.
 Entrada: ponteiro para a lista a ser verificada.
 Saída:   retorna o tamanho da lista em questão.
------------------------------------------------------------------------------*/
int getListSize(List *pList);


/*------------------------------------------------------------------------------
 Função:  inicializa uma lista, alocando o vetor de dados com a capacidade 
          inicial e settando a capacidade e o tamanho da lista.
 Entrada: ponteiro para a lista a ser inicializada.
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void initList(List *pList);


/*------------------------------------------------------------------------------
 Função:  insere um elemento no fim da lista.
 Entrada: ponteiro para a pilha a ser utilizada.
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void pushBackList(List *pList, ListItem item);


/*------------------------------------------------------------------------------
 Função:  libera a memória utilizada pela lista.
 Entrada: ponteiro para a lista a ser liberada.
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void freeList(List *pList);

#endif


