/*
Experiment 18: Maximum Friends in Social Network (Degree of a Node)
Topic: Graphs
Concepts Used:
- Graph (Adjacency Matrix / Degree)
- Degree Counting
- Max Degree Node
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of people (vertices) and friendships (edges): ";
    cin >> n >> e;

    // degree array: kitne dost hain har person ke
    vector<int> degree(n + 1, 0);

    cout << "Enter friendships (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        // dono ka degree badhega
        degree[u]++;
        degree[v]++;
    }

    // sabse zyada dost kiski hain
    int maxDeg = 0, maxPerson = 1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > maxDeg) {
            maxDeg = degree[i];
            maxPerson = i;
        }
    }

    cout << "\nDegree of each person:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Person " << i << ": " << degree[i] << " friends" << endl;
    }

    cout << "\nPerson with maximum friends: Person " << maxPerson
         << " with " << maxDeg << " friends." << endl;

    return 0;
}
