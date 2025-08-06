#include<iostream>
#include<vector>
#include<string>
using namespace std;

int minOperations(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
    if(i == s1.length()) return s2.length() - j;
    if(j == s2.length()) return s1.length() - i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        dp[i][j] = minOperations(i + 1, j + 1, s1, s2, dp);
    }
    else{
        dp[i][j] = 1 + min(minOperations(i + 1, j, s1, s2, dp), minOperations(i, j + 1, s1, s2, dp));
    }

    return dp[i][j];
}

int main(){
    string s1;
    cout << "Enter string s1:" << endl;
    cin >> s1;

    string s2;
    cout << "Enter string s2:" << endl;
    cin >> s2;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));

    cout << "Minimum number of operations needed to make both strings same:" << endl;
    cout << minOperations(0, 0, s1, s2, dp);

    return 0;
}