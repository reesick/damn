#include <iostream>
#include <vector>
using namespace std;

/*
Experiment 18: Maximum Friends
Concepts:
- Graph
- Adjacency List
*/

vector<int> graph[10];

int main() {

    // social network graph
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);

    graph[2].push_back(0);
    graph[2].push_back(1);

    graph[3].push_back(1);

    int maxFriends = 0;
    int user = -1;

    // har user check karo
    for (int i = 0; i < 4; i++) {

        int count = graph[i].size();

        // zyada friends mila
        if (count > maxFriends) {
            maxFriends = count;
            user = i;
        }
    }

    cout << "User with maximum friends: " << user << endl;
    cout << "Total friends: " << maxFriends;

    return 0;
}