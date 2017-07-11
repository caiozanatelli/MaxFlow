////////////////////////////////////////////////////////////////////////////////
//																			  //
// 					UNIVERSIDADE FEDERAL DE MINAS GERAIS					  //
//																			  //
// Trabalho Prático 1 - Algoritmos e Estruturas de Dados III				  //
//																			  //
// Nome: 		Caio Felipe Zanatelli										  //
// Matrícula: 	2016006310													  //
//																			  //
//																		      //
////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

int main() {
	int V, E, F, C;
	scanf("%d %d %d %d", &V, &E, &F, &C);
	
	Graph g;
	initGraph(&g, V + 2, E + F + C);
	
	// Lê as arestas e constrói o grafo
	int i;
	int u, v, m;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &m);
		u++; v++;
		addEdge(&g, u, v, m);
	}
	
	// Identifica as sources (franquias) e as conecta à supersource
	int f;
	int source = 0, sink = V + 1;
	for (i = 0; i < F; i++) {
		scanf("%d", &f);
		f++;
		addEdge(&g, source, f, INF);
	}
	
	// Identifica as sinks (clientes) e as conecta à sink
	int c;
	for (i = 0; i < C; i++) {
		scanf("%d", &c);
		c++;
		addEdge(&g, c, sink, INF);
	}
	
	// Executa o algoritmo Dinic e imprime o fluxo máximo do grafo
	printf("%d\n", getMaxFlow(&g, source, sink));
	
	freeGraph(&g);
	
	return 0;
}

