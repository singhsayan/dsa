#include<iostream>
#include<vector>
using namespace std;

int maxProfit(int index, int buy, int transactions_left, vector<int>&prices, int n, vector<vector<vector<int>>>&dp){
    if(index == n || transactions_left == 0) return 0;

    int profit = 0;

    if(dp[index][transactions_left][buy] != -1) return dp[index][transactions_left][buy];

    if(buy){
        profit = max((-prices[index] + maxProfit(index + 1, 0, transactions_left, prices, n, dp)), maxProfit(index + 1, 1, transactions_left, prices, n , dp));
    }    
    else{
        profit = max((prices[index] + maxProfit(index + 1, 1, transactions_left - 1, prices, n , dp)), maxProfit(index + 1, 0, transactions_left, prices, n, dp));
    }

    return dp[index][buy][transactions_left] = profit;
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

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
    cout << "Maximum profit achieveable is:" << endl;
    cout << maxProfit(0, 1, 2, prices,  n, dp);
    return 0;
}