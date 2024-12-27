#include <iostream>
using namespace std;

const int maxV = 100;
int adjList[maxV][maxV];
int adjSize[maxV];

void createAdjacencyList(int V, int E, int edges[][2]) {
    for (int i = 0; i < V; ++i) {
        adjSize[i] = 0;
    }

    for (int i = 0; i < E; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }
}

int main() {
    int V = 5, E = 7;
    int edges[7][2] = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};

    createAdjacencyList(V, E, edges);
	cout<<"Adjacency List"<<endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < adjSize[i]; ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

