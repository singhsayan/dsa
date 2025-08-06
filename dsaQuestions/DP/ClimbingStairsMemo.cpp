#include<iostream>
#include<vector>
using namespace std;

int solveMem(int n, vector<int>&dp){
    if(n == 0 || n == 1) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = solveMem(n - 1) + solveMem(n - 2);

    return dp[n];
}

int main(){
    int n;
    cout << "Enter value of n:" << endl;
    cin >> n;

    vector<int> dp(n + 1, 0);

    return solveMem(n, dp);
    return 0;
}