#include <iostream>
#include<queue>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap() {
            size = 0;
            arr[0] = -1;
        }
        
        void insert(int val) {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while (index > 1) {
                int parent = index / 2;

                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } 
                else {
                    return;
                }
            }
        }

        void deleteFromHeap() {
            if (size == 0) {
                cout << "Nothing to delete" << endl;
                return;
            }
            arr[1] = arr[size];
            size--;

            int i = 1;
            while (i <= size) {
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;

                int largest = i;
                if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
                    largest = leftIndex;
                }
                if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
                    largest = rightIndex;
                }

                if (largest != i) {
                    swap(arr[i], arr[largest]);
                    i = largest;
                } 
                else {
                    break;
                }
            }
        }

        void heapify(int arr[], int n, int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left <= n && arr[largest] < arr[left]) {
                largest = left;
            }
            if (right <= n && arr[largest] < arr[right]) {
                largest = right;
            }

            if (largest != i) {
                swap(arr[largest], arr[i]);
                heapify(arr, n, largest);
            }
        }

        void buildMaxHeap(int arr[], int n) {
            // Build heap (rearrange array)
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, n, i); // Call heapify on each node
        }
}

        void heapSort(int arr[], int n) {
            // Build the heap
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, n, i);
            }

            // Extract elements from the heap
            int size = n; // Maintain local size for sorting
            while (size > 1) {
                // Step 1: Swap the root with the last element
                swap(arr[0], arr[size - 1]);

                // Step 2: Reduce the size of the heap
                size--;

                // Step 3: Heapify the root element to maintain the heap property
                heapify(arr, size, 0);
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

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout << endl;
    
    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i >= 1; i--) {  // Start from n/2 down to 1
        h.heapify(arr, n, i);
    }

    cout << "Printing the array now" << endl;
    for (int i = 1; i <= n; i++) {  // Start from 1 for 1-based index
        cout << arr[i] << " ";
    }
    cout << endl;

    h.heapSort(arr, n);

    cout << "After sorting: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Using priority queue" << endl;

    // maxheap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Element at top" << pq.top() << endl;

    // min heap

    priority_queue< int, vector<int> , greater<int> > minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Element at top" << pq.top() << endl;


    return 0;
}