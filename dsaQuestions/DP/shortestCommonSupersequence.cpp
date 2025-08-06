#include<iostream>
#include<vector>
#include<string>
using namespace std;

int scs(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
    if(i == s1.length()) return s2.length() - j;
    if(j == s2.length()) return s1.length() - i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        dp[i][j] = scs(i + 1, j + 1, s1, s2, dp);
    }
    else{
        dp[i][j] = min(1 + scs(i + 1, j, s1, s2, dp), 1 + scs(i , j + 1, s1, s2, dp));
    }

    return dp[i][j];
}
z
int main(){
    string s1;
    cout << "Enter string s1:" << endl;
    cin >> s1;

    string s2;
    cout << "Enter string s2:" << endl;
    cin >> s2;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));

    cout << "Length of shortest string that has both subsequences:" << endl;
    cout << scs(0, 0, s1, s2, dp) << endl;

    string result = "";
    int i = 0, j = 0;

    while(i < s1.length() && j < s2.length()){
        if(s1[i] == s2[j]){
            result += s1[i];
            i++;
            j++;
        }
        else if(dp[i+1][j] < dp[i][j+1]){
            result += s1[i];
            i++;
        }
        else{
            result += s2[j];
            j++;
        }
    }

    while(i < s1.length()){
        result += s1[i];
        i++;
    }

    while(j < s2.length()){
        result += s2[j];
        j++;
    }

    cout << "Shortest supersequence is:" << endl;
    cout << result << endl;

    return 0;
}