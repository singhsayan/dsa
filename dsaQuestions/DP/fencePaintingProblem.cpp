#include<iostream>
#include<vector>
using namespace std;

int solve(int n, int k, vector<int>& dp) {
    if (n == 1) return k;
    if (n == 2) return k + k * (k - 1);
    if (dp[n] != -1) return dp[n];

    dp[n] = (solve(n - 1, k, dp) + solve(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

int numWays(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k + k * (k - 1);

    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }

    return dp[n];
}


int main(){
    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    int k;
    cout << "Enter total number of colors:" << endl;
    cin >> k;


    vector<int>dp(n + 1, -1);

    cout << "No of ways of painting fence:" << endl;
    cout << solve(n, k, dp);
}
