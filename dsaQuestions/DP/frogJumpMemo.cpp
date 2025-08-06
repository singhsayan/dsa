#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int miniEnergy(vector<int> &height, int n,  vector<int> &dp){
    if (n == 0) return 0;  // No energy required at the first step (base case)
    if (n == 1) return abs(height[1] - height[0]); // Energy from stair 0 to stair 1

    // Check if we have already computed the energy for this step
    if (dp[n] != -1) {
        return dp[n];
    }

    // Calculate energy for the two possible jumps
    int jump1 = miniEnergy(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    int jump2 = miniEnergy(height, n - 2, dp) + abs(height[n] - height[n - 2]);

    // Store the minimum energy in dp[n]
    dp[n] = min(jump1, jump2);

    return dp[n];
}

int main(){
    int n;
    cout << "Enter no of steps:" << endl;
    cin >> n;

    vector<int> height(n);
    cout << "Enter the height of each step: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    vector<int> dp(n, -1);

    // Call the function to calculate the minimum energy
    cout << "Minimum energy to reach the top: " << miniEnergy(height, n - 1, dp) << endl;

    return 0;
}