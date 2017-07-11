#ifndef QUEUE_H
#define QUEUE_H

#include "NodeQueue.h"

// Estrutura que define o tipo Queue (fila encadeada)
typedef struct {
	NodeQueue *pStart;
	NodeQueue *pEnd;
	int size;
} Queue;

/*------------------------------------------------------------------------------
 Função:  verifica se a fila está vazia.
 Entrada: ponteiro para a fila a ser testada.
 Saída:   retorna 1 se a fila estiver vazia e 0 caso contrário.
------------------------------------------------------------------------------*/
int isQueueEmpty(Queue *pQueue);


/*------------------------------------------------------------------------------
 Função:  obtém o tamanho da fila.
 Entrada: ponteiro para a fila a ser testada.
 Saída:   retorna o tamanho atual da fila.
------------------------------------------------------------------------------*/
int getQueueSize(Queue *pQueue);


/*------------------------------------------------------------------------------
 Função:  inicializa uma fila, settando pStart e pEnd com NULL e size com 0.
 Entrada: ponteiro para a fila a ser criada.
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void initQueue(Queue *pQueue);


/*------------------------------------------------------------------------------
 Função:  insere um elemento na fila.
 Entrada: ponteiro para a fila a ser utilizada na operação.
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void enqueue(Queue *pQueue, QueueItem item);


/*------------------------------------------------------------------------------
 Função:  imprime os elementos da fila (função utilizada para Debug).
 Entrada: ponteiro para a fila a ser impressa.
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void printQueue(Queue *pQueue);


/*------------------------------------------------------------------------------
 Função:  libera a memória utilizada pela fila, desalocando todos os seus nodos.
 Entrada: ponteiro para a fila a ser desalocada.
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void freeQueue(Queue *pQueue);


/*------------------------------------------------------------------------------
 Função:  obtém o primeiro nodo da fila.
 Entrada: ponteiro para a fila a ser utilizada.
 Saída:   retorna o primeiro nodo da fila.
------------------------------------------------------------------------------*/
NodeQueue* frontQueue(Queue *pQueue);


/*------------------------------------------------------------------------------
 Função:  remove um nodo da fila (o primeiro nodo).
 Entrada: ponteiro para a fila a ser utilizada na operação.
 Saída:   retorna o nodo removido.
------------------------------------------------------------------------------*/
NodeQueue* dequeue(Queue *pQueue);

#endif


