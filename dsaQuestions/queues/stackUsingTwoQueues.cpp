#include <iostream>
#include <queue>
using namespace std;

class StackWithTwoQueues {
    queue<int> q1, q2;

public:
    // Push an element onto the stack
    void push(int x) {
        q2.push(x); // Push x to q2

        // Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Remove the top element from the stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q1.pop();
    }

    // Get the top element of the stack
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackWithTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    return 0;
}