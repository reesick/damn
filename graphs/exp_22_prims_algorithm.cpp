#include <iostream>
using namespace std;

/*
Experiment 22: Prim's Algorithm
*/

int main() {

    int graph[3][3] = {
        {0, 2, 6},
        {2, 0, 3},
        {6, 3, 0}
    };

    bool visited[3] = {false};

    int cost = 0;

    // start from node 0
    visited[0] = true;

    // n-1 edges chahiye
    for (int count = 0; count < 2; count++) {

        int min = 999;
        int x, y;

        // visited se unvisited tak minimum edge dhundo
        for (int i = 0; i < 3; i++) {

            if (visited[i]) {

                for (int j = 0; j < 3; j++) {

                    if (!visited[j] && graph[i][j]) {

                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " = " << min << endl;

        cost += min;
        visited[y] = true;
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}