/*
Experiment 03: Depth (Height) of Binary Tree
Topic: Trees
Concepts Used:
- Recursion
- Tree Height Calculation
- Binary Tree
*/

#include <iostream>
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

// depth = 1 + max(left depth, right depth)
int depth(Node* root) {
    // base case: empty tree ki depth 0
    if (root == NULL) return 0;

    int leftDepth  = depth(root->left);
    int rightDepth = depth(root->right);

    // jo bhi zyada ho woh le lo
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Depth of tree: " << depth(root) << endl;

    return 0;
}
