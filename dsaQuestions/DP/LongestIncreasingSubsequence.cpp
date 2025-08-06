#include<iostream>
#include<vector>
using namespace std;

int lis(int curr, int prev, vector<vector<int>>&dp, vector<int>&arr){
    int n = arr.size();
    if(curr >= n) return 0;

    if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

    int include = 0;

    if(prev == -1 || arr[curr] > arr[prev]){
        include = 1 + lis(curr + 1, curr, dp, arr);
    }
    int exclude = lis(curr + 1, prev, dp, arr);

    return dp[curr][prev + 1] = max(include, exclude);
}

int lisTab(int curr, int prev, vector<int>&arr){
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int curr = n - 1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= -1; prev--){
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev]){
                include = 1 + dp[curr + 1][curr ];
            }
            int exclude = dp[curr + 1][prev ];

            dp[curr][prev] = max(inlcude, exclude);
        }
    }
    return dp[curr][prev + 1];
}

int main(){
    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << "Longest LIS is:" << endl;
    cout << lis(0, -1, dp, arr) << endl;

    return 0;
}