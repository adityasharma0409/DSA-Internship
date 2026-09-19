#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start) {
    int queue[MAX];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    queue[rear++] = start;
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int current = queue[front++];

        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    cout << endl;
}

void DFS(int current) {
    visited[current] = 1;

    cout << current << " ";

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges;
    int u, v;
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(start);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFS(start);
    cout << endl;

    return 0;
}