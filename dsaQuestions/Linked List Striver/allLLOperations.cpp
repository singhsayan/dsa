#include <iostream>
#include<algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void InsertAtPosition(Node* &head, int data, int position, int size) {
    if (position == 1) {
        InsertAtHead(head, data);
        return;
    } 
    else if (position > size + 1 || position <= 0) {
        cout << "Please enter a valid position to insert the new node" << endl;
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head, int position) {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node* temp = head;
    Node* previous = NULL;

    if (position == 1) {
        head = temp->next;
        delete temp;
        return;
    }

    int count = 1;
    while (count < position) {
        previous = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    previous->next = temp->next;
    delete temp;
}

int LengthOfLL(Node* head) {
    int size = 0;
    Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

void searchEleInLL(Node* head, int ele) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == ele) {
            cout << "Element present in Linked List" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not present in Linked List" << endl;
}

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

Node* reverseLL(Node* &head){
    Node* current = head;
    Node* prev = NULL;

    Node* forward;

    while(current != NULL){
        forward = current -> next;
        current -> next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

Node* middleEle(Node* &head){
    if (head == NULL || head->next == NULL) {
        return head; // For empty list or single node
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // `slow` now points to the middle node
}


bool hasCycle(Node* &head){
    Node* fast = head -> next;
    Node* slow = head;

    if(head == NULL || head -> next == NULL){
        return false;
    }

    else if(head -> next -> next == NULL){
        return false;
    }

    else{
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
}

Node* HasCycle(Node* &head){
    Node* fast = head -> next;
    Node* slow = head;

    if(head == NULL || head -> next == NULL){
        return NULL;
    }

    else if(head -> next -> next == NULL){
        return NULL;
    }

    else{
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;

            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
}


Node* startingPoint(Node* &head){
    Node* intersection = HasCycle(head);
    Node* slow = head;

    if(intersection == NULL){
        return NULL;
    }

    while(slow !=  intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;

}

bool isPalindrome(Node* &head){
    if (head == NULL || head->next == NULL) {
        return true;  
    }

    Node* middle = middleEle(head);

    Node* temp = middle->next;
    middle->next = reverseLL(temp);  

    Node* node1 = head;
    Node* node2 = middle->next;

    while (node2 != NULL) {
        if (node1->data != node2->data) {
            temp = middle->next;
            middle->next = reverseLL(temp);
            return false;  
        }
        node1 = node1->next;
        node2 = node2->next;
    }

    temp = middle->next;
    middle->next = reverseLL(temp);

    return true;  
}

void bubbleSort(Node* &head){
    if(head == NULL || head -> next == NULL){
        return ;
    }
    bool swapped;
    Node* current;
    Node* lastSorted = NULL;

     do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } 
    while (swapped);
}

void subtractPolynomial(Node* &head1, Node* &head2) {
    Node* poly1 = head1;
    Node* poly2 = head2;
    Node* result = NULL; 
    Node* tail = NULL; 

    while (poly1 != NULL && poly2 != NULL) {
        int diff = poly1->data - poly2->data;
        Node* newNode = new Node(diff);

        if (result == NULL) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }

        poly1 = poly1->next;
        poly2 = poly2->next;
    }

    while (poly1 != NULL) {
        Node* newNode = new Node(poly1->data);
        tail->next = newNode;
        tail = tail->next;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        Node* newNode = new Node(-poly2->data);
        tail->next = newNode;
        tail = tail->next;
        poly2 = poly2->next;
    }

    cout << "Difference of the polynomials: ";
    printLL(result);
}

void addPolynomial(Node* &head1, Node* &head2) {
    Node* poly1 = head1;
    Node* poly2 = head2;
    Node* result = NULL; 
    Node* tail = NULL; 

    while (poly1 != NULL && poly2 != NULL) {
        int sum = poly1->data + poly2->data;
        Node* newNode = new Node(sum);

        if (result == NULL) {
            result = newNode;
            tail = result;
        } 
        else {
            tail->next = newNode;
            tail = tail->next;
        }

        poly1 = poly1->next;
        poly2 = poly2->next;
    }

    // If poly1 has more terms
    while (poly1 != NULL) {
        Node* newNode = new Node(poly1->data);
        tail->next = newNode;
        tail = tail->next;
        poly1 = poly1->next;
    }

    // If poly2 has more terms
    while (poly2 != NULL) {
        Node* newNode = new Node(poly2->data);
        tail->next = newNode;
        tail = tail->next;
        poly2 = poly2->next;
    }

    cout << "Sum of the polynomials: ";
    printLL(result);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    while (true) {
        cout << "\n (1) Insert at Head in Linked List" << endl;
        cout << " (2) Insert at Tail in Linked List" << endl;
        cout << " (3) Insert at a position in Linked List" << endl;
        cout << " (4) Delete a node from a Linked List" << endl;
        cout << " (5) Length of Linked List" << endl;
        cout << " (6) Search an Element in a Linked List" << endl;
        cout << " (7) Print Linked List" << endl;
        cout << " (8) Reverse a Linked List" << endl;
        cout << " (9) Middle element in Linked List" << endl;
        cout << " (10) Detect Cycle in Linked List" << endl;
        cout << " (11) To find starting point in Linked List" << endl;
        cout << " (12) Bubble sort a Linked List" << endl;
        cout << " (13) Add Polynomials in a Linked List" << endl;
        cout << " (14) Subtract Polynomials in a Linked List" << endl;
        cout << " (15) Exit" << endl;

        int option;
        cout << "Enter which operation to perform (1 to 12): ";
        cin >> option;

        if (option == 15) break;

        if (option == 1 || option == 2 || option == 3) {
            int value;
            cout << "Enter the value of the element: ";
            cin >> value;

            if (option == 1) {
                InsertAtHead(head, value);
                if (size == 0) tail = head; 
                size++;
            } 
            
            else if (option == 2) {
                if (tail == NULL) {
                    InsertAtHead(head, value);
                    tail = head; 
                } 
                else {
                    InsertAtTail(tail, value);
                }
                size++;
            } 
            
            else if (option == 3) {
                int position;
                cout << "Enter the position where you want to insert the node: ";
                cin >> position;

                InsertAtPosition(head, value, position, size);

                if (position == size + 1) tail = tail->next; 
                size++;
            }
        } 
        
        else if (option == 4) {
            int position;
            cout << "Enter position of node to be deleted: ";
            cin >> position;

            deleteNode(head, position);

            // Update tail if the last node was deleted
            if (head == NULL) {
                tail = NULL;
            } 
            
            else if (position == size) {
                Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                tail = temp;
            }
            size--;
        } 
        
        else if (option == 5) {
            cout << "Length of Linked List: " << LengthOfLL(head) << endl;
        } 
        
        else if (option == 6) {
            int Ele;
            cout << "Enter value of an element to search: ";
            cin >> Ele;
            searchEleInLL(head, Ele);
        } 
        
        else if (option == 7) {
            printLL(head);
        } 

        else if(option == 8){
            head = reverseLL(head);
            cout << "Reverse Linked List is:" << endl;
            printLL(head);
        }
        else if(option == 9){
            Node* middleNode = middleEle(head);
            if (middleNode != NULL) {
                cout << "Middle element in Linked List is: " << middleNode->data << endl;
            } 
            else {
                cout << "Linked List is empty" << endl;
            }
        }

        else if(option == 10){
            if(hasCycle(head)){
                cout << "Loop is present in Linked List" << endl;
            }
            else{
                cout << "Loop is not present in Linked List" << endl;
            }
        }

        else if(option == 11){
            Node* startPoint = startingPoint(head);
            if(startPoint != NULL){
                cout << "Starting point is:" << startPoint << endl;
            }
            else{
                cout << "Linked List does not have a starting point" << endl;
            }
        }
        
        else if(option == 12){
            bubbleSort(head);
            cout << "Linked List after bubble sort is:" << endl;
            printLL(head);
        }

        else if (option == 13) {
            Node* poly1 = NULL;
            Node* poly2 = NULL;
            addPolynomial(poly1, poly2);
            cout << "Linked List after adding Polynomials is" << endl;
            printLL(poly1); 
        }    

        else if (option == 14) {
            Node* poly1 = NULL;
            Node* poly2 = NULL;
    
            subtractPolynomial(poly1, poly2);
            cout << "Linked List after subtracting Polynomials is" << endl;
            printLL(poly1); 
        }

        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}