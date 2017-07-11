#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Graph.h"

// Inicializa o grafo
void initGraph(Graph *graph, int numVertices, int numArestas) {
	graph->size = numVertices;
	graph->currentVertex = 0;
	graph->adjList = (List*) calloc(numVertices, sizeof(List));
	graph->arrayLevel = (int*) calloc(numVertices, sizeof(int));
	graph->edges = (Edge*) calloc(numArestas * 2, sizeof(Edge));
	
	int i;
	List *adjList;
	for (i = 0; i < numVertices; i++) {
		adjList = &graph->adjList[i];
		initList(adjList);
	}
}

// Insere uma aresta no grafo (aresta de ida e aresta reversa)
void addEdge(Graph *graph, int from, int to, int capacity) {
	Edge forwardEdge = makeEdge(from, to, 0, capacity);	
	Edge backEdge = makeEdge(to, from, 0, 0);
	
	pushBackList(&graph->adjList[from], graph->currentVertex);
	graph->edges[graph->currentVertex++] = forwardEdge;
	
	pushBackList(&graph->adjList[to], graph->currentVertex);
	graph->edges[graph->currentVertex++] = backEdge;
}

// Executa o algoritmo de Dinic e retorna o fluxo máximo possível no grafo
int getMaxFlow(Graph *graph, int source, int sink) {
	if (source == sink) {
		return -1;
	}
	
	int i, flow, maxFlow = 0;
	int visited[graph->size + 1];
	
	// Enquanto existir caminho de souce à sink
	while (isMoreFlowPossible(graph, source, sink)) {
		for (i = 0; i <= graph->size; i++) {
			visited[i] = 0;
		}
		
		// Enquanto não encontrar um fluxo bloqueador, aumenta o fluxo atual
		while ((flow = sendFlow(graph, source, INF, sink, visited)) != 0) {
			maxFlow += flow;
		}
	}
	
	return maxFlow;
}

// BFS para verificar se é possível passar mais fluxo da source à sink
// Prenche também os níveis dos vértices (arrayLevels), que será utilizado
// Pela DFS do Dinic
int isMoreFlowPossible(Graph *graph, int source, int sink) {
	int *level = graph->arrayLevel;
	int i;
	
	for (i = 0; i < graph->size; i++) {
		level[i] = -1;
	}
	
	level[source] = 0;
	
	Queue queue;
	initQueue(&queue);
	enqueue(&queue, source);
	
	while (!isQueueEmpty(&queue)) {
		NodeQueue *pNodeQueue = dequeue(&queue);
		int u = pNodeQueue->value;
		free(pNodeQueue);
		
		int i;
		for (i = 0; i < graph->adjList[u].size; i++) {
			Edge *edge = &graph->edges[graph->adjList[u].data[i]];
			
			// Se a aresta ainda não está no grafo de níveis e é possível passar
			// Passar mais fluxo, seu nível no grafo de levels é definido
			if (level[edge->toVertex] < 0 && edge->flow < edge->capacity) {
				level[edge->toVertex] = level[u] + 1;
				enqueue(&queue, edge->toVertex);
			}
		}
	}
	
	freeQueue(&queue);
	
	return (level[sink] != -1);
}

// DFS para enviar múltiplos fluxos ao longo do grafo de níveis até que um fluxo
// Bloqueador seja encontrado
int sendFlow(Graph *graph, int currentVertex, int currentFlow, int sink, int *visited) {
	if (currentVertex == sink) {
		return currentFlow;
	}
	
	int sizeAdjList = getListSize(&graph->adjList[currentVertex]);
	int *level = graph->arrayLevel;
	
	// Visita os vértices adjacentes um a um
	while (visited[currentVertex] < sizeAdjList) {
		int v = graph->adjList[currentVertex].data[visited[currentVertex]];
		Edge *edge = &graph->edges[v];
		
		// Se é uma aresta válida no grafo de níveis
		if (level[edge->toVertex] == level[currentVertex] + 1 && edge->flow < edge->capacity) {
			
			// Encontra o menor fluxo de currentVertex à sink
			int minFlow = currentFlow;
			if (edge->capacity - edge->flow < minFlow) {
				minFlow = edge->capacity - edge->flow;
			}
			
			int tempFlow = sendFlow(graph, edge->toVertex, minFlow, sink, visited);
			
			// Se o fluxo é maior que 0
			if (tempFlow > 0) {
				
				// adiciona fluxo na aresta atual e subtrai da aresta reversa
				edge->flow += tempFlow; 
				graph->edges[v ^ 1].flow -= tempFlow; // Aresta reversa
				
				return tempFlow;
			}
		}
		visited[currentVertex]++;
	}
	
	return 0;
}

// Libera memória utilizada pelo grafo
void freeGraph(Graph *graph) {
	free(graph->arrayLevel);
	free(graph->edges);
	
	int i;
	for (i = 0; i < graph->size; i++) {
		List adjList = graph->adjList[i];
		freeList(&adjList);
	}
	
	free(graph->adjList);
}
