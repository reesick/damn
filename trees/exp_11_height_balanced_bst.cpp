/*
Experiment 11: Height Balanced BST Check
Topic: Trees
Concepts Used:
- Binary Tree
- Height Calculation
- Balance Factor (left height - right height)
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

// height calculate karo
int height(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// balanced check: har node pe |leftH - rightH| <= 1 hona chahiye
bool isBalanced(Node* root) {
    if (root == NULL) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    // balance factor 1 se zyada nahi hona chahiye
    if (abs(lh - rh) > 1) return false;

    // left aur right subtree bhi balanced hone chahiye
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40};
    for (int x : arr) root = insert(root, x);

    cout << "Height of tree: " << height(root) << endl;

    if (isBalanced(root))
        cout << "Tree is height balanced." << endl;
    else
        cout << "Tree is NOT height balanced." << endl;

    return 0;
}
