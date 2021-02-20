#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"
#include "stack.h"
#include "list.h"
#include "queue.h"

void DFS_iter(Graph g, int start) {
  int visited[g->V];
  int u;
  for (int i = 0; i < g->V; i++) {
    visited[i] = 0;
  }
  Stack S = initStack(start);
  while(!isEmptyStack(S)) {
    u = top(S);
    S = pop(S);
    if (visited[u] == 0) {
      printf("%d ", u);
      visited[u] = 1;
    }
    List aux = g->adjLists[u];
    int i;
    while (aux != NULL) {
      i = aux->data;
      if (!visited[i])
        S = push(S, i);
      aux = aux->next;
    }
  }
}

void DFS_rec_help(Graph g, int u, int *visited) {
  printf("%d ", u);
  visited[u] = 1;
  
  List aux = g->adjLists[u];
  int i;
  while (aux != NULL) {
    i = aux->data;
    if (!visited[i])
      DFS_rec_help(g, i, visited);
    aux = aux->next;
  }
}

void DFS_rec(Graph g, int start) {
  int visited[g->V];
  for (int i = 0; i < g->V; i++) {
    visited[i] = 0;
  }
  DFS_rec_help(g, start, visited);
}

void BFS(Graph g, int start) {
  int d[g->V], p[g->V];
  char c[g->V];
  int current, successor;
  for (int i = 0; i < g->V; i++) {
    d[i] = 0;
    p[i] = -1;
    c[i] = 'a';
  }
  int pas = 0;
  for (int i = 0; i < g->V; i++) {
    if (c[i] != 'a') continue;
    Queue q = initQueue(i);
    c[i] = 'g';
    while (!isEmptyQueue(q)) {
      current = first(q);
      List aux = g->adjLists[current];
      while (aux != NULL) {
        successor = aux->data;
        if (c[successor] == 'a') {
          d[successor] = d[current] + 1;
          p[successor] = current;
          c[successor] = 'g';
          enqueue(q, successor);
        }
        aux = aux->next;
      }
      dequeue(q);
      c[current] = 'n';
      
    }
  }
  for (int i = 0; i < g->V; i++) {
    printf("%d: distanta -> %d, parinte -> %d\n", i, d[i], p[i]);
  }
}

void DFS_sort_top(Graph g, int current, int *pas, int *d, 
                  int *f, int *p, char *c) {
  int successor;
  *pas = *pas + 1;
  d[current] = *pas;
  c[current] = 'g';
  
  List aux = g->adjLists[current];
  while (aux != NULL) {
    successor = aux->data;
    if (c[successor] == 'a') {
      p[successor] = current;
      DFS_sort_top(g, successor, pas, d, f, p, c);
    }
    aux = aux->next;
  }
  c[current] = 'n';
  *pas = *pas + 1;
  f[current] = *pas;
}

void sort_top(Graph g) {
  int d[g->V], f[g->V], p[g->V];
  char c[g->V];
  for (int i = 0; i < g->V; i++) {
    d[i] = 0;
    c[i] = 'a';
    p[i] = -1;
  }
  int pas = 0;
  for (int i = 0; i < g->V; i++) {
    if (c[i] == 'a') {
      p[i] = -1;
      DFS_sort_top(g, i, &pas, d, f, p, c);
    }
  }
  int temp;
  int ord[g->V];
  printf("f:\n");
  for (int i = 0; i < g->V; i++) {
    ord[i] = i;
    printf("%d -> %d\n", i, f[i]);
  } 
  
  for (int i = 0; i < g->V - 1; i++) {
    for (int j = i; j < g->V; j++) {
      if (f[j] > f[i]) {
        temp = f[i];
        f[i] = f[j];
        f[j] = temp;
        temp = ord[i];
        ord[i] = ord[j];
        ord[j] = temp;
      }
    }
  }
  printf("\nOrdinea topologica este:\n");
  for (int i = 0; i< g->V ; i++) {
    printf("%d ", ord[i]);
  }
}

int main() {
	freopen("test1.in", "r", stdin);
	int V, type, i, x, y, M;
	scanf("%d %d", &V, &type);
	Graph graph = initGraph(V, type);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		graph = insertEdge(graph, x, y);
	}
	printf("1.DFS ITERATIV:\n");
	DFS_iter(graph, 0);
	printf("\n");
	DFS_iter(graph, 1);
	printf("\n");
	DFS_iter(graph, 2);
	printf("\n");
	DFS_iter(graph, 3);
	printf("\n");
	DFS_iter(graph, 4);
	printf("\n");
	DFS_iter(graph, 5);
	printf("\n");
	DFS_iter(graph, 6);
	
	printf("\n\n");
	
	printf("2.DFS RECURSIV:\n");
	DFS_rec(graph, 0);
	printf("\n\n");
	
	printf("3.BFS:\n");
	BFS(graph, 0);
	printf("\n\n");
	
	printf("4.Sortare topologica:\n");
	graph->type = 1;
	sort_top(graph);
	printf("\n\n");
	
	//drawGraph(graph, "graph1.dot");
	return 0;
}
