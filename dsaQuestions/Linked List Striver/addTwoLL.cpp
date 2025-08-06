#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} // Constructor for Node
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            Node* next = curr->next; // Store next node
            curr->next = prev;        // Reverse the link
            prev = curr;              // Move prev forward
            curr = next;              // Move curr forward
        }
        return prev; // New head of the reversed list
    }

    void insertAtTail(Node*& head, Node*& tail, int val) {
        Node* temp = new Node(val);
        if (head == nullptr) { // Empty list
            head = tail = temp;
        } else {
            tail->next = temp; // Link the new node
            tail = temp;       // Update tail
        }
    }

    Node* add(Node* first, Node* second) {
        Node* ansHead = nullptr;
        Node* ansTail = nullptr;
        int carry = 0;

        while (first != nullptr || second != nullptr || carry != 0) {
            int val1 = (first != nullptr) ? first->data : 0;
            int val2 = (second != nullptr) ? second->data : 0;

            int sum = carry + val1 + val2;
            insertAtTail(ansHead, ansTail, sum % 10); // Create node for the digit
            carry = sum / 10; // Calculate carry for the next iteration

            if (first != nullptr) first = first->next;
            if (second != nullptr) second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked lists
    Node* addTwoLists(Node* first, Node* second) {
        // Step 1: Reverse input linked lists
        first = reverse(first);
        second = reverse(second);

        // Step 2: Add the two linked lists
        Node* ans = add(first, second);

        // Step 3: Reverse the result to get the final answer
        return reverse(ans);
    }
};

// Function to print the linked list (for testing purposes)
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    Solution solution;

    Node* first = new Node(3);
    first->next = new Node(4);
    first->next->next = new Node(2); // Represents number 243

    Node* second = new Node(4);
    second->next = new Node(6);
    second->next->next = new Node(5); // Represents number 465

    Node* result = solution.addTwoLists(first, second);

    cout << "Resultant Linked List: ";
    printList(result); // Should print 7 0 8 which represents 807

    return 0;
}