#include<iostream>
#include<stack>
using namespace std;

void addAtBottom(stack<int>& s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }

    int num = s.top();
    s.pop();

    addAtBottom(s, ele);

    s.push(num);
}

void printStack(stack<int>& s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main(){

    stack<int> s;
    int size, element;
    cout << "Enter size of stack" << endl;
    cin >> size;

    cout << "Enter the elements present in stack" << endl;
    for(int i = 0; i < size; i++){
        cin >> element;
        s.push(element);
    }

    int ele;
    cout << "Enter the element to be added at bottom" << endl;
    cin >> ele;

    addAtBottom(s, ele);

    cout << "New array after adding element to bottom is:" << endl;
    printStack(s);
}