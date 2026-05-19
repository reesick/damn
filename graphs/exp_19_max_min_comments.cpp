#include <iostream>
#include <vector>
using namespace std;

/*
Experiment 19: Max and Min Comments in Social Network
*/

vector<int> graph[10];

int main() {

    // social graph
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);

    graph[2].push_back(0);
    graph[2].push_back(3);

    graph[3].push_back(1);
    graph[3].push_back(2);

    // comments data
    int comments[] = {5, 12, 3, 8};
    int n = 4;

    int maxComments = comments[0];
    int minComments = comments[0];

    int maxUser = 0;
    int minUser = 0;

    for (int i = 1; i < n; i++) {

        if (comments[i] > maxComments) {
            maxComments = comments[i];
            maxUser = i;
        }

        if (comments[i] < minComments) {
            minComments = comments[i];
            minUser = i;
        }
    }

    cout << "User with maximum comments: " << maxUser << endl;
    cout << "Comments: " << maxComments << endl;

    cout << "User with minimum comments: " << minUser << endl;
    cout << "Comments: " << minComments;

    return 0;
}