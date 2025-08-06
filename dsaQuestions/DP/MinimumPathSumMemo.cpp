#include<iostream>
#include<vector>
using namespace std;

int minPathSumHelper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base case: If we are at the top-left corner, return the grid value
    if (m == 0 && n == 0) {
        return grid[0][0];
    }
    
    // If out of bounds, return a large number (effectively infinity)
    if (m < 0 || n < 0) {
        return INT_MAX;
    }

    // If already calculated, return the memoized result
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    // Calculate the minimum path sum by either going down or right
    int down = minPathSumHelper(m - 1, n, grid, dp);
    int right = minPathSumHelper(m, n - 1, grid, dp);

    // Memoize the result (store it in dp[m][n])
    dp[m][n] = grid[m][n] + min(down, right);

    return dp[m][n];
}

int minPathSum(int m, int n, vector<vector<int>>& grid) {
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp table with -1
    return minPathSumHelper(m - 1, n - 1, grid, dp); // Start from the bottom-right corner
}

int main() {
    int m = 3, n = 3;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum Path Sum: " << minPathSum(m, n, grid) << endl;
    return 0;
}