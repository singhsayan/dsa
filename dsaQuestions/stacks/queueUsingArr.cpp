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
            front = -1;
            rear = -1;
        }

        void push(int x){
            if(rear < size){
                rear++;
                arr[rear] = x;
            }
            else{
                return;
            }
        }
        int pop(){
            if(front == -1){
                return -1;
            }
            else{
                int ele = arr[front];
                arr[front] = -1'
                front++;
                return ele;
            }
            if(front == -1){
                front = rear = -1;
            }
        }
};