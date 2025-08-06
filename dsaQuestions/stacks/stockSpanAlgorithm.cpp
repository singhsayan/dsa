#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> calculateStockSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n, 0);  // Array to store the stock spans
    stack<int> s;  // Stack to keep track of indices

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack while the stack is not empty
        // and the price at the index at the top of the stack
        // is less than or equal to the current price
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }

        // If stack is empty, all previous prices are less than or equal to the current price
        if (s.empty()) {
            span[i] = i + 1;  // Span is the current index + 1
        } else {
            span[i] = i - s.top();  // Span is the difference between current index and index at the top of the stack
        }

        // Push the current index onto the stack
        s.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {90, 40, 20, 30, 80, 60, 100};
    vector<int> span = calculateStockSpan(prices);

    cout << "Stock Span: ";
    for (int s : span) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}