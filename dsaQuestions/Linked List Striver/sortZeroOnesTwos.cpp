#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a node at the tail of the list
void insertAtTail(Node*& tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Function to sort the linked list of 0s, 1s, and 2s
Node* sortList(Node* head) {
    Node* zeroHead = new Node(-1);  // Dummy head for 0s
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);   // Dummy head for 1s
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);   // Dummy head for 2s
    Node* twoTail = twoHead;

    Node* curr = head;

    // Create separate lists for 0s, 1s, and 2s
    while (curr != NULL) {
        int value = curr->data;
        if (value == 0) {
            insertAtTail(zeroTail, curr);
        } else if (value == 1) {
            insertAtTail(oneTail, curr);
        } else if (value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // Merge the three sublists
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;  // Attach 1s after 0s
    } else {
        zeroTail->next = twoHead->next;  // If 1s are empty, attach 2s
    }
    
    oneTail->next = twoHead->next;  // Attach 2s
    twoTail->next = NULL;            // End the list

    // Set the head to the first node of the sorted list
    head = zeroHead->next;

    // Delete dummy nodes to free memory
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// Function to print the linked list (for testing purposes)
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    
    cout << "Original list: ";
    printList(head);
    
    head = sortList(head);
    
    cout << "Sorted list: ";
    printList(head);
    
    return 0;
}