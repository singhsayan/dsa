#include<iostream>
#include<stack>
using namespace std;


class Stack{
    public:
        int size;
        int* arr;
        int top;
    
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }

    void pop(){
        if(top >=0){
            top--;
        }
        else{
            cout << "Stack underflow" << endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            cout << "Stack is Empty" << endl;
        }
        else{
            cout << "Stack is not Empty" << endl;
        }
    }
};

int main(){
    int size, choice = 0, element;

    cout << "Enter size of stack" << endl;
    cin >> size;

    Stack s(size);

    while(choice != 5){
        cout << "\nEnter which operation to perform\n" << endl;
        cout << "1 push" << endl;
        cout << "2 pop" << endl;
        cout << "3 peek" << endl;
        cout << "4 check if empty" << endl;
        cout << "5 exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter element to push" << endl;
                cin >> element;
                s.push(element);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element is:" << s.peek() << endl;
                break;
            case 4:
                if(s.isEmpty()){
                    cout << "Stack is empty" << endl;
                }
                else{
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 5:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice" << endl;
        }
    }
    return 0;
}