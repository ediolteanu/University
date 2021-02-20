#include "graph.h"

Graph initGraph(int V, int type) {
	Graph graph;
	graph = malloc(sizeof(struct graph));
	graph->V = V;
	graph->type = type;
	graph->dist = calloc(V, sizeof(int));
	graph->adjLists = calloc(V, sizeof(List));
	return graph;
}

Graph insertEdge(Graph g, int u, int v) {
	g->adjLists[u] = addLast(g->adjLists[u], v);
	if (g->type == 0)
		g->adjLists[v] = addLast(g->adjLists[v], u);
	return g;
}

//Functie care va deseneaza graful
void drawGraph(Graph g, char *name)
{
	int i, j;
	FILE *stream;
	char *buffer;
	List tmp;

	if (g == NULL || name == NULL)
		return;
	stream = fopen(name, "w");
	fprintf(stream, "graph G {\n");
	fprintf(stream, "    node [fontname=\"Arial\", shape=circle, style=filled, fillcolor=yellow];\n");
	for (i = 0; i < g->V; i++) {
		tmp = g->adjLists[i];
		while (tmp != NULL) {
			if (tmp->data > i)
				fprintf(stream, "    %d -- %d;\n", i, tmp->data);
			tmp = tmp->next;
		}
	}
	fprintf(stream, "}\n");
	fclose(stream);
	buffer = (char*) malloc(SIZE*sizeof(char));
	sprintf(buffer, "dot %s | neato -n -Tpng -o graph.png", name);
	system(buffer);
	free(buffer);
}
