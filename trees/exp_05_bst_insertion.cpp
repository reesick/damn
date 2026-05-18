/*
Experiment 05: BST Insertion
Topic: Trees
Concepts Used:
- Binary Search Tree
- Recursion
- BST Property (left < root < right)
*/

#include <iostream>
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

Node* insert(Node* root, int val) {
    // agar tree empty hai toh naya node hi root banega
    if (root == NULL) return newNode(val);

    // chota value left me jayega
    if (val < root->data)
        root->left = insert(root->left, val);

    // bada value right me jayega
    else if (val > root->data)
        root->right = insert(root->right, val);

    // duplicate ignore karo
    return root;
}

// inorder = sorted order in BST
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;

    return 0;
}
