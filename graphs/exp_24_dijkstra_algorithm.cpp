/*
Experiment 24: Dijkstra's Shortest Path Algorithm
Topic: Graphs
Concepts Used:
- Greedy Algorithm
- Single Source Shortest Path
- Priority Queue (min-heap)
- Adjacency List
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii; // {distance, vertex}

void dijkstra(vector<vector<pii>>& adj, int src, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // agar purana distance hai toh skip karo
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // agar chota rasta mila
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "To " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << endl;
    }
}

int main() {
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    vector<vector<pii>> adj(n);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // directed graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected ke liye dono
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(adj, src, n);
    return 0;
}
