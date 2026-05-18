/*
Experiment 15: AVL Tree Insertion
Topic: Trees
Concepts Used:
- AVL Tree (Self-Balancing BST)
- Rotations: LL, RR, LR, RL
- Balance Factor
*/

#include <iostream>
using namespace std;

struct Node {
    int data, height;
    Node* left;
    Node* right;
};

int h(Node* n) { return n ? n->height : 0; }
int bf(Node* n) { return n ? h(n->left) - h(n->right) : 0; }

Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}

void updateHeight(Node* n) {
    n->height = 1 + max(h(n->left), h(n->right));
}

// RR rotation (left rotate)
Node* leftRotate(Node* z) {
    Node* y = z->right;
    Node* T2 = y->left;
    y->left = z;
    z->right = T2;
    updateHeight(z);
    updateHeight(y);
    return y;
}

// LL rotation (right rotate)
Node* rightRotate(Node* z) {
    Node* y = z->left;
    Node* T3 = y->right;
    y->right = z;
    z->left = T3;
    updateHeight(z);
    updateHeight(y);
    return y;
}

Node* insert(Node* root, int val) {
    // normal BST insert
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root; // duplicate ignore

    updateHeight(root);

    int balance = bf(root);

    // LL case
    if (balance > 1 && val < root->left->data)
        return rightRotate(root);

    // RR case
    if (balance < -1 && val > root->right->data)
        return leftRotate(root);

    // LR case
    if (balance > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL case
    if (balance < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << "(h=" << root->height << ") ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {10, 20, 30, 40, 50, 25};
    for (int x : arr) root = insert(root, x);

    cout << "Inorder traversal of AVL tree:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}
