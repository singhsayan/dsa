#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    int start = 0;             // Pointer at the beginning
    int end = size - 1;       // Pointer at the end

    while (start <= end) {
        // Swap the elements at start and end
        swap(arr[start], arr[end]);

        // Move the pointers closer to the center
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reverse the array
    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}