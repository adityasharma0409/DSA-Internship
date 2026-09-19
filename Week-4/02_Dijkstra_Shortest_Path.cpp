#include <iostream>
using namespace std;

#define MAX 20
#define INF 99999

int main() {
    int n;
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:" << endl;
    cout << "(Enter 0 if there is no direct edge)" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++) {
        distance[i] = graph[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {

        int minDistance = INF;
        int current = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && distance[i] < minDistance) {
                minDistance = distance[i];
                current = i;
            }
        }

        if (current == -1) {
            break;
        }

        visited[current] = 1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 &&
                graph[current][i] != INF &&
                distance[current] + graph[current][i] < distance[i]) {

                distance[i] = distance[current] + graph[current][i];
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":\n";

    for (int i = 0; i < n; i++) {
        if (distance[i] == INF) {
            cout << "Vertex " << i << " : Not reachable" << endl;
        }
        else {
            cout << "Vertex " << i << " : " << distance[i] << endl;
        }
    }

    return 0;
}