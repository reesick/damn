/*
Experiment 22: Prim's Algorithm (Minimum Spanning Tree)
Topic: Graphs
Concepts Used:
- Greedy Algorithm
- MST (Minimum Spanning Tree)
- Adjacency Matrix
*/

#include <iostream>
#include <climits>
using namespace std;

const int MAXN = 10;

// minimum key value wala vertex jo abhi MST me nahi hai
int minKey(int key[], bool inMST[], int n) {
    int minVal = INT_MAX, minIdx = -1;
    for (int i = 0; i < n; i++) {
        if (!inMST[i] && key[i] < minVal) {
            minVal = key[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void primMST(int graph[MAXN][MAXN], int n) {
    int parent[MAXN]; // MST ka parent store karega
    int key[MAXN];    // minimum edge weight
    bool inMST[MAXN]; // vertex MST me hai ya nahi

    // sab key ko infinity se initialize karo
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    // pehla vertex select karo
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        // minimum key vertex lo jo MST me nahi hai
        int u = minKey(key, inMST, n);
        inMST[u] = true;

        // u ke sabhi neighbors update karo
        for (int v = 0; v < n; v++) {
            // agar edge hai, v MST me nahi hai, aur weight choti hai
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // MST print karo
    cout << "Edge\t\tWeight" << endl;
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t\t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[MAXN][MAXN] = {};
    cout << "Enter adjacency matrix (0 if no edge):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    primMST(graph, n);
    return 0;
}
