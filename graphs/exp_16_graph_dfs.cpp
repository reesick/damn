/*
Experiment 16: DFS Traversal on Graph
Topic: Graphs
Concepts Used:
- Graph (Adjacency List)
- Depth First Search
- Recursion + Visited Array
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN]; // adjacency list
bool visited[MAXN];

// recursively DFS karo
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    // sabhi neighbors visit karo jo abhi tak nahi gaye
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor);
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
        // undirected graph - dono taraf edge daalo
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // sab unvisited se shuru
    for (int i = 0; i <= n; i++) visited[i] = false;

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);
    cout << endl;

    return 0;
}
