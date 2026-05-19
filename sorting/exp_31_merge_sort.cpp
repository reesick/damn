#include <iostream>
using namespace std;

/*
Experiment 31: Merge Sort
Sort student credit records in ascending order
*/


// do sorted halves ko merge karega
void merge(int arr[], int left, int mid, int right) {

    int temp[50];   // temporary array
    int i = left;   // left half start
    int j = mid + 1; // right half start
    int k = left;   // temp index


    // dono halves compare karo
    while (i <= mid && j <= right) {

        // jo chota hai temp me dalo
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }


    // agar left side me elements bache
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }


    // agar right side me elements bache
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }


    // sorted temp ko original array me copy karo
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}


// array ko recursively split karega
void mergeSort(int arr[], int left, int right) {

    // ek hi element hai toh already sorted
    if (left < right) {

        // middle nikalo
        int mid = (left + right) / 2;

        // left half sort
        mergeSort(arr, left, mid);

        // right half sort
        mergeSort(arr, mid + 1, right);

        // dono sorted halves merge
        merge(arr, left, mid, right);
    }
}

int main() {

    // student credit records
    int arr[] = {8, 3, 5, 1};
    int n = 4;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted records: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}