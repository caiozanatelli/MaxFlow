#ifndef NODE_QUEUE_H
#define NODE_QUEUE_H

typedef int QueueItem;

// Estrutura que define um nodo de uma fila (Queue)
typedef struct NodeQueue {
	QueueItem value;
	struct NodeQueue *pNext;
} NodeQueue;

#endif


