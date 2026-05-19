#include <iostream>
using namespace std;

/*
Experiment 24: Dijkstra Algorithm
*/

int main() {

    int graph[3][3] = {
        {0, 2, 6},
        {2, 0, 3},
        {6, 3, 0}
    };

    int dist[3] = {0, 999, 999};
    bool visited[3] = {false};

    for (int count = 0; count < 3; count++) {

        int min = 999;
        int u;

        // smallest unvisited distance
        for (int i = 0; i < 3; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // neighbors update
        for (int v = 0; v < 3; v++) {

            if (graph[u][v] && !visited[v]) {

                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    cout << "Shortest distances from source 0:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "0 to " << i << " = " << dist[i] << endl;
    }

    return 0;
}