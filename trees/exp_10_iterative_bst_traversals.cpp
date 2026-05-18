/*
Experiment 10: Iterative BST Traversals
Topic: Trees
Concepts Used:
- Binary Search Tree
- Stack-based Iterative Traversal
- Inorder, Preorder (Iterative)
*/

#include <iostream>
#include <stack>
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

// iterative inorder: stack use karke left me jao, print karo, right pe jao
void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        // left me jaate jao aur stack me push karo
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        // ab backtrack karo
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        // ab right subtree dekho
        curr = curr->right;
    }
    cout << endl;
}

// iterative preorder: root print karo, phir right then left push karo
void iterativePreorder(Node* root) {
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        cout << curr->data << " ";

        // right pehle push karo taaki left pehle process ho
        if (curr->right) st.push(curr->right);
        if (curr->left)  st.push(curr->left);
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) root = insert(root, x);

    cout << "Iterative Inorder:  "; iterativeInorder(root);
    cout << "Iterative Preorder: "; iterativePreorder(root);

    return 0;
}
