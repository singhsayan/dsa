#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n, vector<vector<int>>& grid) {
    vector<vector<int>> dp(m, vector<int>(n, 0)); // DP table initialization

    // Base case: The first row and first column can only be reached in one way if not blocked
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 1) break; // Blocked cell in the first column
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == 1) break; // Blocked cell in the first row
        dp[0][j] = 1;
    }

    // Fill the rest of the table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; // Obstacle, no paths through this cell
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Sum of paths from top and left
            }
        }
    }

    return dp[m - 1][n - 1]; // Bottom-right corner will have the result
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