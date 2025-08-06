#include <iostream>
#include <vector>
using namespace std;

int uniquePathsHelper(int m, int n, vector<vector<int>> &dp) {
    // Base Case: If the robot reaches the top-left cell, there's only 1 way
    if (m == 0 && n == 0) return 1;

    // If out of bounds, return 0
    if (m < 0 || n < 0) return 0;

    // Check if the result is already computed
    if (dp[m][n] != -1) return dp[m][n];

    // Move left and up recursively
    dp[m][n] = uniquePathsHelper(m - 1, n, dp) + uniquePathsHelper(m, n - 1, dp);

    return dp[m][n];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsHelper(m - 1, n - 1, dp);
}

int main() {
    int m = 3, n = 7;
    cout << "Unique Paths: " << uniquePaths(m, n) << endl;
    return 0;
}