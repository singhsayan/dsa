#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Parameterized constructor
    Node(int data) : data(data), next(NULL) {}
};

// Function to insert at the head of CLL
void InsertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  // Circular link
    } else {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

// Function to insert at the tail of CLL
void InsertAtTail(Node* &tail, Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  // Circular link
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert at any position in CLL
void InsertAtPosition(Node* &head, Node* &tail, int data, int position, int &size) {
    if (position < 1 || position > size + 1) {
        cout << "Please enter a valid position to insert the new node" << endl;
        return;
    }
    if (position == 1) {
        InsertAtHead(head, tail, data);
    } else {
        Node* newNode = new Node(data);
        Node* temp = head;
        for (int count = 1; count < position - 1; count++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (position == size + 1) {
            tail = newNode;  // Update tail if inserted at the last position
        }
    }
    size++;
}

// Function to delete a node at a given position in CLL
void deleteNode(Node* &head, Node* &tail, int position, int &size) {
    if (head == NULL) {
        cout << "Circular Linked List is empty" << endl;
        return;
    }

    Node* temp = head;
    if (position == 1) {
        if (head == tail) {  // Only one node in CLL
            delete head;
            head = tail = NULL;
        } else {
            tail->next = head->next;
            head = head->next;
            delete temp;
        }
    } else {
        Node* previous = NULL;
        for (int count = 1; count < position; count++) {
            previous = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        previous->next = temp->next;
        if (temp == tail) {
            tail = previous;  // Update tail if last node is deleted
        }
        delete temp;
    }
    size--;
}

// Function to find length of CLL
int LengthOfCLL(Node* head) {
    if (head == NULL) return 0;
    int size = 1;
    Node* temp = head->next;
    while (temp != head) {
        size++;
        temp = temp->next;
    }
    return size;
}

// Function to print CLL
void printCLL(Node* head) {
    if (head == NULL) {
        cout << "Circular Linked List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Head)" << endl;
}

// Function to reverse a CLL
void reverseCLL(Node*& tail) {
    if (tail == nullptr || tail->next == tail) {
        // Empty list or single-node list
        return;
    }

    Node* prev = nullptr;
    Node* current = tail->next;
    Node* head = tail->next;

    while (current != tail) {  // Traverse until the current node reaches the tail
        Node* next = current->next;  // Store the next node
        current->next = prev;        // Reverse the link
        prev = current;              // Move prev forward
        current = next;              // Move current forward
    }

    // Reverse the link for the tail node and update the tail
    current->next = prev;  // Tail now points to the new head
    tail->next = current;  // Update tail->next to point to the new head
    tail = head;           // Update the tail pointer
}

bool isCircular(Node* head) {
    if (head == NULL) return true;  // An empty list is considered circular

    Node* temp = head->next;
    // Traverse the list, and if we reach the head again, it's circular
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    
    return (temp == head);  // True if circular, false otherwise
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    while (true) {
        cout << "\n(1) Insert at Head\n(2) Insert at Tail\n(3) Insert at Position\n(4) Delete a Node\n(5) Length of Circular Linked List\n(6) Print Circular Linked List\n(7) Reverse Circular Linked List\n(8) Exit\n";
        int option;
        cout << "Choose an option: ";
        cin >> option;

        if (option == 8) break;

        if (option == 1 || option == 2 || option == 3) {
            int value;
            cout << "Enter the value: ";
            cin >> value;
            if (option == 1) {
                InsertAtHead(head, tail, value);
            } else if (option == 2) {
                InsertAtTail(tail, head, value);
            } else if (option == 3) {
                int position;
                cout << "Enter position: ";
                cin >> position;
                InsertAtPosition(head, tail, value, position, size);
            }
            size++;
        } else if (option == 4) {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            deleteNode(head, tail, position, size);
        } else if (option == 5) {
            cout << "Length of Circular Linked List: " << LengthOfCLL(head) << endl;
        } else if (option == 6) {
            printCLL(head);
        } else if (option == 7) {
            head = reverseCLL(head, tail);
            cout << "Reversed Circular Linked List: ";
            printCLL(head);
        } else {
            cout << "Invalid option. Try again." << endl;
        }
    }
    return 0;
}