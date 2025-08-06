#include<iostream>
#include<stack>
using namespace std;

class TwoStack{
    public:
        int top1;
        int top2;
        int size;
        int* arr;

    TwoStack(int size){
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int element){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = element;
        }
    }

    void push2(int element){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = element;
        }
    }

    int pop1(int element){
        if(top1 >= 0){
            int num = arr[top1];
            top1--;
            return num;
        }
        else{
            return -1;
        }
    }

    int pop2(int element){
        if(top2 < size){
            int num = arr[top2];
            top2++;
            return num;
        }
        else{
            return -1;
        }
    }
};