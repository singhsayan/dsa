#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // Step 1: Push the first k elements of the queue into a stack.
    stack<int> s;
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    // Step 2: Push the stack elements back into the queue (reversing the first k elements).
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // Step 3: Move the remaining (n-k) elements to the back of the queue.
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t-- > 0) {
        int n, k;
        cout << "Enter the size of the queue: ";
        cin >> n;
        cout << "Enter the number of elements to reverse (k): ";
        cin >> k;

        queue<int> q;
        cout << "Enter the elements of the queue: ";
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }

        queue<int> ans = modifyQueue(q, k);

        cout << "Modified queue: ";
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
    
    return 0;
}