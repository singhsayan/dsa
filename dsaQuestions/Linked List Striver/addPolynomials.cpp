#include<iostream>
using namespace std;

class Node{
    private:
        
    public:
        int data;
        Node* next = NULL;
    
    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        cout << "Hello" << endl;
    }

    void display(){
        data = 5;

        cout << data << endl;
    }
};

void addPolynomials(Node* &head1, Node* &head2){
    Node* poly1 = head1;
    Node* poly2 = head2;

    Node* result = NULL;
    Node* tail = NULL;

    while(poly1 != NULL & poly2 != NULL){
        int sum = poly1 -> data + poly2 -> data;
        
    }
}




int main(){
    Node n;
    
    //cout<<n->data;
    // n = new Node(5);


    
}