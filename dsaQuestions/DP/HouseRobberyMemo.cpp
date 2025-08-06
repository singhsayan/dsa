#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int> &nums,vector<int>& dp, int n){

    if(n < 0) return 0;

    // n == 0 means if there is one element or house so it's index is 0
    if(n == 0) return nums[0];

    if(dp[n] != -1) return dp[n];

    int incl = rob(nums, dp, n - 2) + nums[n];
    int excl = rob(nums, dp, n - 1) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
    
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