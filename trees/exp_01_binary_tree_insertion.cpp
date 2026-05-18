/*
Experiment 01: Binary Tree Insertion
Topic: Trees
Concepts Used:
- Binary Tree
- Dynamic Node Creation
- Level Order Insertion (queue based)
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// naya node banao
Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// level order me insert karo (BFS style)
Node* insert(Node* root, int val) {
    Node* n = newNode(val);
    if (root == NULL) return n;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        // left khali hai toh yahan insert karo
        if (curr->left == NULL) {
            curr->left = n;
            return root;
        } else q.push(curr->left);

        // right khali hai toh yahan insert karo
        if (curr->right == NULL) {
            curr->right = n;
            return root;
        } else q.push(curr->right);
    }
    return root;
}

// inorder print karo verify karne ke liye
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
