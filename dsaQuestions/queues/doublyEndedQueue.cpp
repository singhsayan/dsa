#include<iostream>
#include<queue>
using namespace std;

class Dequeue{
    public:
        int* arr;
        int front;
        int rear;
        int size;
    
    Dequeue(int size){
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool pushFront(int ele){
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return false;
        }
        else if(front == -1 ){
            front = rear = 0;
        }
        else if(front == 0 && rear != size - 1){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = ele;
        return true;
    }

    bool pushRear(int ele){
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return false;
        }
        else if(front == -1 ){
            front = rear = 0;
        }
        else if(rear = size - 1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = ele;
        return true;
    }

    int popFront(){
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }

        else if(front == size -1){
            front = 0;
        }
        else{
            front++;
        }

        return ans;
    }

    int popRear(){
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }

        else if(rear == 0){
            rear = size - 1;
        }
        else{
            rear--;
        }

        return ans;
    }

    int getFront(){
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            return -1;
        }
        return arr[rear];
    }
};