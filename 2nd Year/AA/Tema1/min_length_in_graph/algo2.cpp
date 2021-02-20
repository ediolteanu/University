#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<chrono>
#include "algo.h"

using namespace std;
using namespace std::chrono;

#define INF INT_MAX

class Graph
{
public:
    int V;
    list< pair<int, int> > *adj;

    Graph(int V);
    void addEdge(int u, int v, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

// W is the maximum weight of an edge
void Dial(Graph g, int V, int start_node, int W, vector<int> &output)
{
   vector<pair<int, list<int>::iterator> > dist(V);

    for (int i = 0; i < V; i++) {
        dist[i].first = INF;
    }

    list<int> B[W * V + 1];

    B[0].push_back(start_node);
    dist[start_node].first = 0;

    int index = 0;
    while (1){
        while (B[index].size() == 0 && index < W*V) {
            index++;
        }
        if (index == W * V) break;

        int u = B[index].front();
        B[index].pop_front();

        for (auto i = g.adj[u].begin(); i != g.adj[u].end(); i++) {
            int v = (*i).first;
            int weight = (*i).second;

            int dist_u = dist[u].first;
            int dist_v = dist[v].first;

            if (dist_v > dist_u + weight) {
                if (dist_v != INF) B[dist_v].erase(dist[v].second);

                dist[v].first = dist_u + weight;
                dist_v = dist[v].first;

                B[dist_v].push_front(v);

                dist[v].second = B[dist_v].begin();
            }
        }
    }

    for (int i = 0; i < g.V; i++) {
        output[i] = dist[i].first;
    }
}

void shortestPath(vector< vector<int> > edges, int nr_nodes, int start_node,
                  int nr_edges, vector<int> &output) {
    Graph g(nr_nodes);
    int W = 0;
    for (int i = 0; i < nr_edges; i++) {
        g.addEdge(edges[i][0] - 1, edges[i][1] - 1, edges[i][2]);
        if (edges[i][2] > W) {
            W = edges[i][2];
        }
    }

    auto start = high_resolution_clock::now();
    Dial(g, nr_nodes, start_node - 1, W, output);
    auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	cout<<"  Time taken: "<<duration.count()<<" nanoseconds  ";
}



