#include <iostream>
using namespace std;

/*
Experiment 03: Height of Binary Tree
Concepts:
- Binary Tree
- Recursion
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* root) {

    // agar node nahi hai toh height 0
    if (root == NULL)
        return 0;

    // left subtree ki height
    int leftHeight = height(root->left);

    // right subtree ki height
    int rightHeight = height(root->right);

    // bada wala lo + current node
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
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

    cout << "Height of tree: " << height(root);

    return 0;
}