#include<iostream>
#include<vector>
using namespace std;

int minPathSum(int m, int n, vector<vector<int>>& grid) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the top-left corner
    dp[0][0] = grid[0][0];

    // Fill the first row (can only come from left)
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column (can only come from top)
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1]; // Return the minimum path sum to bottom-right corner
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