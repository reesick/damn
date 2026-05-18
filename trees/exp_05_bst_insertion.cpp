#include <iostream>
using namespace std;

/*
Experiment 05: BST Insertion
Concepts:
- BST
- Recursion
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {

    // empty spot mila toh node banao
    if (root == NULL)
        return new Node{value, NULL, NULL};

    // chota value left me
    if (value < root->data)
        root->left = insert(root->left, value);

    // bada value right me
    else
        root->right = insert(root->right, value);

    return root;
}

// inorder just to verify tree
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 8);

    cout << "BST Inorder: ";
    inorder(root);

    return 0;
}