#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 100000

typedef struct list {
	int data;
	int cost;
	struct list *prev, *next;
}*List;

typedef struct muchie {
  int nod1;
  int nod2;
}Edge;
typedef struct muchieK {
  int nod1;
  int nod2;
  int cost;
}EdgeK;

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

void Prim(Graph g, int start) {
  int d[g->V], p[g->V];
  Edge AMA[g->V];
  int u;
  for (int i = 0; i < g->V; i++) {
    d[i] = INF;
    p[i] = -1;
  }
  d[start] = 0;
  Queue q = initQueue(start);
  for (int i = 0; i < g->V; i++) {
    if (i != start) q = enqueue(q, i);
  }
  int k = 0;
  int l = 0;
  
  while (!isEmptyQueue(q)) {
    k++;
    Node *auxq = q->head;
    printf("\nPasul %d:\nCoada:\n", k);
    while (auxq != NULL) {
      if (d[auxq->data] == INF) {
        printf("%c -> d(%c) = INF\n", auxq->data + 97, auxq->data + 97);
      } else {
        printf("%c -> d(%c) = %d\n", auxq->data + 97, auxq->data + 97, d[auxq->data]);
      }
      auxq = auxq->next;
    }
    
    
    u = ExtrageMin(q, d);
    printf("\nExtrage din coada nodul cu d[u] minim: %c\n", u + 97);
    q = removeMin(q, d, u);
    if (p[u] != -1) {
      AMA[l].nod1 = u;
      AMA[l].nod2 = p[u];
      l++;
    }
    
    List aux = g->adjLists[u];
    while (aux != NULL) {
      printf("d(%c) >  w(%c, %c) ?\n", aux->data + 97, u + 97, aux->data + 97);
      if (d[aux->data] > aux->cost) {
        d[aux->data] = aux->cost;
        p[aux->data] = u;
        printf("Da -> d(%c) = %d, p(%c) = %c\n", aux->data + 97, d[aux->data], aux->data + 97, u + 97);
      } else {
        printf("Nu, d si p raman neschimbate\n");
      }
    aux = aux->next;
    }
  }
  printf("\nAMA rezultat contine muchiile:\n");
  for (int i = 0; i < l; i++) {
    printf("%c-%c\n", AMA[i].nod1 + 97, AMA[i].nod2 + 97);
  }
}

int hasIntersection(int **arb, int nrV, int u, int v) {
  for (int i = 0; i < nrV; i++) {
    if (arb[u][i] && arb[v][i]) return 1; 
  }
  return 0;
}

void Kruskal(EdgeK *muchii, int nrE, int nrV) {
  EdgeK aux;
  for (int i = 0; i < nrE - 1; i++) 
    for (int j = i + 1; j < nrE; j++) {
      if (muchii[j].cost < muchii[i].cost) {
        aux = muchii[i];
        muchii[i] = muchii[j];
        muchii[j] = aux;
      } 
    }
  
  EdgeK AMA[nrE];
  int **Arb = (int **) calloc(nrV + 1, sizeof(int *));
  for (int i = 0; i < nrV + 1; i++) {
    Arb[i] = calloc(nrV + 1, sizeof(int));
    Arb[i][i] = 1;
  }
  
  int l = 0;
  for (int i = 0; i < nrE; i++) {
    printf("Iau muchia %c-%c si verific daca se intersecteaza arborii nodurilor.\n", muchii[i].nod1 + 97, muchii[i].nod2 + 97);
    if (!hasIntersection(Arb, nrV, muchii[i].nod1, muchii[i].nod2)) {
      printf("Arborii nu se intersecteaza, deci adaug muchia in AMA.\n\n");
      AMA[l++] = muchii[i];
      for(int k = 0; k < nrV; k++) {
        if (Arb[muchii[i].nod2][k] == 1) {
          Arb[muchii[i].nod1][k] = 1;
        }
      }
      free(Arb[muchii[i].nod2]);
      Arb[muchii[i].nod2] = Arb[muchii[i].nod1];
    } else {
      printf("Arborii se intersecteaza, deci NU adaug muchia in AMA.\n\n");
    }
  }
  printf("\nAMA rezultat contine muchiile:\n");
  for (int i = 0; i < l; i++) {
    printf("%c-%c\n", AMA[i].nod1 + 97, AMA[i].nod2 + 97);
  }
}

int main() {
  Graph g = initGraph(12, 0);
  g = insertEdge(g, 0, 1, 9);
  g = insertEdge(g, 0, 6, 10);
  g = insertEdge(g, 0, 7, 6);
  g = insertEdge(g, 0, 8, 3);
  g = insertEdge(g, 1, 2, 5);
  g = insertEdge(g, 1, 6, 11);
  g = insertEdge(g, 2, 3, 8);
  g = insertEdge(g, 2, 4, 12);
  g = insertEdge(g, 3, 5, 9);
  g = insertEdge(g, 4, 5, 2);
  g = insertEdge(g, 6, 7, 4);
  g = insertEdge(g, 8, 9, 5);
  g = insertEdge(g, 8, 11, 8);
  g = insertEdge(g, 9, 10, 14);
  g = insertEdge(g, 10, 11, 7);
  
  EdgeK muchii[15];
  muchii[0].nod1 = 0;
  muchii[0].nod2 = 1;
  muchii[0].cost = 9;
  muchii[1].nod1 = 0;
  muchii[1].nod2 = 6;
  muchii[1].cost = 10;
  muchii[2].nod1 = 0;
  muchii[2].nod2 = 7;
  muchii[2].cost = 6;
  muchii[3].nod1 = 0;
  muchii[3].nod2 = 8;
  muchii[3].cost = 3;
  muchii[4].nod1 = 1;
  muchii[4].nod2 = 2;
  muchii[4].cost = 5;
  muchii[5].nod1 = 1;
  muchii[5].nod2 = 6;
  muchii[5].cost = 11;
  muchii[6].nod1 = 2;
  muchii[6].nod2 = 3;
  muchii[6].cost = 8;
  muchii[7].nod1 = 2;
  muchii[7].nod2 = 4;
  muchii[7].cost = 12;
  muchii[8].nod1 = 3;
  muchii[8].nod2 = 5;
  muchii[8].cost = 9;
  muchii[9].nod1 = 4;
  muchii[9].nod2 = 5;
  muchii[9].cost = 2;
  muchii[10].nod1 = 6;
  muchii[10].nod2 = 7;
  muchii[10].cost = 4;
  muchii[11].nod1 = 8;
  muchii[11].nod2 = 9;
  muchii[11].cost = 5;
  muchii[12].nod1 = 8;
  muchii[12].nod2 = 11;
  muchii[12].cost = 8;
  muchii[13].nod1 = 9;
  muchii[13].nod2 = 10;
  muchii[13].cost = 14;
  muchii[14].nod1 = 10;
  muchii[14].nod2 = 11;
  muchii[14].cost = 7;
  
  int nrE = 15;
  int nrV = 12;
  printf("2.Prim\n");
  Prim(g, 8); // incepe din nodul i(8)
  printf("\n\n");
  printf("4.Kruskal\n");
  Kruskal(muchii, nrE, nrV);
  return 0;
}



