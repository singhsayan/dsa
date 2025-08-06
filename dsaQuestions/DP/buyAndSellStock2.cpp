#include<iostream>
#include<vector>
using namespace std;

int maxProfit(int index, int buy, vector<int>&prices, int n, vector<vector<int>>&dp){
    if(index == n) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;

    if(buy){
        profit = max((-prices[index] + maxProfit(index + 1, 0, prices, n, dp)), maxProfit(index + 1, 1, prices, n, dp));
    }
    else{
        profit = max((prices[index] + maxProfit(index + 1, 1, prices, n, dp)), maxProfit(index + 1, 0, prices, n, dp));
    }

    return dp[index][buy] = profit;
}

int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int>prices(n);

    cout << "Enter prices of stock:" << endl;
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout << "Maximum profit achievable is:" << endl;
    cout << maxProfit(0, 1, prices, n, dp) << endl;

    return 0;
}