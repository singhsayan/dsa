#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int robHelper(vector<int> &nums, vector<int> &dp, int start, int end) {
    if(start > end) return 0;
    
    if(dp[start] != -1) return dp[start];

    dp[start] = max(robHelper(nums, dp, start + 2, end) + nums[start], robHelper(nums, dp, start + 1, end));
    return dp[start];
}

int rob(vector<int>& nums, int n, vector<int>& dp) {
    if (n == 0) return 0;

    if (n == 1) return nums[0];

    // Case 1: Rob houses from index 0 to n-2
    dp.assign(n, -1); // Reset the dp array
    int case1 = robHelper(nums, dp, 0, n - 2);

    // Case 2: Rob houses from index 1 to n-1
    dp.assign(n, -1); // Reset the dp array
    int case2 = robHelper(nums, dp, 1, n - 1);

    return max(case1, case2);
}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);
    int n = nums.size();
    vector<int> dp(n, -1);  // Initialize dp array

    cout << "Maximum amount that can be robbed: " << rob(nums, n, dp) << endl;
    return 0;
}