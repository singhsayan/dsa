#include<iostream>
#include<vector>
using namespace std;

int minPathSum(int m, int n, vector<vector<int>>& grid) {
    vector<int> dp(n, 0); // Initialize a 1D dp array

    dp[0] = grid[0][0]; // Initialize the first cell

    // Fill the first row (can only come from left)
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }

    // Fill the rest of the rows
    for (int i = 1; i < m; i++) {
        // Update the first cell of the row
        dp[0] += grid[i][0];

        // Update the rest of the cells in the current row
        for (int j = 1; j < n; j++) {
            dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
        }
    }

    return dp[n - 1]; // Return the minimum path sum to bottom-right corner
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