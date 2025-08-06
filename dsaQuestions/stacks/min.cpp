#include <iostream>
#include <stack>
#include <utility> // For pair

using namespace std;

class Stack {
    public:
        stack<pair<int, int>> s; // Auxiliary stack to store (value, current_min)

        // Push operation
        void push(int x) {
            int current_min = (s.empty()) ? x : min(s.top().second, x);
            s.push({x, current_min});
        }

        // Pop operation
        int pop() {
            if (!s.empty()) {
                int ele = s.top().first;
                s.pop();
                return ele;
            } else {
                return -1; // Indicate stack underflow
            }
        }

        // Peek operation (top of stack)
        int peek() {
            if (!s.empty()) {
                return s.top().first;
            } else {
                return -1; // Indicate empty stack
            }
        }

        // Get the minimum element
        int getMin() {
            if (!s.empty()) {
                return s.top().second;
            } else {
                return -1; // Indicate empty stack
            }
        }

        // Check if the stack is empty
        bool isEmpty() {
            return s.empty();
        }
};

int main() {
    Stack stack;
    int choice, value;

    cout << "Stack Operations:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek (Top Element)\n";
    cout << "4. Get Minimum Element\n";
    cout << "5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                cout << value << " pushed into the stack.\n";
                break;

            case 2:
                value = stack.pop();
                if (value == -1) {
                    cout << "Stack underflow! Cannot pop from an empty stack.\n";
                } else {
                    cout << value << " popped from the stack.\n";
                }
                break;

            case 3:
                value = stack.peek();
                if (value == -1) {
                    cout << "The stack is empty. No top element.\n";
                } else {
                    cout << "Top element is: " << value << "\n";
                }
                break;

            case 4:
                value = stack.getMin();
                if (value == -1) {
                    cout << "The stack is empty. No minimum element.\n";
                } else {
                    cout << "Minimum element is: " << value << "\n";
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}