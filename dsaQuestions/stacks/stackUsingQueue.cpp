#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class queue{
    public:
        int front;
        int rear;
        int size;
        int *arr;

    queue(int size){
            this -> size = size;
            arr = new int[size];
            front = size;
            rear = size - 1;
        }

        void push(int x){
            if(front > 0){
                front--;
                arr[front] = x;
            }
        }
        int pop(){
            if(front == size){
                return -1;
            }
            else{
                int ele = arr[front];
                front++;
                if(front == size){
                    rear = size - 1;
                }
                return ele;
            }
        }
        int top(){
            if(front == size){
                return -1;
            }
            else{
                return arr[front];
            }
            
        }
        bool isEmpty(){
            if(front == size){
                return true;
            }
            else{
                return false;
            }
        }
};