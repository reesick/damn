#include <iostream>
#include <stack>
using namespace std;

/*
Experiment 14: Non Recursive Expression Tree Traversal
Concepts:
- Stack
- Expression Tree
- Iterative Inorder
*/

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char value) {

    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
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

        // top node nikalo
        current = st.top();
        st.pop();

        // print
        cout << current->data << " ";

        // right subtree
        current = current->right;
    }
}

int main() {

    /*
          +
         / \
        *   C
       / \
      A   B
    */

    Node* root = createNode('+');

    root->left = createNode('*');
    root->right = createNode('C');

    root->left->left = createNode('A');
    root->left->right = createNode('B');

    cout << "Iterative Inorder: ";
    inorder(root);

    return 0;
}