#include <iostream>
using namespace std;

/*
Experiment 06: BST Searching
Concepts:
- BST
- Recursion
- Search
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {

    // empty jagah pe node banao
    if (root == NULL)
        return new Node{value, NULL, NULL};

    // chota left
    if (value < root->data)
        root->left = insert(root->left, value);

    // bada right
    else
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int key) {

    // node nahi mila
    if (root == NULL)
        return false;

    // mil gaya
    if (key == root->data)
        return true;

    // chota hai toh left
    if (key < root->data)
        return search(root->left, key);

    // warna right
    return search(root->right, key);
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 8);

    int key = 8;

    if (search(root, key))
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}