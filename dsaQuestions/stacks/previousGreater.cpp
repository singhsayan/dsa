#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousGreaterElement(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> s;

    for (int i = 0; i < arr.size(); i++) {
        // Pop elements from the stack that are smaller than or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        // If stack is not empty, top of stack is the previous greater element
        if (!s.empty()) {
            result[i] = s.top();
        }
        // Push current element onto stack
        s.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 10, 5, 8, 20, 15, 3, 12};
    vector<int> result = previousGreaterElement(arr);

    cout << "Previous Greater Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}