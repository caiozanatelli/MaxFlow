#ifndef GRAPH_H
#define GRAPH_H

#include "List.h"
#include "Edge.h"

#define INF	2147483647

// Estrutura que define o tipo Graph (Grafo)
typedef struct {
	List *adjList;
	Edge *edges;     
	int *arrayLevel; 
	int currentVertex;
	int size;
} Graph;

/*------------------------------------------------------------------------------
 Função:  inicializa o grafo. Define o número de vértices e arestas, além  de
		  inicializar as listas de adjacências e alocar o vetor de arestas e
		  o grafo de níveis (arrayLevel).		  
 Entrada: ponteiro para o grafo a ser inicializado, num. de vértices e arestas
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void initGraph(Graph *graph, int numVertices, int numArestas);


/*------------------------------------------------------------------------------
 Função:  insere uma aresta no grafo (residual) - insere tanto a aresta de ida
		  quanto a aresta reversa.		  
 Entrada: ponteiro para o grafo que será modificado e as informações da aresta
		  (origem, destino e capacidade);		
 Saída:   sem rotorno.
------------------------------------------------------------------------------*/
void addEdge(Graph *graph, int from, int to, int capacity);


/*------------------------------------------------------------------------------
 Função:  cálcula o fluxo máximo do vértice source ao sink (implementação Dinic).
 Entrada: ponteiro para o grafo a ser utilizado, vértice source e vértice sink.
 Saída:   retorna o fluxo máximo possível entre os vértices source e sink.
------------------------------------------------------------------------------*/
int getMaxFlow(Graph *graph, int source, int sink);


/*------------------------------------------------------------------------------
 Função:  Busca em largura (BFS). Constrói o vetor (grafo) de  níveis e verifica
		  se é possível transmitir mais fluxo do vérice source ao sink.
 Entrada: ponteiro para o grafo a ser utilizado, vértice source e vértice sink.
 Saída:   Retorna 1 se for possível transmitir mais fluxo do vértice source ao
		  vértice sink e 0 caso contrário.
------------------------------------------------------------------------------*/
int isMoreFlowPossible(Graph *graph, int source, int sink);


/*------------------------------------------------------------------------------
 Função:  Busca em profundidade (DFS). Envia múltimos fluxos utilizando o grafo
		  de níveis até que um fluxo bloqueador seja alcançado.
 Entrada: ponteiro para o grafo a ser utilizado, vértice atual da busca, fluxo
		  encontrado até o momento, vértice sink e um vetor de visitados para
		  controlar a DFS.
 Saída:   retorna o fluxo que a DFS conseguiu aumentar no grafo.
------------------------------------------------------------------------------*/
int sendFlow(Graph *graph, int currentVertex, int currentFlow, int sink, int *visited);


/*------------------------------------------------------------------------------
 Função:  libera a memória utilizada pelo grafo (listas de adjacências, grafo de
		  níveis e vetor de arestas).
 Entrada: ponteiro para a pilha a ser criada.
 Saída: sem rotorno.
------------------------------------------------------------------------------*/
void freeGraph(Graph *graph);

#endif


