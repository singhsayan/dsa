#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestCommonSubstring(string& s1, string& s2, string& result) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;
    int endIndex = 0;  // Last index of the substring in s1

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    if(maxLen > 0)
        result = s1.substr(endIndex - maxLen + 1, maxLen);
    else
        result = "";

    return maxLen;
}

int main(){
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;

    cout << "Enter string 2: ";
    cin >> s2;

    string result;
    int length = longestCommonSubstring(s1, s2, result);

    cout << "Length of Longest Common Substring is: " << length << endl;
    cout << "Longest Common Substring is: " << result << endl;

    return 0;
}
