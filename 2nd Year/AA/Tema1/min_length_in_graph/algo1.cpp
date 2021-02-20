#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<chrono>
#include "algo.h"

using namespace std;
using namespace std::chrono;

#define INF 1000000

void dijkstra(vector< vector<int> >, int , int , vector<int> &);
void shortestPath(vector< vector<int> > edges, int nr_nodes, int start_node,
				  int nr_edges, vector<int> &output) {
	vector< vector<int> > cost;
	cost.resize(nr_nodes, vector<int>(nr_nodes));
	output.resize(nr_nodes);
    for (int i = 0; i < nr_nodes; i++) {
        for (int j = 0; j < nr_nodes; j++) {
                cost[i][j] = INF;
        }
    }
    for (int i = 0; i < nr_edges; i++) {
        cost[edges[i][0] - 1][edges[i][1] - 1] = edges[i][2];
    }

    auto start = high_resolution_clock::now();
	dijkstra(cost, nr_nodes, start_node - 1, output);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	cout<<"  Time taken: "<<duration.count()<<" nanoseconds  ";
}

void dijkstra(vector< vector<int> > cost, int nr_nodes, int start_node,
               vector<int> &output) {
    vector<int> dist(nr_nodes);
    vector<bool> visited(nr_nodes);
    int count, min_distance, next_node;

    for (int i = 0; i < nr_nodes; i++) {
        dist[i] = cost[start_node][i];
        visited[i] = false;
    }
    dist[start_node] = 0;
    visited[start_node] = true;

    count = 0;
    while (count < nr_nodes - 1) {
        min_distance = INF;
        for (int i = 0; i < nr_nodes; i++) {
            if (!visited[i]) {
                if ((dist[i] < min_distance)) {
                    min_distance = dist[i];
                    next_node = i;
                }
            }
        }
        visited[next_node] = true;
        for (int i = 0; i < nr_nodes; i++) {
            if (!visited[i]) {
                if ((min_distance + cost[next_node][i]) < dist[i]) {
                    dist[i] = min_distance + cost[next_node][i];
                }
            }
        }
        count++;
    }

    for (int i = 0; i < nr_nodes; i++) {
        output[i] = dist[i];
    }
}

