/*
Experiment 09: Recursive BST Traversals
Topic: Trees
Concepts Used:
- Binary Search Tree
- Inorder, Preorder, Postorder (Recursive)
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

// Left -> Root -> Right (sorted order deta hai BST me)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    cout << "Inorder   (L-Root-R): "; inorder(root);   cout << endl;
    cout << "Preorder  (Root-L-R): "; preorder(root);  cout << endl;
    cout << "Postorder (L-R-Root): "; postorder(root); cout << endl;

    return 0;
}
