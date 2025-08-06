#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSquareSide(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxLen = 0;

    // Fill the dp matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = mat[i][j]; // First row/column = same as input
            } else if(mat[i][j] == 1) {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    cout << "Maximum side length of square with all 1s: " << maxSquareSide(mat) << endl;
    return 0;
}
