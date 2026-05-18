#include <iostream>
using namespace std;

/*
Experiment 11: Height Balanced BST
Concepts:
- BST
- Height
- Recursion
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


// height nikalne ka same old logic
int height(Node* root) {

    // node nahi hai
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}


// balance check
bool isBalanced(Node* root) {

    // empty tree balanced hota hai
    if (root == NULL)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = leftHeight - rightHeight;

    // absolute difference manually
    if (diff < 0)
        diff = -diff;

    // agar difference 1 se bada hai toh fail
    if (diff > 1)
        return false;

    // left aur right subtree bhi balanced hone chahiye
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 8);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}