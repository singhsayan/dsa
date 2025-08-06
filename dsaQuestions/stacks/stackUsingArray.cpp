#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Stack{
    public:
        int top;
        int size;
        int *arr;

        stack(int size){
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int x){
            int size = arr.size() - 1;
            if(size - top >= 1){
                top++;
                arr[top] = x;
            }
        }

        int pop(){
            if(top >= 0{
                int ele = arr[top];
                top--;
                return ele;
            })
            else{
                return -1;
            }
        }
};