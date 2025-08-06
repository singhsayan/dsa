#include <iostream>
#include <unordered_set> // Include unordered_set for hash table
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a node at the head of the linked list
void InsertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printLL(Node* head) {
    if (head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to remove duplicates from the unsorted linked list
void removeDuplicates(Node* &head) {
    if (head == NULL) return;

    unordered_set<int> seen; // Hash table to store seen values
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        // If current data is already seen, skip it
        if (seen.find(current->data) != seen.end()) {
            previous->next = current->next; // Bypass the current node
            delete current; // Free memory
            current = previous->next; // Move to the next node
        } else {
            seen.insert(current->data); // Mark the data as seen
            previous = current; // Move previous to current
            current = current->next; // Move to the next node
        }
    }
}

int main() {
    Node* head = NULL;

    // Sample input: Inserting nodes
    InsertAtHead(head, 5);
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1); // Duplicate
    InsertAtHead(head, 3);
    InsertAtHead(head, 5); // Duplicate
    InsertAtHead(head, 4);

    cout << "Original Linked List: ";
    printLL(head);

    removeDuplicates(head); // Remove duplicates

    cout << "Linked List after removing duplicates: ";
    printLL(head);

    return 0;
}