#include <iostream>
#include <queue>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
        arr[0] = -1; // Dummy value to make the index 1-based
    }

    void insert(int x) {
        size++;
        arr[size] = x;

        // Heapify up to maintain the min-heap property
        int i = size;
        while (i > 1) {
            int parent = i / 2;
            if (arr[parent] > arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    int findKthLargest(int arr[], int size, int k) {
        // Min-heap to store the k largest elements
        heap minHeap;

        // Step 1: Push the first k elements into the min-heap
        for (int i = 0; i < k; i++) {
            minHeap.insert(arr[i]);
        }

        // Step 2: Process the remaining elements
        for (int i = k; i < size; i++) {
            if (arr[i] > minHeap.arr[1]) { // minHeap.arr[1] is the root (min element)
                minHeap.arr[1] = arr[i];
                int index = 1;
                while (index <= k) {
                    int leftChild = 2 * index;
                    int rightChild = 2 * index + 1;
                    int smallest = index;

                    if (leftChild <= k && minHeap.arr[leftChild] < minHeap.arr[smallest]) {
                        smallest = leftChild;
                    }
                    if (rightChild <= k && minHeap.arr[rightChild] < minHeap.arr[smallest]) {
                        smallest = rightChild;
                    }

                    if (smallest == index) {
                        break;
                    }
                    swap(minHeap.arr[smallest], minHeap.arr[index]);
                    index = smallest;
                }
            }
        }

        return minHeap.arr[1]; // The kth largest element is at the root
    }
};

int main() {
    int n, k;

    // Take input from the user for the array size and kth value
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; // Declare an array of size n

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k (the kth largest element): ";
    cin >> k;

    // Create an object of the heap class
    heap h;

    // Find and output the kth largest element
    int result = h.findKthLargest(arr, n, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}