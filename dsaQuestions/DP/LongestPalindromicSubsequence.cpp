#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lps(int start, int end, string&s, vector<vector<int>>&dp){
    if(start > end) return 0;
    if(start == end) return 1;

    if(dp[start][end] != -1) return dp[start][end];

    if(s[start] == s[end]){
        dp[start][end] = 2 + lps(start + 1, end - 1, s, dp);
    }
    else{
        dp[start][end] = max(lps(start + 1, end, s, dp), lps(start, end - 1, s, dp));
    }

    return dp[start][end];
}


int main(){
    string s;
    cout << "Enter string:" << endl;
    cin >> s;

    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));

    cout << "Length of longest palindromic subsequence is:" << endl;
    cout << lps(0, s.length(), s, dp) << endl;

    return 0;
}