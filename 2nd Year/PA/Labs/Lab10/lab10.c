#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 100000

typedef struct list {
	int data;
	int cost;
	struct list *prev, *next;
}*List;


List initList(int data, int cost)
{
	List list;

	list = (List) malloc(sizeof(struct list));
	list->data = data;
	list->cost = cost;
	list->next = NULL;
	list->prev = NULL;
	return list;
}

List addFirst(List list, int data, int cost)
{
	List new;

	if (list == NULL)
		return initList(data, cost);
	new = initList(data, cost);
	new->next = list;
	list->prev = new;
	return new;
}

List addLast(List list, int data, int cost)
{
	List new, tmp;

	if (list == NULL)
		return initList(data, cost);
	new = initList(data, cost);
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

Graph insertEdge(Graph g, int u, int v, int cost) {
	g->adjLists[u] = addLast(g->adjLists[u], v, cost);
  if (g->type == 0) { // daca este neorientat se adauga si muchia inversa
    g->adjLists[v] = addLast(g->adjLists[v], u, cost);
  }
	return g;
}

int ExtrageMin(Queue q, int *d) {
  Node *aux = q->head;
  int min = aux->data;
  while (aux != NULL) {
    if (d[min] > d[aux->data]) min = aux->data;
    aux = aux->next;
  }
  return min;
}
Queue removeMin(Queue q, int *d, int min) {
  Node *aux = q->head;
  if (q->head->next == NULL) return NULL;
  if (aux->data == min) {
    q->size--;
    q->head = q->head->next; 
    return q;
  }
  Node *aux1 = q->head;
  aux = q->head->next;
  while (aux != NULL) {
    if (aux->data == min) {
      aux1->next = aux->next;
      q->size--;
      break;
    }
    aux1 = aux;
    aux = aux->next;
  }
  
  return q;
}

void Dijkstra(Graph g, int start) {
  int d[g->V], p[g->V];
  int u;
  for (int i = 1; i < g->V; i++) {
    d[i] = INF;
    p[i] = -1;
  }
  d[start] = 0;
  
  Queue q = initQueue(start);
  for (int i = 1; i < g->V; i++) {
    if (i != start) q = enqueue(q, i);
  }
  int k = 1;
  while(!isEmptyQueue(q)) {
    u = ExtrageMin(q, d);
    
    printf("Pasul %d -> Extrage din coada nodul cu d[u] minim: %d\n", k, u);
    q = removeMin(q, d, u);
    
    List aux = NULL;
    
    if (g->adjLists[u] != NULL) {
      aux = g->adjLists[u];
    }
    
    while (aux != NULL) {
      if (d[aux->data] > d[u] + aux->cost) {
        d[aux->data] = d[u] + aux->cost;
        p[aux->data] = u;
        printf("Da -> d(%d) = %d, p(%d) = %d\n", aux->data, d[aux->data], aux->data, u);
      } else {
        printf("Nu, d si p raman neschimbate\n");
      }
      aux = aux->next;
    }
    k++;
  }
  printf("Pasul %d -> Coada este vida\n", k);
  printf("\nValorile pentru d si p sunt:\n");
  for (int i = 1; i < g->V; i++) {
    printf("d(%d) = %d, p(%d) = %d\n", i, d[i], i, p[i]);
  }
}

void BellmanFord(Graph g, int start) {
  int d[g->V], p[g->V];
  int visited[g->V];
  for (int i = 1; i < g->V; i++) {
    d[i] = INF;
    p[i] = -1;
    visited[i] = 0;
  }
  d[start] = 0;
  visited[start] = 1;
  Queue q = initQueue(start);
  int j;
  Queue newq = initQueue(start);
  newq = dequeue(newq);
  for (int i = 1; i < g->V - 1; i++) {
    printf("Pasul %d:\n", i);
    while(!isEmptyQueue(q)) {
        j = first(q);
        q = dequeue(q);
          List aux = g->adjLists[j];
          while (aux != NULL) {
            printf("d(%d) > d(%d) + w(%d, %d) ?\n", aux->data, j, j, aux->data);
            if (d[aux->data] > d[j] + aux->cost) {
              d[aux->data] = d[j] + aux->cost;
              p[aux->data] = j;
              newq = enqueue(newq, aux->data);
              printf("Da -> d(%d) = %d, p(%d) = %d\n", aux->data, d[aux->data], aux->data, j);
            } else {
              printf("Nu, d si p raman neschimbate\n");
            }
          aux = aux->next;
          }
    }
    printf("\n");
    while(!isEmptyQueue(newq)) {
      j = first(newq);
      newq = dequeue(newq);
      q = enqueue(q, j);
    }
    
  }
  
  for (int j = 1; j < g->V; j++) {
    List aux = g->adjLists[j];
    while (aux != NULL) {
      if (d[aux->data] > d[j] + aux->cost) {
        printf("Eroare: ciclu negativ\n");
      }
      aux = aux->next;
    }
  }
  for (int i = 1; i < g->V; i++) {
    printf("d(%d) = %d, p(%d) = %d\n", i, d[i], i, p[i]);
  }
}

int main() {
  Graph g = initGraph(8, 1);
  g = insertEdge(g, 1, 2, 3);
  g = insertEdge(g, 1, 3, 4);
  g = insertEdge(g, 1, 5, 1);
  g = insertEdge(g, 1, 6, 10);
  g = insertEdge(g, 1, 7, 3);
  g = insertEdge(g, 2, 3, 2);
  g = insertEdge(g, 3, 4, 2);
  g = insertEdge(g, 3, 6, 2);
  g = insertEdge(g, 5, 4, 3);
  g = insertEdge(g, 5, 7, 1);
  g = insertEdge(g, 6, 4, 2);
  g = insertEdge(g, 7, 3, 1);
  g = insertEdge(g, 7, 4, 10);
  g = insertEdge(g, 7, 5, 2);
  
  Dijkstra(g, 1);
  printf("\n\n");
  BellmanFord(g, 1);
  return 0;
}
