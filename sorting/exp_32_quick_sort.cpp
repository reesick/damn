#include <iostream>
using namespace std;

/*
Experiment 32: Quick Sort
Sort student credit records in ascending order
*/


// pivot ko correct jagah pe set karega
int partition(int arr[], int low, int high) {

    // last element pivot
    int pivot = arr[high];

    // smaller element ka last index track karega
    int i = low - 1;


    // pivot ke pehle wale elements check karo
    for (int j = low; j < high; j++) {

        // agar current pivot se chota hai
        if (arr[j] < pivot) {

            i++;

            // swap arr[i] aur arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }


    // pivot ko correct position pe bhejo
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // pivot ka final index return
    return i + 1;
}


// recursive quick sort
void quickSort(int arr[], int low, int high) {

    // agar ek se zyada elements hai
    if (low < high) {

        // pivot ki correct position
        int p = partition(arr, low, high);

        // left side sort
        quickSort(arr, low, p - 1);

        // right side sort
        quickSort(arr, p + 1, high);
    }
}

int main() {

    // student credit records
    int arr[] = {8, 3, 5, 1};
    int n = 4;

    quickSort(arr, 0, n - 1);

    cout << "Sorted records: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}