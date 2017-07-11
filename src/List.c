#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// Retorna 1 se a lista estiver 0 e falso caso contrário
int isListEmpty(List *pList) {
    return (pList->size == 0);
}

// Retorna o tamanho atual da lista
int getListSize(List *pList) {
	return pList->size;
}

// Inicializa a lista
void initList(List *pList) {
	pList->capacity = INITIAL_CAPACITY;
	pList->data = (int*) calloc(pList->capacity, sizeof(ListItem));
    pList->size = 0;
}

// Insere um novo elemento no fim da lista
// Se necessário, aumenta o tamanho da lista dinâmicamente
void pushBackList(List *pList, ListItem item) {
	if (pList->size == pList->capacity) {
		pList->capacity *= 2;
		pList->data = (int*) realloc(pList->data, pList->capacity * sizeof(ListItem));
	}
	
	pList->data[pList->size++] = item;
}

// Libera a memória utilizada pela lista
void freeList(List *pList) {
	free(pList->data);
}

