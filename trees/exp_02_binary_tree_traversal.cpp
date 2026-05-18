/*
Experiment 02: Binary Tree Traversal
Topic: Trees
Concepts Used:
- Recursion
- Inorder, Preorder, Postorder Traversal
- Binary Tree
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

// Left -> Root -> Right
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
    // sample tree banate hai
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node{1,NULL,NULL};
    root->left = new Node{2,NULL,NULL};
    root->right = new Node{3,NULL,NULL};
    root->left->left = new Node{4,NULL,NULL};
    root->left->right = new Node{5,NULL,NULL};

    cout << "Inorder:   "; inorder(root);   cout << endl;
    cout << "Preorder:  "; preorder(root);  cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    return 0;
}
