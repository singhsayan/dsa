#include <iostream>
#include <stack>
using namespace std;

void sortedInsertStack(stack<int>& s, int ele) {
    if (s.empty() || (s.top() < ele)) {
        s.push(ele);
        return;
    }

    int num = s.top();
    s.pop();

    sortedInsertStack(s, ele);
    s.push(num);
}

void sortStack(stack<int>& s) {  
    if (s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s); 
    sortedInsertStack(s, num); 
}

void printStack(stack<int> s) { 
    while (!s.empty()) {
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
    for (int i = 0; i < size; i++) {
        cin >> element;
        s.push(element);
    }

    cout << "Original Stack: " << endl;
    printStack(s);  

    sortStack(s);  

    cout << "Sorted Stack: " << endl; 
    printStack(s);  

    return 0;
}