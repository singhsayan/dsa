#include<iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) {
        return 1;  // Base cases
    }
    
    int prev2 = 1;  // dp[0], ways to reach step 0
    int prev1 = 1;  // dp[1], ways to reach step 1
    int current = 0; // Variable to store the current step's number of ways
    
    // Loop to calculate the number of ways to reach each step
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;  // Current step = previous step + step before that
        prev2 = prev1;  // Update prev2 to prev1 (shift the window)
        prev1 = current;  // Update prev1 to current (shift the window)
    }
    
    return current;  // The result will be stored in 'current'
}

int main() {
    int n;
    cout << "No of steps taken to reach the top: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid" << endl;
    }
    else {
        cout << "No of distinct ways to reach top are: " << climbStairs(n) << endl;
    }

    return 0;
}