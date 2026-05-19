#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Experiment 17: BFS Traversal
Concepts:
- Graph
- BFS
- Queue
*/

vector<int> graph[10];
bool visited[10];

void bfs(int start) {

    queue<int> q;

    // start node queue me
    q.push(start);

    // visited mark
    visited[start] = true;

    while (!q.empty()) {

        // front node nikalo
        int node = q.front();
        q.pop();

        // print
        cout << node << " ";

        // neighbors check
        for (int neighbor : graph[node]) {

            // agar visit nahi hua
            if (!visited[neighbor]) {

                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    // graph create
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);

    graph[2].push_back(0);

    graph[3].push_back(1);

    cout << "BFS Traversal: ";

    bfs(0);

    return 0;
}