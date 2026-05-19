#include <iostream>
#include <vector>
using namespace std;

/*
Experiment 16: DFS Traversal
Concepts:
- Graph
- DFS
- Recursion
*/

vector<int> graph[10];
bool visited[10];

void dfs(int node) {

    // current node visited
    visited[node] = true;

    // print current node
    cout << node << " ";

    // saare neighbors check karo
    for (int neighbor : graph[node]) {

        // agar pehle visit nahi hua
        if (!visited[neighbor]) {
            dfs(neighbor);
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

    cout << "DFS Traversal: ";

    dfs(0);

    return 0;
}