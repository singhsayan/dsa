#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int> &nums, int n){
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
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