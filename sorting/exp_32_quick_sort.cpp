/*
Experiment 32: Quick Sort
Topic: Sorting
Concepts Used:
- Divide and Conquer
- Partition
- Quick Sort Recursion
*/

#include <iostream>
using namespace std;

// pivot choose karo aur partition karo
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // last element ko pivot banate hai
    int i = low - 1;       // chote elements ka index

    for (int j = low; j < high; j++) {
        // agar element pivot se chota hai
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // pivot ko sahi jagah pe rakho
    swap(arr[i + 1], arr[high]);
    return i + 1; // pivot ka final index
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return; // base case

    // partition karo
    int pi = partition(arr, low, high);

    // left aur right parts ko sort karo
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Before: "; printArr(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "After:  "; printArr(arr, n);

    return 0;
}
