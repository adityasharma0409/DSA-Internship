#include <iostream>
#include <string>
using namespace std;

#define MAX 20
#define INF 99999

int graph[MAX][MAX];
string cities[MAX];
int n;

int findCity(string name) {
    for (int i = 0; i < n; i++) {
        if (cities[i] == name) {
            return i;
        }
    }

    return -1;
}

void findShortestPath(int start, int destination) {

    int distance[MAX];
    int visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {

        int minDistance = INF;
        int current = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 &&
                distance[i] < minDistance) {

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

                distance[i] =
                    distance[current] + graph[current][i];

                parent[i] = current;
            }
        }
    }

    if (distance[destination] == INF) {
        cout << "\nNo route found." << endl;
        return;
    }

    int path[MAX];
    int pathSize = 0;

    int current = destination;

    while (current != -1) {
        path[pathSize] = current;
        pathSize++;
        current = parent[current];
    }

    cout << "\nShortest Route: ";

    for (int i = pathSize - 1; i >= 0; i--) {

        cout << cities[path[i]];

        if (i != 0) {
            cout << " -> ";
        }
    }

    cout << endl;

    cout << "Shortest Distance: "
         << distance[destination] << " km" << endl;
}

int main() {

    int edges;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter city names:\n";

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = INF;
            }
        }
    }

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter roads in this format:\n";
    cout << "City1 City2 Distance\n";

    for (int i = 0; i < edges; i++) {

        string city1, city2;
        int distance;

        cin >> city1 >> city2 >> distance;

        int u = findCity(city1);
        int v = findCity(city2);

        if (u != -1 && v != -1) {

            graph[u][v] = distance;
            graph[v][u] = distance;
        }
    }

    string startCity;
    string destinationCity;

    cout << "Enter starting city: ";
    cin >> startCity;

    cout << "Enter destination city: ";
    cin >> destinationCity;

    int start = findCity(startCity);
    int destination = findCity(destinationCity);

    if (start == -1 || destination == -1) {
        cout << "Invalid city name." << endl;
        return 0;
    }

    findShortestPath(start, destination);

    return 0;
}