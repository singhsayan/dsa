#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcs(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    if(i >= s1.size()) return 0;

    if(j >= s2.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        dp[i][j] =  1 + lcs(i + 1, j + 1, s1, s2, dp);
    }
    else{
        dp[i][j] = max(lcs(i + 1, j, s1, s2, dp), lcs(i, j + 1, s1, s2, dp));
    }
    return dp[i][j];
}

int lcsTab(string&s1, string&s2){
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

int lcsOptimal(string &s1, string &s2){
    vector<int> curr(n + 1, 0), next(n + 1, 0);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s1[i] == s2[j])
                curr[j] = 1 + next[j + 1];
            else
                curr[j] = max(next[j], curr[j + 1]);
        }
        next = curr;
    }
}

string buildLCS(string &s1, string &s2, vector<vector<int>>&dp){
    string str = "";

    int i = 0, j = 0;
    int m = s1.size();
    int n = s2.size();

    while (i < m && j < n){
        if(s1[i] == s2[j]){
            str += s1[i];
            i++;
            j++;
        }
        else if(i+1 < m && (j == n || dp[i+1][j] >= dp[i][j+1])){
            i++;
        }
        else{
            j++;
        }
    }
    return str;
}

int main(){
    string s1;
    string s2;

    cout << "Enter value of string 1:" << endl;
    cin >> s1;

    cout << "Enter value of string 2:" << endl;
    cin >> s2;

    int m = s1.size(); int n = s2.size();
    vector<vector<int>>dp(m, vector<int>(n, -1));

    cout << "Length of Longest common substring is:" << endl;
    cout << lcs(0, 0, s1, s2, dp) << endl;


    cout << "Longest common subsequence is:" << endl;
    cout << buildLCS(s1, s2, dp) << endl;

    return 0;
}