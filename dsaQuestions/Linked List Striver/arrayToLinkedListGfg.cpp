#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;  // Make next public

        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // Function to print the linked list
        void printList(){
            Node* temp = this;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

class Solution{
    public:
        Node* constructLL(vector<int>& arr){
            if(arr.empty()){
                return NULL;
            }
            Node* head = new Node(arr[0]);
            Node* tail = head;

            int count = 1;

            while(count < arr.size()){
                tail->next = new Node(arr[count]);
                tail = tail->next;
                count++;
            }

            return head;
        }
};

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter elements of the array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    Solution solution;
    Node* head = solution.constructLL(arr);

    if(head != NULL){
        // head->printList();  // Print the linked list
        head -> data;
    }

    return 0;
}