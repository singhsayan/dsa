#include<iostream>
using namespace std;

class heap {
    int arr[100];
    int size;

public:
    heap() {
        size = 0;
        arr[0] = -1;  // First element as -1 as a placeholder
    }

    void insert(int x) {
        size++;
        arr[size] = x; // Add element at the end

        int index = size;
        // Move the inserted element to its correct position in the heap
        while (index > 1 && arr[index / 2] > arr[index]) {
            swap(arr[index / 2], arr[index]);  // Swap with the parent
            index = index / 2;  // Move index up
        }
    }

    void change() {
        // To heapify the entire array (optional, not necessary after each insert)
        for (int i = size / 2; i >= 1; i--) {
            int parent = i;
            int leftChild = 2 * parent; 
            int rightChild = 2 * parent + 1;

            // Find the smallest among parent, left, and right child
            if (leftChild <= size && arr[leftChild] < arr[parent]) {
                parent = leftChild;
            }

            if (rightChild <= size && arr[rightChild] < arr[parent]) {
                parent = rightChild;
            }

            if(parent != i){
                swap(arr[i], arr[parent]);
                i = parent; // Repeat the process for the next index
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements for the heap:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        h.insert(val);
    }

    cout << "Heap after insertions: ";
    h.print();

    // Optionally call change() to heapify the array after manual insertions
    h.change();

    return 0;
}