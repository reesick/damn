/*
Experiment 12: Expression Tree Construction
Topic: Trees
Concepts Used:
- Expression Tree
- Stack-based Construction
- Postfix Expression
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

// check karo operator hai ya operand
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// postfix expression se expression tree banate hai
Node* buildExprTree(string postfix) {
    stack<Node*> st;

    for (char c : postfix) {
        Node* n = newNode(c);

        if (isOperator(c)) {
            // operator ke liye 2 operands stack se nikalo
            n->right = st.top(); st.pop(); // pehle right
            n->left  = st.top(); st.pop(); // phir left
        }
        // node stack me push karo
        st.push(n);
    }

    // stack ka top hi root hoga
    return st.top();
}

// inorder traversal = infix expression
void inorder(Node* root) {
    if (root == NULL) return;
    if (root->left)  { cout << "("; inorder(root->left); }
    cout << root->data;
    if (root->right) { inorder(root->right); cout << ")"; }
}

int main() {
    // postfix: ab+cd-*  means (a+b)*(c-d)
    string postfix = "ab+cd-*";
    cout << "Postfix: " << postfix << endl;

    Node* root = buildExprTree(postfix);

    cout << "Infix (Expression Tree Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
