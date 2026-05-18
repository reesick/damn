/*
Experiment 27: Maximum Marks using Max Heap
Topic: Heaps
Concepts Used:
- Max Heap
- Heap Insertion
- Heapify Up
*/

#include <iostream>
using namespace std;

int heap[100]; // max heap array
int heapSize = 0;

// naya element insert karo aur upar le jao
void insertMaxHeap(int val) {
    heap[++heapSize] = val; // end me daalo
    int i = heapSize;

    // jab tak parent se bada hai tab tak upar jao
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

// top element nikalo (maximum)
int extractMax() {
    int maxVal = heap[1]; // root = max
    heap[1] = heap[heapSize--]; // last ko root pe rakho
    
    // heapify down karo
    int i = 1;
    while (true) {
        int largest = i;
        int left = 2 * i, right = 2 * i + 1;
        
        if (left <= heapSize && heap[left] > heap[largest])
            largest = left;
        if (right <= heapSize && heap[right] > heap[largest])
            largest = right;
        
        if (largest == i) break;
        swap(heap[i], heap[largest]);
        i = largest;
    }
    return maxVal;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks:" << endl;
    for (int i = 0; i < n; i++) {
        int marks;
        cin >> marks;
        insertMaxHeap(marks);
    }

    cout << "Maximum Marks: " << extractMax() << endl;

    cout << "Marks in descending order: ";
    while (heapSize > 0)
        cout << extractMax() << " ";
    cout << endl;

    return 0;
}
