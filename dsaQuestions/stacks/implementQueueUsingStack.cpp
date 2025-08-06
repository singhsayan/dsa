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
        stack<int>s1, s2;

        void push(int x){
            s1.push(x);
        }

        int pop(){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()){
                int topEle = s2.top();
                s2.pop();
                return topEle;
            }
            return -1;
        }

        int peek(){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()){
                int topEle = s2.top();
                return topEle;
            }
            return -1;
        }
        
        bool isEmpty(){
            return s1.empty() && s2.empty();
        }
};