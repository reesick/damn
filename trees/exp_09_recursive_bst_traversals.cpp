#include <iostream>
using namespace std;

/*
Experiment 09: Recursive BST Traversals
Concepts:
- BST
- Recursion
- Tree Traversals
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

    // chota left me
    if (value < root->data)
        root->left = insert(root->left, value);

    // bada right me
    else
        root->right = insert(root->right, value);

    return root;
}


// LEFT ROOT RIGHT
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// ROOT LEFT RIGHT
void preorder(Node* root) {

    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


// LEFT RIGHT ROOT
void postorder(Node* root) {

    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 8);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}