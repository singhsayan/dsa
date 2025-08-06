#include<iostream>
using namespace std;

class node {
public:
    node* next;
    int data;
    node* head;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->head = NULL;
    }

    // Insert a node at the specified position
    void insert(node*& head, int x, int position) {
        if (head == NULL && position == 0) {
            head = new node(x);
            return;
        }
        
        int count = 0;
        node* nnode = new node(x);
        node* curr = head;
        
        while (curr != NULL && count < position - 1) {
            curr = curr->next;
            count++;
        }
        
        if (curr == NULL) {
            cout << "Position is out of range." << endl;
            delete nnode;
            return;
        }

        nnode->next = curr->next;
        curr->next = nnode;
    }

    // Delete a node by value
    void deleteNode(node*& head, int y) {
        if (head == NULL) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        if (head->data == y) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* curr = head;
        node* prev = NULL;

        while (curr != NULL && curr->data != y) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Node with value " << y << " not found." << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // Calculate the length of the list
    int length() {
        node* curr = head;
        int len = 0;
        while (curr != NULL) {
            curr = curr->next;
            len++;
        }
        return len;
    }

    // Search for an element in the list
    bool searchEle(int x) {
        node* curr = head;
        while (curr != NULL) {
            if (curr->data == x) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Print the list for user review
    void printList(node* head) {
        node* curr = head;
        if (curr == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    node* head = NULL;
    node list(0);  // Placeholder for the linked list operations
    int choice, value, position;

    do {
        cout << "\nLinked List Operations Menu:\n";
        cout << "1. Insert at position\n";
        cout << "2. Delete by value\n";
        cout << "3. Search for value\n";
        cout << "4. Print the list\n";
        cout << "5. Length of the list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insert(head, value, position);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(head, value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                cout << "Is the value " << value << " in the list? " 
                     << (list.searchEle(value) ? "Yes" : "No") << endl;
                break;

            case 4:
                list.printList(head);
                break;

            case 5:
                cout << "Length of the list: " << list.length() << endl;
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}