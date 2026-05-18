#include <iostream>
using namespace std;

/*
Experiment 07: BST Deletion
Concepts:
- BST
- Recursion
- Deletion cases
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {

    // empty jagah
    if (root == NULL)
        return new Node{value, NULL, NULL};

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


// smallest node find karo (right subtree ke liye use hoga)
Node* findMin(Node* root) {

    // sabse left wala smallest hota hai
    while (root->left != NULL)
        root = root->left;

    return root;
}


Node* deleteNode(Node* root, int key) {

    // node mila hi nahi
    if (root == NULL)
        return NULL;

    // key choti hai → left me search
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // key badi hai → right me search
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        // CASE 1: no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // CASE 2: only right child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // CASE 2: only left child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // CASE 3: two children
        else {

            // right subtree ka smallest lo
            Node* temp = findMin(root->right);

            // current value replace
            root->data = temp->data;

            // duplicate delete karo
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}


// sorted verify
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

    cout << "Before deletion: ";
    inorder(root);

    root = deleteNode(root, 5);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}