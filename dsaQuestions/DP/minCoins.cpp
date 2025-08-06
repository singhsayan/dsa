#include<iostream>
#include<vector>
using namespace std;

int minCoins(int index, int amount, vector<vector<int>>&dp, vector<int>&coins){
    if(amount == 0) return 0;

    if(index == coins.size()) return 1e9;

    if(dp[index][amount] != -1) return dp[index][amount];

    int include = 1e9;
    if(amount - coins[index] >= 0){
        include = 1 + minCoins(index, amount - coins[index], dp, coins);
    }

    int exclude = minCoins(index + 1, amount, dp, coins);

    return dp[index][amount] = min(include, exclude);
}
int minCoins1(int amount, vector<int>&coins, int n){
    vector<vector<int>>dp(n, vector<int>(amount + 1, 1e9));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int total = 1; total <= amount; total++) {
        if (total % coins[0] == 0) {
            dp[0][total] = total / coins[0];
        }
    }

    for(int i = 0; i < n; i++){
        for(int total = 0; total <= amount; total++){
            int include = 1e9;
            if(coins[i] <= total){
                include = 1 + dp[i][total - coins[i]];
            }
            int exclude = dp[i + 1][total];
            dp[i][total] = min(include, exclude);
        }
    }
    int ans =  dp[n - 1][amount];
    return (ans >= 1e9) ? -1 : ans;
}
int main(){
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vector<int> coins(n);

    cout << "Enter which of coins we have:" << endl;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int amount;
    cout << "Enter total amount of money:" << endl;
    cin >> amount;

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    int result = minCoins(0, amount, dp, coins);
    cout << "Minimum coins required to achieve the given amount is:" << endl;
    if(result  >= 1e9) cout << "No solution exists" << endl;
    else cout << result << endl;

    cout << "Min coins needed are:" << endl;
    cout << minCoins1(amount, coins, n);

    return 0;
}