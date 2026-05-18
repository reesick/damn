/*
Experiment 14: Non-Recursive Expression Tree Traversal
Topic: Trees
Concepts Used:
- Expression Tree
- Stack-based Iterative Traversal
- Postfix, Prefix using stack
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
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

// iterative inorder using stack
void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data;
        curr = curr->right;
    }
    cout << endl;
}

// iterative postorder: do-reverse trick using 2 stacks
void iterativePostorder(Node* root) {
    if (root == NULL) return;
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top(); s1.pop();
        s2.push(curr);
        if (curr->left)  s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    // s2 me ulta order hai, seedha print karo
    while (!s2.empty()) {
        cout << s2.top()->data;
        s2.pop();
    }
    cout << endl;
}

// iterative preorder
void iterativePreorder(Node* root) {
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        cout << curr->data;
        if (curr->right) st.push(curr->right);
        if (curr->left)  st.push(curr->left);
    }
    cout << endl;
}

int main() {
    string postfix = "ab+cd-*";
    cout << "Postfix input: " << postfix << endl;

    Node* root = buildExprTree(postfix);

    cout << "Infix  (Iterative Inorder):   "; iterativeInorder(root);
    cout << "Prefix (Iterative Preorder):  "; iterativePreorder(root);
    cout << "Postfix(Iterative Postorder): "; iterativePostorder(root);

    return 0;
}
