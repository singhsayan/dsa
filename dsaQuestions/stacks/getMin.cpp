#include <iostream>
#include <stack>
#include <utility> // For std::pair

class MinStack {
private:
    std::stack<std::pair<int, int>> st; // Stack to store pairs of (value, minimum value)

public:
    MinStack() {
        // Constructor
    }
    
    void push(int val) {
        int min;
        if (st.empty()) {
            min = val; // If stack is empty, the min is the current value
        } else {
            min = std::min(st.top().second, val); // Compare with the current minimum
        }
        st.push({val, min}); // Push the value and the current minimum
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop(); // Pop the top element
        }
    }
    
    int top() {
        if (!st.empty()) {
            return st.top().first; // Return the value at the top of the stack
        }
        throw std::runtime_error("Stack is empty"); // Handle empty stack
    }
    
    int getMin() {
        if (!st.empty()) {
            return st.top().second; // Return the minimum value
        }
        throw std::runtime_error("Stack is empty"); // Handle empty stack
    }
};

// Example usage
int main() {
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(5);
    std::cout << "Min: " << obj->getMin() << std::endl; // Should print 3
    obj->push(2);
    obj->push(1);
    std::cout << "Min: " << obj->getMin() << std::endl; // Should print 1
    obj->pop();
    std::cout << "Top: " << obj->top() << std::endl; // Should print 2
    std::cout << "Min: " << obj->getMin() << std::endl; // Should print 2
    obj->pop();
    std::cout << "Min: " << obj->getMin() << std::endl; // Should print 3

    delete obj; // Clean up
    return 0;
}