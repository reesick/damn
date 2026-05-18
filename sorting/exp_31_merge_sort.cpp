/*
Experiment 31: Merge Sort
Topic: Sorting
Concepts Used:
- Divide and Conquer
- Merge Sort
- Recursion
*/

#include <iostream>
using namespace std;

// do sorted halves ko merge karo
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temporary arrays
    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // dono arrays ko compare karke merge karo
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }

    // bacha hua copy karo
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// recursively split karo aur merge karo
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return; // base case: 1 element

    int mid = (left + right) / 2;

    // left aur right half ko sort karo
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // sorted halves ko merge karo
    merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    cout << "After:  "; printArr(arr, n);

    return 0;
}
