#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit function
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> stack;

    for (char ch : expression) {
        if (isdigit(ch)) {
            // Convert character to integer and push it onto the stack
            stack.push(ch - '0');
        } else {
            // Pop two top elements for the operator
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            // Perform the operation
            switch (ch) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator encountered: " << ch << endl;
                    return -1;
            }
        }
    }

    // The result will be the only element left in the stack
    return stack.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression (e.g., 231*+9-): ";
    cin >> expression;

    int result = evaluatePostfix(expression);
    cout << "Result of the postfix expression is: " << result << endl;

    return 0;
}