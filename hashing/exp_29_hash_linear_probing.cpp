/*
Experiment 29: Hash Table using Linear Probing
Topic: Hashing
Concepts Used:
- Hash Function
- Collision Handling (Linear Probing)
- Search and Insert
*/

#include <iostream>
using namespace std;

const int SIZE = 10; // table ka size
int hashTable[SIZE];

// table ko -1 se initialize karo (empty slot)
void initTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// hash function
int hashFunc(int key) {
    return key % SIZE;
}

// linear probing se insert karo
void insert(int key) {
    int idx = hashFunc(key);

    // collision hai toh aage khali jagah dhundho
    int i = 0;
    while (i < SIZE) {
        int newIdx = (idx + i) % SIZE;
        if (hashTable[newIdx] == -1) {
            hashTable[newIdx] = key;
            cout << "Inserted " << key << " at index " << newIdx << endl;
            return;
        }
        i++;
    }
    cout << "Table full! Cannot insert " << key << endl;
}

// search karo
void search(int key) {
    int idx = hashFunc(key);

    for (int i = 0; i < SIZE; i++) {
        int newIdx = (idx + i) % SIZE;
        if (hashTable[newIdx] == key) {
            cout << key << " found at index " << newIdx << endl;
            return;
        }
        // khali slot mil gayi matlab element nahi hai
        if (hashTable[newIdx] == -1) break;
    }
    cout << key << " not found." << endl;
}

// table print karo
void display() {
    cout << "\nHash Table:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        if (hashTable[i] == -1) cout << "EMPTY";
        else cout << hashTable[i];
        cout << endl;
    }
}

int main() {
    initTable();

    int keys[] = {15, 25, 35, 11, 21, 6};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "Inserting elements:" << endl;
    for (int i = 0; i < n; i++)
        insert(keys[i]);

    display();

    cout << "\nSearching:" << endl;
    search(25);
    search(99);

    return 0;
}
