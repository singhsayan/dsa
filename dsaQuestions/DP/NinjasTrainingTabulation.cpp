#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumPoints(vector<vector<int> > &arr, int n, vector<vector<int> > &dp){
    // Initialize dp for the first day
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    // fill the dp table for subsequent days
    for(int day = 1; day < n; day++){
        dp[day][0] = arr[day][0] + max(dp[day - 1][1], dp[day - 1][2]);
        dp[day][1] = arr[day][1] + max(dp[day - 1][0], dp[day - 1][2]);
        dp[day][2] = arr[day][2] + max(dp[day - 1][0], dp[day - 1][1]);
    }

    // Return the maximum points on the last day
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
    vector<vector<int>> arr = {{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Call the tabulation function
    cout << "Maximum Merit Points: " << maximumPoints(arr, n, dp) << endl;
    return 0;
}