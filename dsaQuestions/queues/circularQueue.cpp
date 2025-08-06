#include<iostream>
#include<queue>
using namespace std;

class circularQueue{
    public:
        int* arr;
        int front;
        int rear;
        int size;
    
    circularQueue(int size){
        this -> size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool enqueue(int value){ // 2nd condition is for when front is ahead of rear 
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return false;
        }
        else if(front == -1){ // first element to push
            front = 0;
            rear = 0;
        }
        else if(rear == size -1 && front != 0){ // for maintaining cyclic flow
            rear = 0;
        }
        else{ // for normal flow
            rear++;
        }
        arr[rear] = value; 
        
        return true;
    }

    int dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            // single element is present
            front = -1;
            rear = -1;
        }
        else if(front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};