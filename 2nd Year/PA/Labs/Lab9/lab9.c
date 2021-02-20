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
	int type; // 0 - neorientat, 1 - orientat
	List *adjLists;
}*Graph;

Graph initGraph(int V, int type) {
	Graph graph;
	graph = malloc(sizeof(struct graph));
	graph->V = V;
	graph->type = type;
	graph->adjLists = calloc(V, sizeof(List));
	return graph;
}

Graph insertEdge(Graph g, int u, int v) {
	g->adjLists[u] = addLast(g->adjLists[u], v);
  if (g->type == 0) { // daca este neorientat se adauga si muchia inversa
    g->adjLists[v] = addLast(g->adjLists[v], u);
  }
	return g;
}

void pct_art_help(Graph g, int current, int *pas, int *d, 
                  int *low, int *p, int *subarb, int *art, char *c) {
  int succ;
  c[current] = 'g';
  d[current] = *pas;
  low[current] = *pas;
  printf("%d -> d(%d) = %d, low(%d) = %d, c(%d) = g\n", *pas, current, *pas, current, *pas, current);
  *pas = *pas + 1;
  
  List aux = g->adjLists[current];
  while (aux != NULL) {
    succ = aux->data;
    if (c[succ] == 'a') {
      p[succ] = current;
      subarb[current] = subarb[current] + 1;
      printf("subarb(%d) = %d, p(%d) = %d\n\n", current, subarb[current], succ, current);
      pct_art_help(g, succ, pas, d, low, p, subarb, art, c);
      
      if (low[succ] < low[current]) {
        low[current] = low[succ];
      }
      
      printf("low(%d) = %d (min(low(%d), low(%d)))\n", current, low[current], current, current);
      printf("p(%d) != null si low(%d) = %d >= d(%d) = %d ?\n", current, succ, low[succ], current, d[current]);
      if ((p[current] != -1) && (d[current] <= low[succ])) {
        printf("Da, atunci art(%d) = 1\n", current);
        art[current] = 1;
      } else {
        printf("Nu, atunci art(%d) ramane neschimbat\n", current);
      }
    } else {
      printf("p(%d) != null si low(%d) = %d > d(%d) = %d ?\n", current, current, low[current], succ, d[succ]);
      if ((p[current] != -1) && (d[succ] < low[current])) {
        printf("Da, atunci low(%d) = d(%d) = %d\n", current, succ, d[succ]);
        low[current] = d[succ];
      } else {
        printf("Nu, atunci low(%d) ramane neschimbat\n", current);
      }
    }
    aux = aux->next;
  }
}

void pct_art(Graph g) {
  char c[g->V];
  int d[g->V], p[g->V], low[g->V], subarb[g->V], art[g->V];
  int pas = 0;
  for (int i = 0; i < g->V; i++) {
    c[i] = 'a';
    d[i] = 0;
    p[i] = -1;
    low[i] = 0;
    subarb[i] = 0;
    art[i] = 0;
  }
  
  for (int i = 0; i < g->V; i++) {
    if (c[i] == 'a') {
      pct_art_help(g, i, &pas, d, low, p, subarb, art, c);
      if (subarb[i] > 1) {
        art[i] = 1;
      }
    }
  }
  
  printf("Puncte de articulatie: ");
  for (int i = 0; i < g->V; i++) {
    if (art[i] == 1) {
      printf("%d ", i);
    }
  }
}

void punti_help(Graph g, int current, int *pas, int *d, 
                  int *low, int *p, int *punte, char *c) {
  int succ;
  c[current] = 'g';
  d[current] = *pas;
  low[current] = *pas;
  printf("%d -> d(%d) = %d, low(%d) = %d, c(%d) = g\n", *pas, current, *pas, current, *pas, current);
  *pas = *pas + 1;
  
  List aux = g->adjLists[current];
  while (aux != NULL) {
    succ = aux->data;
    if (c[succ] == 'a') {
      p[succ] = current;
      printf("p(%d) = %d\n\n", succ, current);
      punti_help(g, succ, pas, d, low, p, punte, c);
      
      if (low[succ] < low[current]) {
        low[current] = low[succ];
      }
      
      printf("low(%d) = %d (min(low(%d), low(%d)))\n", current, low[current], current, current);
      printf("low(%d) = %d > d(%d) = %d ?\n", succ, low[succ], current, d[current]);
      if (d[current] < low[succ]) {
        printf("Da, atunci punte(%d) = 1\n", current);
        punte[succ] = current;
      } else {
        printf("Nu, atunci punte(%d) ramane neschimbat\n", current);
      }
    } else {
      printf("p(%d) != %d ?\n", current, succ);
      if (p[current] != succ) {
        printf("Da, atunci low(%d) = min(low(%d), d(%d)) = %d\n", current, current, succ, d[succ]);
        if (d[succ] < low[current]) {
          low[current] = d[succ];
        }
      } else {
        printf("Nu, atunci low(%d) ramane neschimbat\n", current);
      }
    }
    aux = aux->next;
  }
}

void punti(Graph g) {
  char c[g->V];
  int d[g->V], p[g->V], low[g->V], punte[g->V];
  int pas = 0;
  for (int i = 0; i < g->V; i++) {
    c[i] = 'a';
    d[i] = 0;
    p[i] = -1;
    low[i] = 0;
    punte[i] = -1;
  }
  
  for (int i = 0; i < g->V; i++) {
    if (c[i] == 'a') {
      punti_help(g, i, &pas, d, low, p, punte, c);
    }
  }
  
  printf("\nPunti:\n");
  for (int i = 0; i < g->V; i++) {
    if (punte[i] != -1) {
      printf("%d - %d\n", i, punte[i]);
    }
  }
}

int main() {
  Graph g = initGraph(10, 0);
  g = insertEdge(g, 0, 1);
  g = insertEdge(g, 0, 9);
  g = insertEdge(g, 1, 2);
  g = insertEdge(g, 1, 8);
  g = insertEdge(g, 2, 3);
  g = insertEdge(g, 2, 4);
  g = insertEdge(g, 2, 7);
  g = insertEdge(g, 3, 4);
  g = insertEdge(g, 3, 5);
  g = insertEdge(g, 5, 6);
  g = insertEdge(g, 7, 8);
  
  printf("2.Puncte de articulatie\n");
  pct_art(g);
  printf("\n\n");
  
  printf("4.Punti\n");
  punti(g);
  printf("\n\n");
  
  return 0;
}
