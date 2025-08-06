#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChocolates(int row, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    int n = grid.size(), m = grid[0].size();
    if (row == n) return 0; // If we've reached the last row, no more chocolates can be collected.

    if (dp[row][c1][c2] != -1) return dp[row][c1][c2]; // Return if already computed.

    int maxChoco = 0;
    for (int move1 = -1; move1 <= 1; move1++) { // Possible moves for robot 1 (left, down, right)
        for (int move2 = -1; move2 <= 1; move2++) { // Possible moves for robot 2 (left, down, right)
            int newC1 = c1 + move1, newC2 = c2 + move2;
            if (newC1 >= 0 && newC1 < m && newC2 >= 0 && newC2 < m) { // Check valid moves
                int chocolates = (c1 == c2 ? grid[row][c1] : grid[row][c1] + grid[row][c2]);
                maxChoco = max(maxChoco, maxChocolates(row + 1, newC1, newC2, grid, dp) + chocolates);
            }
        }
    }
    return dp[row][c1][c2] = maxChoco;
}

int collectChocolates(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocolates(0, 0, m-1, grid, dp);
}

int main() {
    vector<vector<int>> grid = {{5, 3, 2, 1}, {1, 4, 7, 2}, {3, 6, 1, 4}, {4, 2, 9, 8}};
    cout << collectChocolates(grid) << endl; // Output the maximum chocolates collected
}