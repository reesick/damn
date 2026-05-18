/*
Experiment 04: Display Leaf Nodes of Binary Tree
Topic: Trees
Concepts Used:
- Recursion
- Leaf Node Condition
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

// leaf node = jiske dono children NULL hain
void printLeaves(Node* root) {
    if (root == NULL) return;

    // agar dono children NULL hain toh yeh leaf hai
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    // warna left aur right me dhundho
    printLeaves(root->left);
    printLeaves(root->right);
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << "Leaf nodes: ";
    printLeaves(root);
    cout << endl;

    return 0;
}
