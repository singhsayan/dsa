#include <iostream>
using namespace std;

class Deque {
    int *arr;
    int front, rear, capacity;

public:
    // Constructor
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    // Insert at front
    void insertFront(int value) {
        if ((front == 0 && rear == capacity - 1) || (rear + 1 == front)) {
            cout << "Deque is full\n";
            return;
        }

        if (front == -1) { // If deque is empty
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1; // Wrap around
        } else {
            front--;
        }
        arr[front] = value;
    }

    // Insert at rear
    void insertRear(int value) {
        if ((front == 0 && rear == capacity - 1) || (rear + 1 == front)) {
            cout << "Deque is full\n";
            return;
        }

        if (rear == -1) { // If deque is empty
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0; // Wrap around
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    // Delete from front
    void deleteFront() {
        if (front == -1) { // If deque is empty
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) { // Single element
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }
    }

    // Delete from rear
    void deleteRear() {
        if (rear == -1) { // If deque is empty
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) { // Single element
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1; // Wrap around
        } else {
            rear--;
        }
    }

    // Print the deque
    void printDeque() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity; // Move to next index (circular)
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    dq.printDeque();

    dq.deleteFront();
    dq.deleteRear();

    dq.printDeque();

    return 0;
}