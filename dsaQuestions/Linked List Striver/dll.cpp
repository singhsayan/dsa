#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtHead(Node* &head, Node* &tail,int data){
        if(head == NULL ){
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

    void insertAtPosition(Node* &head, Node* &tail, int position, int data){
        int count = 0;
        Node* temp = new Node(data);
        Node* curr = head;

        while(count < position){
            curr = curr -> next;
            count++;
        }
        temp -> next = curr -> next;
        curr -> next -> prev = temp;
        curr -> next = temp;
        temp -> prev = curr;

    }
    
    void insertAtEnd(Node* &head, Node* &tail, int position, int data){
        
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    DoublyLinkedList d1;

    d1.append(1);
    d1.append(2);
    d1.append(3);
    d1.append(4);

    cout << "Doubly Linked List: ";
    d1.print();

    return 0;
}