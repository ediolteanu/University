#include<iostream>
#include<stdio.h>
#include <bits/stdc++.h>
#include<algorithm>
#include<chrono>
#include "algo.h"

using namespace std;
using namespace std::chrono;

#define INF INT_MAX

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void BellmanFord(struct Graph* , int , vector<int> &);

void shortestPath(vector< vector<int> > edges, int nr_nodes, int start_node,
				  int nr_edges, vector<int> &output) {
    Graph *graph = createGraph(nr_nodes, nr_edges);
    for (int i = 0; i < nr_edges; i++) {
        graph->edge[i].src = edges[i][0] - 1;
        graph->edge[i].dest = edges[i][1] - 1;
        graph->edge[i].weight = edges[i][2];
    }

    auto start = high_resolution_clock::now();
    BellmanFord(graph, start_node - 1, output);
    auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	cout<<"  Time taken: "<<duration.count()<<" nanoseconds  ";
}

void BellmanFord(struct Graph* graph, int src, vector<int> &output) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout<<"  Graph contains negative weight cycle!";
            return;
        }
    }

    for (int i = 0; i < graph->V; i++) {
        output[i] = dist[i];
    }
}
