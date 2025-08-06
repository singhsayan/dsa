#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Function to merge two sorted linked lists
Node<int>* mergeSortedLists(Node<int>* first, Node<int>* second) {
    // Create a dummy node to simplify the merging process
    Node<int>* dummy = new Node<int>(0);
    Node<int>* tail = dummy;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            tail->next = first; // Append first
            first = first->next; // Move first pointer
        } else {
            tail->next = second; // Append second
            second = second->next; // Move second pointer
        }
        tail = tail->next; // Move the tail pointer
    }

    // Append the remaining nodes of either list
    if (first != NULL) {
        tail->next = first;
    } else {
        tail->next = second;
    }

    Node<int>* mergedHead = dummy->next; // The head of the merged list
    delete dummy; // Delete the dummy node
    return mergedHead; // Return the head of the merged list
}

// Function to print the linked list
void printList(Node<int>* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating first sorted linked list: 1 -> 3 -> 5
    Node<int>* first = new Node<int>(1);
    first->next = new Node<int>(3);
    first->next->next = new Node<int>(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    Node<int>* second = new Node<int>(2);
    second->next = new Node<int>(4);
    second->next->next = new Node<int>(6);

    cout << "First Linked List: ";
    printList(first);
    cout << "Second Linked List: ";
    printList(second);

    // Merging the two sorted linked lists
    Node<int>* mergedList = mergeSortedLists(first, second);
    cout << "Merged Linked List: ";
    printList(mergedList);

    // Clean up memory (optional for this example)
    delete mergedList; // The destructor will delete all nodes

    return 0;
}