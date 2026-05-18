/*
Experiment 08: BST Level Wise Traversal (BFS)
Topic: Trees
Concepts Used:
- Binary Search Tree
- Level Order Traversal
- Queue
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left  = insert(root->left,  val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// level by level print karo using queue
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        // current level ke kitne nodes hain
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";

            // children queue me daalo
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl; // nayi level pe nayi line
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    cout << "Level wise traversal:" << endl;
    levelOrder(root);

    return 0;
}
