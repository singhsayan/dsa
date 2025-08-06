#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n, vector<vector<int>>& grid) {
    vector<int> dp(n, 0); // Initialize the first row
    dp[0] = grid[0][0] == 1 ? 0 : 1; // If the start is blocked, there are 0 paths

    // Iterate over each row
    for (int i = 0; i < m; i++) {
        // We need to check for the first column separately
        if (grid[i][0] == 1) {
            dp[0] = 0; // If the first column cell is blocked, set it to 0
        }
        // Iterate over each column starting from the second column
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[j] = 0; // Obstacle, no paths through this cell
            } else {
                dp[j] = dp[j] + dp[j - 1]; // Sum of paths from top and left
            }
        }
    }

    return dp[n - 1]; // The last element will contain the result
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