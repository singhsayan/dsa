#include<iostream>
#include <vector>
#include <cmath>
using namespace std;


int miniEnergy(int n, vector<int> &height, vector<int> &dp){

    dp[0]= 0;

    for(int i = 2; i < n; i++){
        int jump1 = dp[i - 1] + abs(height[i] - height[i - 1]);
        int jump2 = if i > 1 ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;

        dp[i] = min(jump1, jump2);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout << "Enter the number of steps:" << endl;
    cin >> n;

    vector<int> height(n);
    cout << "Enter the height of each step: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    vector<int> dp(n + 1, -1);

    // Call the function to calculate the minimum energy
    cout << "Minimum energy to reach the top: " << miniEnergy(height, n, dp) << endl;

    return 0;
}