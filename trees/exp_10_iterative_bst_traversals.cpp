#include <iostream>
#include <stack>
using namespace std;

/*
Experiment 10: Iterative BST Traversal
Concepts:
- BST
- Stack
- Iterative Inorder
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {

    if (root == NULL)
        return new Node{value, NULL, NULL};

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {

    stack<Node*> st;
    Node* current = root;

    while (current != NULL || !st.empty()) {

        // left side push karte jao
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }

        // top nikalo
        current = st.top();
        st.pop();

        // print
        cout << current->data << " ";

        // right side
        current = current->right;
    }
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 8);

    cout << "Iterative Inorder: ";
    inorder(root);

    return 0;
}