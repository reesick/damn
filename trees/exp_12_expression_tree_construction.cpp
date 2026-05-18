#include <iostream>
#include <stack>
using namespace std;

/*
Experiment 12: Expression Tree Construction
Concepts:
- Stack
- Expression Tree
- Postfix
*/

struct Node {
    char data;
    Node* left;
    Node* right;
};


// helper node creation
Node* createNode(char value) {

    // naya node banao
    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// operator check
bool isOperator(char ch) {

    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


// tree build from postfix
Node* buildTree(string postfix) {

    // stack node addresses store karega
    stack<Node*> st;

    for (char ch : postfix) {

        // agar operand hai
        if (!isOperator(ch)) {

            // simple node banao aur push
            st.push(createNode(ch));
        }

        else {

            // operator mila

            // first pop = right child
            Node* right = st.top();
            st.pop();

            // second pop = left child
            Node* left = st.top();
            st.pop();

            // operator node banao
            Node* opNode = createNode(ch);

            // children connect karo
            opNode->left = left;
            opNode->right = right;

            // new mini tree stack me push
            st.push(opNode);
        }
    }

    // final tree root
    return st.top();
}


// inorder just for verification
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    string postfix = "AB+C*";

    Node* root = buildTree(postfix);

    cout << "Inorder Expression: ";
    inorder(root);

    return 0;
}