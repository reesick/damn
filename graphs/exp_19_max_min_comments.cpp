/*
Experiment 19: Maximum and Minimum Comments on Posts
Topic: Graphs / Arrays
Concepts Used:
- Array traversal
- Comparison logic
- Max/Min finding
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of posts: ";
    cin >> n;

    int comments[100];
    cout << "Enter comment count for each post:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Post " << i + 1 << ": ";
        cin >> comments[i];
    }

    // max aur min dhundho
    int maxComments = comments[0], minComments = comments[0];
    int maxPost = 0, minPost = 0;

    for (int i = 1; i < n; i++) {
        if (comments[i] > maxComments) {
            maxComments = comments[i];
            maxPost = i;
        }
        if (comments[i] < minComments) {
            minComments = comments[i];
            minPost = i;
        }
    }

    cout << "\nPost with Maximum Comments: Post " << maxPost + 1
         << " (" << maxComments << " comments)" << endl;

    cout << "Post with Minimum Comments: Post " << minPost + 1
         << " (" << minComments << " comments)" << endl;

    return 0;
}
