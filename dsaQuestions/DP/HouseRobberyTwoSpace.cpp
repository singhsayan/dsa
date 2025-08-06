#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int rob(vector<int>& nums, int n) {
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = 0, prev1 = 0;
        
        // Case 1: Rob houses from 0 to n-2
        for (int i = 0; i < n - 1; i++) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        
        int case1 = prev1;
        
        // Reset for Case 2: Rob houses from 1 to n-1
        prev2 = 0, prev1 = 0;
        
        for (int i = 1; i < n; i++) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        
        int case2 = prev1;
        
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

    cout << "Maximum amount that can be robbed: " << rob(nums, n) << endl;
    return 0;
}