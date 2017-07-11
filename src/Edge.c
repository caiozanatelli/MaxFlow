#include "Edge.h"

// Cria uma aresta (e a retorna) com base nos parâmetros recebidos
Edge makeEdge (int from, int to, int flow, int capacity) {
	Edge edge;
	edge.fromVertex = from;
	edge.toVertex = to;
	edge.flow = flow;
	edge.capacity = capacity;
	
	return edge;
}
