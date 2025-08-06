#include <iostream>
#include <queue>
using namespace std;

class StackWithOneQueue {
    queue<int> q;

public:
    // Push an element onto the stack
    void push(int x) {
        int size = q.size();
        q.push(x); // Insert x at the end

        // Move all previous elements behind the newly added element
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Remove the top element from the stack
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q.pop();
    }

    // Get the top element of the stack
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackWithOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    return 0;
}