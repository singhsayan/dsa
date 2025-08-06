#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> dp(n, 0);  // DP array for storing the minimum path sums

    // Start from the last row
    for (int row = n - 1; row >= 0; row--) {
        vector<int> curr(n, 0);  // Temporary array for the current row

        for (int col = 0; col < n; col++) {
            if (row == n - 1) {
                // If it's the last row, no need to calculate, just copy the value
                curr[col] = matrix[row][col];
            } else {
                // Calculate the minimum sum path for the current cell
                int down = dp[col];
                int leftDiagonal = (col > 0) ? dp[col - 1] : INT_MAX;
                int rightDiagonal = (col < n - 1) ? dp[col + 1] : INT_MAX;

                curr[col] = matrix[row][col] + min({down, leftDiagonal, rightDiagonal});
            }
        }

        dp = curr;  // Update the DP array to be the current row
    }

    // The answer will be the minimum value in the first row
    int minPathSum = INT_MAX;
    for (int col = 0; col < n; col++) {
        minPathSum = min(minPathSum, dp[col]);
    }

    return minPathSum;
}

int main() {
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;
    return 0;
}