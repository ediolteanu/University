#include<bits/stdc++.h>

using namespace std;

#define maxM 20000
unordered_set<int> path;

int getHighestParent(int u, int *p) {
  if (p[u] == u) {
    return u;
  } else {
    p[u] = getHighestParent(p[u], p);
    return p[u];
  }
}

void insertEdge(vector<int> *adjMatrix, int u, int v, int *p) {
	adjMatrix[u].push_back(v);
	p[getHighestParent(u, p)] = getHighestParent(v, p);
}

void DFS(vector<int> *adjMatrix, int u, int *p, int *visited, int *cycle) {
	int v;
	visited[u] = 1;
	path.insert(u);
	for (int i = 0; i < (int) adjMatrix[u].size(); i++) {
		v = adjMatrix[u][i];
		if(getHighestParent(u, p) != getHighestParent(v, p)) {
			continue;
		} else if (visited[v]) {
      if (path.find(v) != path.end()) {
	      cycle[getHighestParent(v, p)] = 1;
      }
    } else {
	    DFS(adjMatrix, v, p, visited, cycle);
    }
	}
  path.erase(u);
}

int main() {
  int V, E, u, v, x, nr;
  int visited[maxM], p[maxM], cycle[maxM];
  vector<int> adjMatrix[maxM];
  FILE *fin = fopen("holograme.in", "r");
	fscanf(fin, "%d %d", &V, &E);

	for (int i = 0; i < V; i++) {
    p[i] = i;
	}

	for (int i = 0; i < E; i++) {
		fscanf(fin, "%d %d", &u, &v);
		insertEdge(adjMatrix, u, v, p);
	}
	fclose(fin);

	for (int i = 0; i < V; i++) {
		x = getHighestParent(i, p);
		if (cycle[x]) {
			visited[i] = 1;
		}

		if (!visited[i]) {
			DFS(adjMatrix, i, p, visited, cycle);
		}
	}

  nr = 0;
	for(int i = 0; i < V; i++) {
		x = getHighestParent(i, p);
		if (visited[i] && !cycle[x]) {
			cycle[x] = 1;
			nr++;
		}
	}

	FILE *fout = fopen("holograme.out", "w");
	fprintf(fout, "%d\n", V - nr);
	fclose(fout);
	return 0;
}
