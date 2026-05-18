/*
Experiment 28: Minimum Marks using Min Heap
Topic: Heaps
Concepts Used:
- Min Heap
- Heap Insertion
- Heapify Up / Down
*/

#include <iostream>
using namespace std;

int heap[100]; // min heap array
int heapSize = 0;

// naya element insert karo aur upar le jao
void insertMinHeap(int val) {
    heap[++heapSize] = val;
    int i = heapSize;

    // jab tak parent se chota hai tab tak upar jao
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

// minimum nikalo (root)
int extractMin() {
    int minVal = heap[1]; // root = min
    heap[1] = heap[heapSize--]; // last ko root pe rakho

    // heapify down
    int i = 1;
    while (true) {
        int smallest = i;
        int left = 2 * i, right = 2 * i + 1;

        if (left <= heapSize && heap[left] < heap[smallest])
            smallest = left;
        if (right <= heapSize && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;
        swap(heap[i], heap[smallest]);
        i = smallest;
    }
    return minVal;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks:" << endl;
    for (int i = 0; i < n; i++) {
        int marks;
        cin >> marks;
        insertMinHeap(marks);
    }

    cout << "Minimum Marks: " << extractMin() << endl;

    cout << "Marks in ascending order: ";
    while (heapSize > 0)
        cout << extractMin() << " ";
    cout << endl;

    return 0;
}
