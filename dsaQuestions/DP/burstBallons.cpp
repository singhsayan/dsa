#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int maxCoins(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxCost = INT_MIN;

    for(int k = i; k <= j; k++){
        int cost = maxCoins(i, k - 1, arr, dp) + maxCoins(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j + 1];
        maxCost = max(maxCost, cost);
    }

    return dp[i][j] = maxCost;
}


int main(){
    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements present in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    cout << "Maximum coins which can be collected:" << endl;
    cout << maxCoins(1, n, arr, dp);

    return 0;
}