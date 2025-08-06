#include<iostream>
#include<vector>
#include<string>
using namespace std;

int minLPS(int start, int end, string&s, vector<vector<int>>&dp){
    if(start >= end) return 0;

    if(dp[start][end] != -1) return dp[start][end];

    if(s[start] == s[end]){
        dp[start][end] = minLPS(start + 1, end - 1, s, dp);
    }
    else{
        dp[start][end] = 1 + min(minLPS(start + 1, end, s, dp), minLPS(start, end - 1, s, dp));
    }

    return dp[start][end];
}

int main(){
    string s;
    cout << "Enter string:" << endl;
    cin >> s;   

    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));

    cout << "Minimum number of insertions needed to make string palindrome:" << endl;
    cout << minLPS(0, s.length() - 1, s, dp) << endl;

    return 0;
}