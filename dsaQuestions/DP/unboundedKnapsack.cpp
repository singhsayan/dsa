#include<iostream>
#include<vector>
using namespace std;

int knapsack(int index, int capacity, vector<int>&weights, vector<int>&profits, vector<vector<int>>&dp){
    if(index >= weights.size()) return 0;

    if(dp[index][capacity] != -1) return dp[index][capacity];

    int include = 0;
    if(capacity >= weights[index]){
        include = profits[index] + knapsack(index + 1, capacity - weights[index], weights, profits, dp);
    }
    int exclude = knapsack(index + 1, capacity, weights, profits, dp);

    return dp[index][capacity] = max(include, exclude);
}

int knapsackTab(int n, int capacity, vector<int>&weights, vector<int>&profits){
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for(int index = n - 1; index >= 0; index--){
        for(int j = 0 j <= capacity; j++){
            int include = 0;
            if(capacity > weights[index]){
                include = profits[index] + dp[index + 1][capacity - weights[index]];
            }
            else{
                int exclude = dp[index + 1][capacity];
            }
            dp[index][capacity] = max(include, exclude);
        }
    }
    return dp[0][capacity];
}

int main(){
    int n;
    cout << "Enter total number of items present in the bag:" << endl;
    cin >> n;

    vector<int> weights(n);
    vector<int> profits(n);

    cout << "Enter weights of the items:" << endl;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    cout << endl;

    cout << "Enter profits of the items:" << endl;
    for(int i = 0; i < n; i++){
        cin >> profits[i];
    }
    cout << endl;

    int w;
    cout << "Enter capacity of the bag:" << endl;
    cin >> w;

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
 
    cout << "Enter maximum value which can come in knapsack:" << endl;
    cout << knapsack(0, w, weights, profits, dp) << endl;
    return 0;
}