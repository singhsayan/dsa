#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s; // Stack to keep track of indices

    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are not smaller than arr[i]
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the top element is the next smaller element
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextSmallerElement(arr);

    cout << "Next smaller elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << result[i] << endl;
    }

    return 0;
}