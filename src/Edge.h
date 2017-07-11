#ifndef EDGE_H
#define EDGE_H

// Estrutura que define o tipo Edge (Aresta)
typedef struct {
	int fromVertex;
	int toVertex;
	int flow;
	int capacity;
} Edge;

/*------------------------------------------------------------------------------
 Função:  cria uma aresta de acordo com os parâmetros recebidos.
 Entrada: origem, destino, fluxo e capacidade da aresta.
 Saída:   variável do tipo Edge, a qual contém a aresta criada.
------------------------------------------------------------------------------*/
Edge makeEdge (int from, int to, int flow, int capacity);

#endif


