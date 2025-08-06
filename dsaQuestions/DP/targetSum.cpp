#include<iostream>
#include<vector>
using namespace std;

int targetSum(int index, vector<vector<int>>&dp, int target, vector<int>&arr, int n){
    if(target == 0) return 1;

    if(index == n) return 0;

    if(dp[index][target] != -1) return dp[index][target];

    int include = targetSum(index + 1, dp, target - arr[index], arr, n);
    int exclude = targetSum(index + 1, dp, target, arr, n);

    dp[index][target] = include + exclude;
    return dp[index][target];
}

int targetSumTab(int target, vector<int>&arr, int n){
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= target; j++){
            int include = 0;
            if(j - arr[i] >= 0){
                include = dp[i + 1][j - arr[i]];
            }
            int exclude = dp[i + 1][j];
            dp[i][j] = include + exclude;
        }
    }
    return dp[0][target];
}


int main(){
    int n;
    cout << "Enter size of array";  
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements present in array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element:" << endl;
    cin >> target;

   // vector<vector<int>> dp(n + 1, vector<int>(target+1, -1));

    cout << "Total number of ways to achieve target sum is:" << endl;
    //cout <<  targetSum(0, dp, target, arr, n) << endl;
    cout << targetSumTab(target, arr, n) << endl;

    return 0;
}