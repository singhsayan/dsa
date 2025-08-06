#include <iostream>
#include <set>
#include <vector>

using namespace std;

void removeDuplicates(int arr[], int size) {
    set<int> uniqueElements; // Create a set to hold unique elements

    // Insert elements into the set
    for (int i = 0; i < size; i++) {
        uniqueElements.insert(arr[i]);
    }

    // Copy unique elements back to the array
    int index = 0;
    for (const int& element : uniqueElements) {
        arr[index++] = element; // Assign unique elements back to the array
    }

    // Optionally, resize the array if needed
    // size = uniqueElements.size(); // new size after removing duplicates
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueElements.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 6, 7, 5, 6, 4, 8, 9, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    removeDuplicates(arr, size);

    return 0;
}