#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int> &nums,vector<int> &dp, int n){
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int incl = (i >= 2 ? dp[i - 2] : 0) + nums[i]; 
        int excl = dp[i - 1] + 0;

        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);
    int n = nums.size();
    vector<int> dp(n, -1);  // Initialize memoization array

    cout << "Maximum amount that can be robbed: " << rob(nums, dp, n - 1) << endl;
    return 0;
}