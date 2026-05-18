#include <iostream>
#include <queue>
using namespace std;

/*
Experiment 08: BST Level Wise Traversal
Concepts:
- BST
- Queue
- BFS
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {

    if (root == NULL){       
        return new Node {value,NULL, NULL};
    }

    if (value< root->data){
        root->left = insert(root->left,value);
    }

    else{
        root->right = insert(root->right,value);
    }
    
    return root;
    
}

void levelOrder(Node* root) {

    // tree empty
    if (root == NULL)
        return;

    // queue node addresses store karega
    queue<Node*> q;

    // root se start
    q.push(root);

    while (!q.empty()) {

        // front node nikalo
        Node* temp = q.front();
        q.pop();

        // print current node
        cout << temp->data << " ";

        // left child hai toh queue me dalo
        if (temp->left != NULL)
            q.push(temp->left);

        // right child hai toh queue me dalo
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 8);

    cout <<&root;

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}