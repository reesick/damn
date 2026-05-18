/*
Experiment 17: BFS Traversal on Graph
Topic: Graphs
Concepts Used:
- Graph (Adjacency List)
- Breadth First Search
- Queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];

// queue use karke BFS karo
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        // sabhi unvisited neighbors ko queue me daalo
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i <= n; i++) visited[i] = false;

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    bfs(start);
    cout << endl;

    return 0;
}
