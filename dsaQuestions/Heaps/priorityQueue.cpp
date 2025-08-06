#include <iostream>
using namespace std;

class heap {
public:
    int size;
    int arr[100];

    heap() {
        size = 0; // Initialize size to 0
        arr[0] = -1; // Not used, but keeping index 0 as a placeholder for simplicity
    }

    void heapifyUp(int idx) {
        if (idx == 1) return;

        int parent = idx / 2;
        if (arr[parent] < arr[idx]) {
            swap(arr[parent], arr[idx]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int idx) {
        int largest = idx;
        int left = 2 * idx;
        int right = 2 * idx + 1;

        if (left <= size && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right <= size && arr[largest] < arr[right]) {
            largest = right;
        }
        if (largest != idx) {
            swap(arr[largest], arr[idx]);
            heapifyDown(largest);
        }
    }

    void insert(int value) {
        size++;
        arr[size] = value;
        heapifyUp(size);
    }

    int getMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return arr[1]; // Root of the heap
    }

    void removeMax() {
        if (size == 0) {
            cout << "Heap is empty, cannot remove!" << endl;
            return;
        }

        // Replace root with the last element
        arr[1] = arr[size];
        size--;

        // Heapify down from the root
        heapifyDown(1);
    }

    void displayHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap pq; // Priority queue using heap
    int choice, value;

    cout << "Priority Queue using Heap" << endl;
    while (true) {
        cout << "\n1. Insert\n2. Get Max\n3. Remove Max\n4. Display Heap\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                cout << "Maximum element: " << pq.getMax() << endl;
                break;

            case 3:
                cout << "Removing maximum element..." << endl;
                pq.removeMax();
                break;

            case 4:
                cout << "Current heap: ";
                pq.displayHeap();
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }
}