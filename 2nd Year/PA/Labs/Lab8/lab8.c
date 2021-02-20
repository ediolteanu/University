#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structura pentru lista si functiile aferente
typedef struct list {
	int data;
	struct list *prev, *next;
}*List;


List initList(int data)
{
	List list;

	list = (List) malloc(sizeof(struct list));
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
	return list;
}

List addFirst(List list, int data)
{
	List new;

	if (list == NULL)
		return initList(data);
	new = initList(data);
	new->next = list;
	list->prev = new;
	return new;
}

List addLast(List list, int data)
{
	List new, tmp;

	if (list == NULL)
		return initList(data);
	new = initList(data);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return list;
}

List deleteItem(List l, int data) {
	if(l == NULL) {
		return NULL;
	} else {
		List tmp = l, prev;
		if(tmp->data == data) {
			l = l->next;
			free(tmp);
			l->prev = NULL;
			return l;
		} else {
			prev = tmp;
			tmp = tmp->next;
		}
		while(tmp != NULL) {
			if(tmp->data == data) {
				prev->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = prev;
				free(tmp);
				return l;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		return l;
	}
}

List freeList(List list)
{
	List tmp;

	if (list == NULL)
		return list;
	while (list != NULL) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return NULL;
}

//structura pentru coada si functiile aferente
typedef struct node {
	int data;
	struct node *next;
}Node;

typedef struct queue {
	Node *head, *tail;
	int size;
}*Queue;

Node *initNode(int data)
{
	Node *node;

	node = malloc(sizeof(struct node));
	node->data = data;
	node->next = NULL;
	return node;
}

Node *freeNode(Node *node)
{
	if (node) {
		free(node);
	}
	return NULL;
}

Queue initQueue(int data)
{
	Queue queue;

	queue = malloc(sizeof(struct queue));
	queue->head = queue->tail = initNode(data);
	queue->size = 1;
	return queue;
}

int isEmptyQueue(Queue queue) {
	if (queue == NULL || queue->head == NULL || queue->size == 0)
		return 1;
	return 0;
}

Queue enqueue(Queue queue, int data)
{
	Node *node;

	if (isEmptyQueue(queue)) {
		if (queue == NULL)
			return initQueue(data);
		free(queue);
		return initQueue(data);
	}
	node = initNode(data);
	queue->tail->next = node;
	queue->tail = node;
	queue->size++;
	return queue;
}

Queue dequeue(Queue queue)
{
	Node *temp;

	if (!isEmptyQueue(queue)) {
		temp = queue->head;
		queue->head = queue->head->next;
		temp = freeNode(temp);
		queue->size--;
	}
	return queue;
}

int first(Queue queue) {
	if (!isEmptyQueue(queue)) {
		return queue->head->data;
	} else {
		return -1;
	}
}

Queue freeQueue(Queue queue) {
	while (!isEmptyQueue(queue)) {
		queue = dequeue(queue);
	}
	if (queue)
		free(queue);
	return NULL;
}


//structura pentru graf si functiile aferente
typedef struct graph {
	int V;
	List *adjLists;
}*Graph;

Graph initGraph(int V) {
	Graph graph;
	graph = malloc(sizeof(struct graph));
	graph->V = V;
	graph->adjLists = calloc(V, sizeof(List));
	return graph;
}

Graph insertEdge(Graph g, int u, int v) {
	g->adjLists[u] = addLast(g->adjLists[u], v);

	return g;
}

// este creat un nou graf, transpus
Graph transposeGraph(Graph g) {
  Graph transposed = initGraph(g->V);
  for (int i = 0; i < g->V; i++) {
    List aux = g->adjLists[i];
    while (aux != NULL) {
      transposed->adjLists[aux->data] = addLast(transposed->adjLists[aux->data], i);
      aux = aux->next;
    }
  }
  return transposed;
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

void sort_top(Graph g, int type) {
  int d[g->V], f[g->V], p[g->V];
  char c[g->V];
  for (int i = 0; i < g->V; i++) {
    d[i] = 0;
    c[i] = 'a';
    p[i] = -1;
  }
  int pas = 0;
  if (type == 0) {
    for (int i = 0; i < g->V; i++) {
      if (c[i] == 'a') {
        p[i] = -1;
        DFS_sort_top(g, i, &pas, d, f, p, c);
      }
    }
  }
  
  if (type == 1) {
    for (int i = g->V - 1; i >= 0; i--) {
      if (c[i] == 'a') {
        p[i] = -1;
        DFS_sort_top(g, i, &pas, d, f, p, c);
      }
    }
  }
  int temp;
  int ord[g->V];
  printf("Nod -> d, f\n");
  for (int i = 0; i < g->V; i++) {
    ord[i] = i;
    printf("%c -> %d, %d\n", i + 97, d[i], f[i]);
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
  for (int i = 0; i < g->V ; i++) {
    printf("%c ", ord[i] + 97);
  }
}

void CTC_help(Graph g, int i, int *pas, int *ord, int *d, int *f, char *c) {
  int successor;
  *pas = *pas + 1;
  d[i] = *pas;
  printf(" %c", i + 97);
  c[i] = 'g';
  List aux = g->adjLists[i];
  while (aux != NULL) {
    successor = aux->data;
    if (c[successor] == 'a') {
      CTC_help(g, successor, pas, ord, d, f, c);
    }
    aux = aux->next;
  }
  c[i] = 'n';
  *pas = *pas + 1;
  f[i] = *pas;
}

void CTC(Graph g) {
  int d[g->V], f[g->V], p[g->V];
  char c[g->V];
  int current, successor;
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
  printf("Nod -> d, f\n");
  for (int i = 0; i < g->V; i++) {
    ord[i] = i;
    printf("%c -> %d, %d\n", i + 97, d[i], f[i]);
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
  for (int i = 0; i < g->V ; i++) {
    printf("%c ", ord[i] + 97);
  }
  printf("\n\n");
  
  Graph transposed = transposeGraph(g);
  
  for (int i = 0; i < transposed->V; i++) {
    c[i] = 'a';
    d[i] = 0;
    f[i] = -1;
    p[i] = -1;
  }
  
  pas = 0;
  for (int i = 0, k = 0; i < transposed->V; i++) {
    temp = ord[i];
    if (c[temp] == 'a') {
      printf("CTC %d:", ++k);
      CTC_help(transposed, temp, &pas, ord, d, f, c);
      printf("\n");
    }
  }
}

int main() {
  int V = 7;
  Graph graph1 = initGraph(V);
  // am notat literele din graf, de la a la g cu numere de la 0 la 6
  // introduc muchiile pentru ordine alfabetica
  graph1 = insertEdge(graph1, 0, 1); 
  graph1 = insertEdge(graph1, 0, 3);
  graph1 = insertEdge(graph1, 0, 6);
  graph1 = insertEdge(graph1, 1, 6);
  graph1 = insertEdge(graph1, 3, 4);
  graph1 = insertEdge(graph1, 5, 4);
  graph1 = insertEdge(graph1, 6, 2);
  
  Graph graph2 = initGraph(V);
  // am notat literele din graf, de la a la g cu numere de la 0 la 6
  // introduc muchiile pentru ordine invers alfabetica
  graph2 = insertEdge(graph2, 0, 6); 
  graph2 = insertEdge(graph2, 0, 3);
  graph2 = insertEdge(graph2, 0, 1);
  graph2 = insertEdge(graph2, 1, 6);
  graph2 = insertEdge(graph2, 3, 4);
  graph2 = insertEdge(graph2, 5, 4);
  graph2 = insertEdge(graph2, 6, 2);
  
  printf("2.Sortare topologica:\n");
  printf("Alfabetica:\n");
  sort_top(graph1, 0);
  printf("\n\nInvers alfabetica:\n");
  sort_top(graph2, 1);
  printf("\n\n");
  
  V = 16; 
  Graph graph3 = initGraph(V);
  // am notat literele din graf, de la a la g cu numere de la 0 la 6
  // introduc muchiile pentru ordine invers alfabetica
  graph3 = insertEdge(graph3, 0, 1);
  graph3 = insertEdge(graph3, 0, 6);
  graph3 = insertEdge(graph3, 1, 2);
  graph3 = insertEdge(graph3, 1, 6);
  graph3 = insertEdge(graph3, 2, 4);
  graph3 = insertEdge(graph3, 3, 2);
  graph3 = insertEdge(graph3, 3, 5);
  graph3 = insertEdge(graph3, 4, 3);
  graph3 = insertEdge(graph3, 6, 7);
  graph3 = insertEdge(graph3, 8, 0);
  graph3 = insertEdge(graph3, 8, 9);
  graph3 = insertEdge(graph3, 8, 11);
  graph3 = insertEdge(graph3, 9, 10);
  graph3 = insertEdge(graph3, 10, 8);
  graph3 = insertEdge(graph3, 10, 12);
  graph3 = insertEdge(graph3, 11, 10);
  graph3 = insertEdge(graph3, 12, 13);
  graph3 = insertEdge(graph3, 13, 14);
  graph3 = insertEdge(graph3, 14, 12);
  graph3 = insertEdge(graph3, 14, 15);
  
  printf("4.Componente tare conexe:\n");
  CTC(graph3);
  return 0;
}

