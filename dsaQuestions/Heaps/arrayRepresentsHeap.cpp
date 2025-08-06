#include <iostream>
using namespace std;

class heap {
    public:
        int arr[100];  // Fixed-size array
        int size;      // To track the number of elements in the heap

        heap() {
            size = 0;
            arr[0] = -1;  // Initialize with a dummy value at index 0
        }

        bool check() {
            // Iterate through the array and check if the heap property is satisfied
            for (int i = 1; i < size; i++) {  // Using the size to limit iteration
                int parent = i / 2;
                if (arr[parent] > arr[i]) {
                    return false;  // Heap property violated
                }
            }
            return true;  // Heap property is satisfied
        }

        void insert(int x) {
            // Insert the element at the end of the heap
            size++;
            arr[size] = x;

            // Maintain the heap property
            int index = size;
            while (index > 1 && arr[index / 2] > arr[index]) {
                // Swap with parent if the parent is greater
                swap(arr[index], arr[index / 2]);
                index /= 2;
            }
        }
};

int main() {
    heap h;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Input heap elements from the user
    cout << "Enter " << n << " elements for the heap:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        h.insert(val);
    }

    // Check if the heap property is satisfied
    if (h.check()) {
        cout << "The heap property is maintained!" << endl;
    } else {
        cout << "The heap property is violated!" << endl;
    }

    return 0;
}