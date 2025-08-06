#include<iostream>
#include<queue>
using namespace std;

class Queue{
    public:
        int* arr;
        int front;
        int rear;
        int size;
    
    Queue(int size){
        this -> size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int ele){
        if(rear == size){
            cout << "Queue is full" << endl;
        }
        else{
            arr[rear] = ele;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int getFront(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }


    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } 
        else {
            cout << "Queue elements: ";
            for(int i = front; i < rear; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);
    int choice, element;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Queue is Empty" << endl;
        cout << "4. Get Front Element" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> element;
                q.enqueue(element);
                break;
            case 2:
                element = q.dequeue();
                if(element != -1) {
                    cout << "Dequeued element: " << element << endl;
                }
                break;
            case 3:
                if(q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } 
                else {
                    cout << "Queue is not empty" << endl;
                }
                break;
            case 4:
                element = q.getFront();
                if(element != -1) {
                    cout << "Front element: " << element << endl;
                }
                break;
            case 5:
                q.displayQueue();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 6);

    return 0;
}