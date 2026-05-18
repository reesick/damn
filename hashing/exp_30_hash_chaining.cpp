/*
Experiment 30: Hash Table using Chaining
Topic: Hashing
Concepts Used:
- Hash Function
- Collision Handling (Separate Chaining)
- Linked List at each bucket
*/

#include <iostream>
using namespace std;

const int SIZE = 7;

// chain ke liye linked list node
struct Node {
    int data;
    Node* next;
};

Node* hashTable[SIZE]; // array of linked list heads

void initTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}

int hashFunc(int key) {
    return key % SIZE;
}

// chain me insert karo
void insert(int key) {
    int idx = hashFunc(key);
    Node* n = new Node();
    n->data = key;
    // front me insert karo (O(1))
    n->next = hashTable[idx];
    hashTable[idx] = n;
    cout << "Inserted " << key << " at index " << idx << endl;
}

// chain me search karo
void search(int key) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    while (curr != NULL) {
        if (curr->data == key) {
            cout << key << " found at index " << idx << endl;
            return;
        }
        curr = curr->next;
    }
    cout << key << " not found." << endl;
}

// table print karo
void display() {
    cout << "\nHash Table (Chaining):" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* curr = hashTable[i];
        while (curr != NULL) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        if (hashTable[i] == NULL) cout << "EMPTY";
        cout << endl;
    }
}

int main() {
    initTable();

    int keys[] = {15, 25, 35, 11, 21, 6, 13};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "Inserting elements:" << endl;
    for (int i = 0; i < n; i++)
        insert(keys[i]);

    display();

    cout << "\nSearching:" << endl;
    search(21);
    search(99);

    return 0;
}
