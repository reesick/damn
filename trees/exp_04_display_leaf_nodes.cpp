#include <iostream>
using namespace std;

/*
Experiment 04: Display Leaf Nodes
Concepts:
- Binary Tree
- Recursion
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

void displayLeaf(Node* root) {

    // agar node nahi hai toh stop
    if (root == NULL)
        return;

    // agar dono children nahi hai toh leaf node
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    // left subtree check karo
    displayLeaf(root->left);

    // right subtree check karo
    displayLeaf(root->right);
}

int main() {

    /*
            10
           /  \
          5    20
         / \
        2   8
    */

    Node* root = new Node{10, NULL, NULL};

    root->left = new Node{5, NULL, NULL};
    root->right = new Node{20, NULL, NULL};

    root->left->left = new Node{2, NULL, NULL};
    root->left->right = new Node{8, NULL, NULL};

    cout << "Leaf nodes: ";
    displayLeaf(root);

    return 0;
}