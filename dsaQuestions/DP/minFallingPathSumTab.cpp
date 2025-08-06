#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Start from the second last row and move upwards
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col < n; col++) {
            // Get the possible moves from the current cell
            int down = matrix[row + 1][col];
            int leftDiagonal = (col > 0) ? matrix[row + 1][col - 1] : INT_MAX;
            int rightDiagonal = (col < n - 1) ? matrix[row + 1][col + 1] : INT_MAX;
            
            // Update the current cell with the minimum path sum
            matrix[row][col] += min({down, leftDiagonal, rightDiagonal});
        }
    }

    // The answer will be the minimum value in the first row
    int minPathSum = INT_MAX;
    for (int col = 0; col < n; col++) {
        minPathSum = min(minPathSum, matrix[0][col]);
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