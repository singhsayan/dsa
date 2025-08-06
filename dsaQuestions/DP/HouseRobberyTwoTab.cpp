#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums, int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Case 1: Rob houses from index 0 to n-2 (ignoring the last house)
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        int case1 = dp[n-2];  // Max profit from robbing 0 to n-2
        
        // Case 2: Rob houses from index 1 to n-1 (ignoring the first house)
        dp[1] = nums[1];
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        int case2 = dp[n-1];  // Max profit from robbing 1 to n-1
        
        return max(case1, case2);  // Max profit from both cases
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