#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
        Node* prev = NULL;

        Node(){
            data = 0;
            this -> next = NULL;
            this -> prev = NULL;
        }

        Node(int data){
            this -> data = data;
            this -> next = next;
            this -> prev = NULL;
        }
};

void InsertAtHead(Node* &head, Node* &tail,  int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node* &head, Node* &tail,  int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        InsertAtHead(head, tail, data);
    }

    Node* temp = new Node(data);
    int count = 1;

    Node*  current = head;

    while(count < position - 1){
        current = current -> next;
        return;
    }
    temp -> next = current -> next ;
    current -> next -> prev = temp;
    current -> next = temp;
    temp -> prev = current;
}

void deleteNode(Node* &head, Node* &tail, int position, int data){
    if(head == NULL){
        cout << "Linked List is empty" << endl;
    }

    Node* temp = head;

    if(position == 1){
        head = temp -> next;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }

    int count = 1;
    while(count < position){
        temp = temp -> next;
        count++;
    }

    if(temp == NULL){
        cout << "Position out of range" << endl;
        return;
    }

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp;
}

int lengthOfDLL(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}

void printDLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp ->data << endl;
        temp = temp -> next;
    }
    cout << endl;
}

void reverseDLL(Node* &head, Node* &tail) {
    Node* current = head;
    Node* temp = NULL;

    // Traverse the list and swap next and prev for each node
    while (current != NULL) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev; // because we swapped prev and next
    }

    // Update head and tail
    if (temp != NULL) {
        tail = head;
        head = temp->prev;
    }
}
