#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;      // Data of the node
    Node* next;    // Pointer to the next node

    Node(int value) {
        data = value;
        next = nullptr; // Initialize next to null
    }
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front node
    Node* rear;  // Pointer to the rear node

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode; // Link new node at the end of the queue
            rear = newNode;       // Update rear to the new node
        }
        cout << value << " enqueued to queue." << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return -1 if queue is empty
        }
        int value = front->data; // Get the front value
        Node* temp = front;      // Store the front node
        front = front->next;     // Move front to the next node
        delete temp;             // Free memory of the old front

        // If the queue becomes empty after dequeuing
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << value << " dequeued from queue." << endl;
        return value; // Return the dequeued value
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free up the allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Dequeue all elements
        }
    }
};

// Main function to test the queue implementation
int main() {
    Queue q;

    // Sample operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Display queue

    q.dequeue();
    q.display(); // Display queue after dequeue

    q.enqueue(40);
    q.display(); // Display queue again

    q.dequeue();
    q.dequeue();
    q.display(); // Display queue after more dequeues

    q.dequeue(); // Dequeue from empty queue

    return 0;
}