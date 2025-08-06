#include<iostream>
#include<vector>
using namespace std;

int uniquePathsHelper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base case: if we are at the top-left corner and it's not blocked
    if (m == 0 && n == 0) {
        return grid[m][n] == 0 ? 1 : 0; // Only valid if the start is not blocked
    }

    // If out of bounds or there's an obstacle, return 0
    if (m < 0 || n < 0 || grid[m][n] == 1) {
        return 0;
    }

    // Check if the value is already computed
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    // Recur for the top and left cells, ensuring we don't go through obstacles
    dp[m][n] = uniquePathsHelper(m - 1, n, grid, dp) + uniquePathsHelper(m, n - 1, grid, dp);

    return dp[m][n];
}

int uniquePaths(int m, int n, vector<vector<int>>& grid) {
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp with -1
    return uniquePathsHelper(m - 1, n - 1, grid, dp); // Start from the bottom-right corner
}

int main() {
    int m = 3, n = 3;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0}, // Obstacle at (1, 1)
        {0, 0, 0}
    };
    cout << "Unique Paths: " << uniquePaths(m, n, grid) << endl;
    return 0;
}