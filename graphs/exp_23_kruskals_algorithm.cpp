/*
Experiment 23: Kruskal's Algorithm (Minimum Spanning Tree)
Topic: Graphs
Concepts Used:
- Greedy Algorithm
- MST using Kruskal
- Disjoint Set Union (DSU / Union-Find)
- Sorting edges by weight
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// DSU - parent find karo
int parent[100];
int rankArr[100];

int find(int x) {
    // path compression
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// do sets ko merge karo
void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    // rank ke hisaab se merge karo
    if (rankArr[px] < rankArr[py]) swap(px, py);
    parent[py] = px;
    if (rankArr[px] == rankArr[py]) rankArr[px]++;
}

int main() {
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    // edges ko weight ke hisaab se sort karo
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.weight < b.weight;
    });

    // DSU initialize karo
    for (int i = 0; i < n; i++) { parent[i] = i; rankArr[i] = 0; }

    cout << "\nKruskal's MST:" << endl;
    cout << "Edge\t\tWeight" << endl;

    int totalWeight = 0, edgesUsed = 0;

    for (Edge& edge : edges) {
        // agar same component me nahi hain toh add karo
        if (find(edge.u) != find(edge.v)) {
            cout << edge.u << " - " << edge.v << "\t\t" << edge.weight << endl;
            totalWeight += edge.weight;
            unite(edge.u, edge.v);
            edgesUsed++;
            // MST complete: n-1 edges
            if (edgesUsed == n - 1) break;
        }
    }

    cout << "Total MST Weight: " << totalWeight << endl;
    return 0;
}
