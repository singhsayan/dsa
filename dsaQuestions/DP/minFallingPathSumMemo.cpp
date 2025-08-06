#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minFallingPathSumRecursive(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
    int n = matrix.size();
    
    // Base case: If we've reached the last row, return the value of the current element
    if (row == n - 1) {
        return matrix[row][col];
    }
    
    // Check memoization table to avoid redundant calculations
    if (memo[row][col] != -1) {
        return memo[row][col];
    }
    
    // Calculate the minimum sum for the three possible moves
    int down = minFallingPathSumRecursive(matrix, row + 1, col, memo);
    int leftDiagonal = (col > 0) ? minFallingPathSumRecursive(matrix, row + 1, col - 1, memo) : INT_MAX;
    int rightDiagonal = (col < n - 1) ? minFallingPathSumRecursive(matrix, row + 1, col + 1, memo) : INT_MAX;
    
    // Store the result in memoization table
    memo[row][col] = matrix[row][col] + min({down, leftDiagonal, rightDiagonal});
    
    return memo[row][col];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int minPathSum = INT_MAX;
    
    // Start the recursive search from every element in the first row
    for (int col = 0; col < n; col++) {
        minPathSum = min(minPathSum, minFallingPathSumRecursive(matrix, 0, col, memo));
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