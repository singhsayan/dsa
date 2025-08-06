#include <iostream>
using namespace std;

void insertionSortRecursive(int arr[], int n) {
    // Base case: if the array has only one element, it's already sorted
    if (n <= 1)
        return;

    // Recursively sort the first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert the nth element into the sorted part of the array
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements of arr[0..n-2] that are greater than last to one position ahead
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    // Place the last element at its correct position
    arr[j + 1] = last;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSortRecursive(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}