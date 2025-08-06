#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxLen(int i, int j,int m, int n, vector<vector<int>>&mat){
    if(i >= m || j >= n) return 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLen = 0;

    for(int i = 0; i < m; i++){
        dp[i][0] = mat[i][0];
        maxLen = max(maxLen, dp[i][0]);
    }

    for(int j = 0; j < n; j++){
        dp[0][j] = mat[0][j];
        maxLen = max(maxLen, dp[0][j]);
    }

    for(int i= 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(mat[i][j] == 1){
                dp[i][j] = 1 + min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                maxLen = max(maxLen, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}

int main(){
    int n, m;
    cout << "Enter size of matrix (n * m):" << endl;
    cin >> n >> m;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter values present in matrix:" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    cout << endl;

    cout << "Maximum length of side of a square sub matrix is:" << endl;
    cout << maxLen(0, 0, m, n,  mat) << endl;

    cout << endl;
}