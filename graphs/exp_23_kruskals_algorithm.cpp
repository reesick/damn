#include <iostream>
using namespace std;

/*
Experiment 23: Kruskal's Algorithm
*/

int findParent(int parent[], int node) {

    while (parent[node] != -1)
        node = parent[node];

    return node;
}

int main() {

    // source, destination, weight
    int edges[3][3] = {
        {0, 1, 2},
        {1, 2, 3},
        {0, 2, 6}
    };

    int parent[3] = {-1, -1, -1};

    int cost = 0;
    int count = 0;

    for (int i = 0; i < 3 && count < 2; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        // cycle nahi hai
        if (pu != pv) {

            parent[pu] = pv;

            cout << u << " - " << v << " = " << w << endl;

            cost += w;
            count++;
        }
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}