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

void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    reverseStack(s);

    addAtBottom(s, num);

}

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}



int main() {
    stack<int> s;
    int size, element;

    cout << "Enter size of stack: ";
    cin >> size;

    cout << "Enter elements in stack: ";
    for(int i = 0; i < size; i++) {
        cin >> element;
        s.push(element);
    }

    cout << "Original Stack: " << endl;
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: " << endl;
    printStack(s);

    return 0;
}