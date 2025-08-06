#include<iostream>
using namespace std;

class node {
public:
    node* next;
    node* prev;
    int data;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Insert a new node at the given position
    void insert(int x, int position, node* &head) {
        if (head == NULL && position == 1) {
            head = new node(x);
        }
        else if (head != NULL && position == 1) {
            node* ele = new node(x);
            ele->next = head;
            head->prev = ele;
            head = ele;
        }
        else {
            int count = 1;
            node* curr = head;
            node* temp = new node(x);
            while (count < position - 1) {
                count++;
                curr = curr->next;
            }
            temp->next = curr->next;
            if (curr->next != NULL) {
                curr->next->prev = temp;
            }
            curr->next = temp;
            temp->prev = curr;
        }
    }

    // Delete the node at the given position
    node* deleteNode(int position, node* &head) {
        if (head == NULL) return NULL;
        int count = 1;
        node* curr = head;
        node* prev = NULL;
        while (count < position) {
            count++;
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        }
        else if (curr->next == NULL) {
            prev->next = NULL;
        }
        else {
            prev->next = curr->next;
            curr->next->prev = prev;
        }
        delete curr;
        return head;
    }

    // Reverse the doubly linked list
    node* reverseDLL(node* &head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        node* curr = head;
        node* temp = NULL;
        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != NULL) {
            head = temp->prev;
        }
        return head;
    }

    // Delete all nodes with the given value
    void deleteAllKey(int target, node* &head) {
        if (head == NULL) return;
        node* curr = head;
        while (curr != NULL) {
            if (curr->data == target) {
                if (curr->prev != NULL) {
                    curr->prev->next = curr->next;
                }
                if (curr->next != NULL) {
                    curr->next->prev = curr->prev;
                }
                if (curr == head) {
                    head = curr->next;
                }
                node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }
    }

    // Find a pair of nodes whose sum equals the given value
    pair<int, int> sumPair(int sum, node* head) {
        if (head == NULL) return {0, 0};
        node* left = head;
        node* right = head;
        while (right->next != NULL) {
            right = right->next;
        }

        while (left != right && left->prev != right) {
            if (left->data + right->data == sum) {
                return {left->data, right->data};
            }
            else if (sum < (left->data + right->data)) {
                right = right->prev;
            }
            else {
                left = left->next;
            }
        }
        return {0, 0}; // No such pair found
    }

    // Remove duplicates from the doubly linked list
    node* removeDuplicates(node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        node* prev = NULL;
        node* curr = head;
        while (curr != NULL) {
            if (prev != NULL && prev->data == curr->data) {
                curr->next->prev = curr->prev;
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

    // Reverse the list in groups of k
    node* reverseK(node* &head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        node* curr = head;
        node* prev = NULL;
        node* forward = NULL;
        int count = 0;

        node* temp = head;
        while (count < k && temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (count == k) {
            temp = head;
            count = 0;

            while (count < k) {
                forward = temp->next;
                temp->next = prev;
                prev = temp;
                temp = forward;
                count++;
            }
            head->next = reverseK(temp, k);
            return prev;
        }
        return head;
    }

    // Rotate the list by k positions
    node* rotate(node* &head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        node* current = head;
        int length = 1;

        while (current->next != NULL) {
            current = current->next;
            length++;
        }
        current->next = head;
        k = k % length;
        int stepsToNewHead = length - k;
        node* newTail = head;

        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        node* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};

int main() {
    node* head = NULL;
    node* list = new node(10);
    head = list;

    // Insert nodes
    list->insert(20, 2, head);
    list->insert(30, 3, head);

    // Print list (forward)
    node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete a node at position 2
    head = list->deleteNode(2, head);

    // Print list after deletion
    temp = head;
    cout << "After deletion: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse the list
    head = list->reverseDLL(head);

    // Print reversed list
    temp = head;
    cout << "Reversed List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Rotate the list by 1 position
    head = list->rotate(head, 1);

    // Print rotated list
    temp = head;
    cout << "Rotated List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}