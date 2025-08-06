#include <iostream>
using namespace std;

void bubbleSortRecursive(int arr[], int n) {
    // Base case: if the array size is 1 or less, no need to sort
    if (n == 1)
        return;

    // Traverse through the array from 0 to n-1
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            // Swap arr[i] and arr[i + 1]
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for the next pass with reduced array size
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}