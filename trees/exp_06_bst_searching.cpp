/*
Experiment 06: BST Searching
Topic: Trees
Concepts Used:
- Binary Search Tree
- Recursion
- Search Logic
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

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left  = insert(root->left,  val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// search karo BST me
bool search(Node* root, int key) {
    // element mila nahi
    if (root == NULL) return false;

    // element mil gaya
    if (root->data == key) return true;

    // key choti hai toh left me jao
    if (key < root->data)
        return search(root->left, key);

    // key badi hai toh right me jao
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (search(root, key))
        cout << key << " found in BST." << endl;
    else
        cout << key << " not found in BST." << endl;

    return 0;
}
