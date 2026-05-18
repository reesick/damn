/*
Experiment 13: Recursive Expression Tree Traversal
Topic: Trees
Concepts Used:
- Expression Tree
- Recursive Inorder, Preorder, Postorder
- Prefix, Infix, Postfix expressions
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char val) {
    Node* n = new Node();
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* buildExprTree(string postfix) {
    stack<Node*> st;
    for (char c : postfix) {
        Node* n = newNode(c);
        if (isOperator(c)) {
            n->right = st.top(); st.pop();
            n->left  = st.top(); st.pop();
        }
        st.push(n);
    }
    return st.top();
}

// inorder = infix expression
void inorder(Node* root) {
    if (root == NULL) return;
    if (isOperator(root->data)) cout << "(";
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    if (isOperator(root->data)) cout << ")";
}

// preorder = prefix expression
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// postorder = postfix expression
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    string postfix = "ab+cd-*";
    cout << "Postfix input: " << postfix << endl;

    Node* root = buildExprTree(postfix);

    cout << "Infix  (Inorder):   "; inorder(root);   cout << endl;
    cout << "Prefix (Preorder):  "; preorder(root);  cout << endl;
    cout << "Postfix (Postorder):"; postorder(root); cout << endl;

    return 0;
}
