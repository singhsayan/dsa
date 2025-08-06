#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    // Helper function to maintain the heap property
    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);  // Recursive call to heapify up the parent node
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        
        // Check if left child exists and is larger than the current node
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check if right child exists and is larger than the current largest
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If the largest is not the current node, swap and continue heapifying
        if (largest != index) {
            swap(heap[largest], heap[index]);
            heapifyDown(largest);  // Recursive call to heapify down
        }
    }

public:
    // Insert an element into the priority queue
    void insert(int value) {
        heap.push_back(value);       // Add the new element at the end
        heapifyUp(heap.size() - 1);  // Restore the heap property by heapifying up
    }

    // Extract the maximum element (highest priority)
    int extractMax() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty!");
        }
        int maxValue = heap[0];  // The root of the heap (max element)
        heap[0] = heap.back();   // Replace the root with the last element
        heap.pop_back();         // Remove the last element
        heapifyDown(0);          // Restore the heap property by heapifying down

        return maxValue;
    }

    // Peek at the maximum element without removing it
    int getMax() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty!");
        }
        return heap[0];
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Get the size of the priority queue
    int size() const {
        return heap.size();
    }

    // Display the heap elements (for debugging)
    void printHeap() const {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    
    pq.insert(15);
    pq.insert(10);
    pq.insert(30);
    pq.insert(5);
    pq.insert(12);
    
    cout << "Max element: " << pq.getMax() << endl; // Should print 30
    
    cout << "Priority queue after insertion: ";
    pq.printHeap();  // Should display the max-heap

    cout << "Extracting max element: " << pq.extractMax() << endl;  // Should extract 30
    cout << "Priority queue after extraction: ";
    pq.printHeap();  // Should restore heap after extraction

    return 0;
}