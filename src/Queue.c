#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Inicializa fila
void initQueue(Queue *pQueue) {
    pQueue->pStart = NULL;
    pQueue->size = 0;
}

// Insere um elemento no fim da fila
void enqueue(Queue *pQueue, QueueItem item) {
	NodeQueue *pNodeQueue = (NodeQueue*) malloc(sizeof(NodeQueue));
	
	if (isQueueEmpty(pQueue)) {
		pQueue->pStart = pNodeQueue;
	}
	else {
		pQueue->pEnd->pNext = pNodeQueue;
	}
	
	pNodeQueue->value = item;
	pNodeQueue->pNext = NULL;
	pQueue->pEnd = pNodeQueue;
	pQueue->size++;
}

// Retorna o primeiro elemento da fila
NodeQueue* front(Queue *pQueue) {
	return pQueue->pStart;
}

// Remove o primeiro elemento da fila, caso ela não esteja vazia
NodeQueue* dequeue(Queue *pQueue) {
    if (isQueueEmpty(pQueue)) {
        return NULL;
    }
    
    NodeQueue *pNodeQueue = pQueue->pStart;
    pQueue->pStart = pNodeQueue->pNext;
    pQueue->size--;
    
    return pNodeQueue;
}

// Imprime os valores dos nodos da fila (utilizado para Debug)
void printQueue(Queue *pQueue) {
    if (isQueueEmpty(pQueue)) {
        printf("Queue vazia. \n");
    }
    else {
        NodeQueue *pNodeQueueAtual = pQueue->pStart;
        while (pNodeQueueAtual != NULL) {
            printf("%d ", pNodeQueueAtual->value);
            pNodeQueueAtual = pNodeQueueAtual->pNext;
        }
    }
}

// Libera a memória utilizada pela fila, removendo todos os seus nodos
void freeQueue(Queue *pQueue) {
	NodeQueue *pNodeQueue = NULL;
	while ((pNodeQueue = dequeue(pQueue)) != NULL) {
		free(pNodeQueue);
	}
}

// Retorna o tamanho da fila
int getQueueSize(Queue *pQueue) {
	return pQueue->size;
}

// Retorna 1 se a fila estiver vazia e 0 caso contrário
int isQueueEmpty(Queue *pQueue) {
    return (pQueue->size == 0);
}
